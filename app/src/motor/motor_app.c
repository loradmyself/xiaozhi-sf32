#include "rtthread.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "motor_app.h"
#include "motor_control.h"
#include "pid.h"

static int speed_max = 0;
static int l_pulse = 0;
static int r_pulse = 0;
static int non_stop_mode = 0;
static pid_controller_t pid_speed_l;
static pid_controller_t pid_speed_r;
static pid_controller_t pid_pos_l;
static pid_controller_t pid_pos_r;
static struct rt_thread *motor_thread = RT_NULL;
static volatile int motor_running = 0;

static void motor_thread_entry(void *parameter)
{
    int l_out, r_out;
    int l_expect_speed, r_expect_speed;
    int enc_l, enc_r;
    int cnt = 0;
    int64_t wake_time = rt_tick_get();

    rt_kprintf("[MOTOR] Control thread started (50Hz)\n");

    while (motor_running)
    {
        enc_l = encoder_read_left();
        enc_r = encoder_read_right();

        if (non_stop_mode)
        {
            l_expect_speed = speed_max;
            r_expect_speed = speed_max;
        }
        else
        {
            l_pulse -= enc_l;
            r_pulse -= enc_r;
            l_expect_speed = -pid_controller_cal(&pid_pos_l, 0, l_pulse);
            if (l_expect_speed > speed_max)  l_expect_speed = speed_max;
            if (l_expect_speed < -speed_max) l_expect_speed = -speed_max;
            r_expect_speed = -pid_controller_cal(&pid_pos_r, 0, r_pulse);
            if (r_expect_speed > speed_max)  r_expect_speed = speed_max;
            if (r_expect_speed < -speed_max) r_expect_speed = -speed_max;
        }

        l_out = pid_controller_cal_sat(&pid_speed_l, l_expect_speed, enc_l);
        r_out = pid_controller_cal_sat(&pid_speed_r, r_expect_speed, enc_r);
        motor_set(l_out, r_out);

        cnt++;
        if (cnt >= 50)
        {
            rt_kprintf("[MOTOR] L: %.1f rpm, R: %.1f rpm\n",
                       pulse_to_rpm(enc_l), pulse_to_rpm(enc_r));
            cnt = 0;
        }

        wake_time += 20;
        rt_thread_mdelay(wake_time - rt_tick_get());
    }

    motor_stop();
    rt_kprintf("[MOTOR] Thread exited\n");
}

void motor_app_start(void)
{
    if (!motor_is_ready())
    {
        rt_kprintf("[MOTOR] HW not initialized, skip\n");
        return;
    }
    if (motor_running)
    {
        rt_kprintf("[MOTOR] Already running\n");
        return;
    }

    pid_controller_init(&pid_speed_l, 100, 20, 0, MAX_DUTY, MIN_DUTY);
    pid_controller_init(&pid_speed_r, 100, 20, 0, MAX_DUTY, MIN_DUTY);
    pid_controller_init(&pid_pos_l, 1, 0, 0, MAX_DUTY, MIN_DUTY);
    pid_controller_init(&pid_pos_r, 1, 0, 0, MAX_DUTY, MIN_DUTY);

    speed_max = rpm_to_pulse(CONFIG_MOTOR_MAX_RPM);

    motor_running = 1;
    motor_thread = rt_thread_create("motor", motor_thread_entry,
                                    RT_NULL, 2048, 10, 10);
    if (motor_thread)
        rt_thread_startup(motor_thread);
    else
        rt_kprintf("[MOTOR] Create thread failed\n");
}

void motor_app_stop(void)
{
    motor_running = 0;
    motor_stop();
}

static void motor(int argc, char **argv)
{
    int dir, spd, num;

    if (argc != 4)
    {
        rt_kprintf("Usage: motor [dir] [spd] [num]\n");
        rt_kprintf("  dir: 0-forward, 1-reverse\n");
        rt_kprintf("  spd: speed in rpm\n");
        rt_kprintf("  num: rotation count (0=continuous)\n");
        return;
    }

    dir = atoi(argv[1]);
    spd = atoi(argv[2]);
    num = atoi(argv[3]);

    if (dir != 0 && dir != 1)
    {
        rt_kprintf("Error: dir must be 0 or 1\n");
        return;
    }
    if (spd < 0)
    {
        rt_kprintf("Error: speed cannot be negative\n");
        return;
    }
    if (num < 0)
    {
        rt_kprintf("Error: rotation count cannot be negative\n");
        return;
    }

    l_pulse = dir == 0 ? num * PPR : -num * PPR;
    r_pulse = dir == 0 ? num * PPR : -num * PPR;
    non_stop_mode = (num == 0) ? 1 : 0;
    speed_max = rpm_to_pulse(spd);

    rt_kprintf("Motor: dir=%s spd=%d rpm num=%d\n",
               dir == 0 ? "FWD" : "REV", spd, num);
}
MSH_CMD_EXPORT(motor, motor control : motor[dir][spd][num]);
