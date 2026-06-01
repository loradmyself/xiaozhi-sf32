#include "rtthread.h"
#include "rthw.h"
#include "bf0_hal.h"
#include "drv_io.h"
#include "board.h"
#include "motor_control.h"
#include <drivers/rt_drv_encoder.h>

/* Pin definitions for TB6612 motor driver */
#define PWMA_PIN  29
#define PWMB_PIN  20
#define AIN1_PIN  35
#define AIN2_PIN  36
//#define STBY_PIN  43
#define BIN1_PIN  27
#define BIN2_PIN  28
#define ENC1A_PIN 25   /* GPTIM1_CH1 - left encoder A */
#define ENC1B_PIN 24   /* GPTIM1_CH2 - left encoder B */

static struct rt_device_pwm *pwma1_device = RT_NULL;
static rt_device_t gptim1_device = RT_NULL;
static rt_device_t pin_device = RT_NULL;
static int motor_initialized = 0;

static void rt_pin_set(int pin, int value)
{
    struct rt_device_pin_status st;
    st.pin = pin;
    st.status = value ? 1 : 0;
    rt_device_write(pin_device, 0, &st, sizeof(struct rt_device_pin_status));
}

static void pin_mode_set(int pin, int mode)
{
    struct rt_device_pin_mode m;
    m.pin = pin;
    m.mode = mode;
    rt_device_control(pin_device, 0, &m);
}

int motor_hw_init(void)
{
    struct rt_encoder_configuration enc_cfg;

    /* Init PWM pins (ATIM1 CH1/CH2) */
    HAL_PIN_Set(PAD_PA00 + PWMA_PIN, ATIM1_CH1, PIN_NOPULL, 1);
    HAL_PIN_Set(PAD_PA00 + PWMB_PIN, ATIM1_CH2, PIN_NOPULL, 1);
    pwma1_device = (struct rt_device_pwm *)rt_device_find("pwma1");
    if (pwma1_device == RT_NULL)
    {
        rt_kprintf("[MOTOR] PWM device not found\n");
        return -1;
    }
    rt_device_open((struct rt_device *)pwma1_device, RT_DEVICE_OFLAG_RDWR);
    rt_pwm_set(pwma1_device, 1, PWM_PERIOD, 0);
    rt_pwm_set(pwma1_device, 2, PWM_PERIOD, 0);
    rt_pwm_enable(pwma1_device, 1);
    rt_pwm_enable(pwma1_device, 2);

    /* Init encoder pins - left motor only (GPTIM1) */
    HAL_PIN_Set(PAD_PA00 + ENC1A_PIN, GPTIM1_CH1, PIN_PULLUP, 1);
    HAL_PIN_Set(PAD_PA00 + ENC1B_PIN, GPTIM1_CH2, PIN_PULLUP, 1);
    gptim1_device = rt_device_find("encoder1");
    if (gptim1_device == RT_NULL)
    {
        rt_kprintf("[MOTOR] Encoder device not found\n");
        return -1;
    }
    enc_cfg.channel = GPT_CHANNEL_ALL;
    rt_device_control(gptim1_device, PULSE_ENCODER_CMD_ENABLE, &enc_cfg);

    /* Init direction/enable pins */
    HAL_PIN_Set(PAD_PA00 + AIN1_PIN, GPIO_A0 + AIN1_PIN, PIN_PULLUP, 1);
    HAL_PIN_Set(PAD_PA00 + AIN2_PIN, GPIO_A0 + AIN2_PIN, PIN_PULLUP, 1);
    //HAL_PIN_Set(PAD_PA00 + STBY_PIN, GPIO_A0 + STBY_PIN, PIN_PULLUP, 1);
    HAL_PIN_Set(PAD_PA00 + BIN1_PIN, GPIO_A0 + BIN1_PIN, PIN_PULLUP, 1);
    HAL_PIN_Set(PAD_PA00 + BIN2_PIN, GPIO_A0 + BIN2_PIN, PIN_PULLUP, 1);
    pin_device = rt_device_find("pin");
    if (pin_device == RT_NULL)
    {
        rt_kprintf("[MOTOR] GPIO pin device not found\n");
        return -1;
    }
    rt_device_open(pin_device, RT_DEVICE_OFLAG_RDWR);
    pin_mode_set(AIN1_PIN, PIN_MODE_OUTPUT);
    pin_mode_set(AIN2_PIN, PIN_MODE_OUTPUT);
    //pin_mode_set(STBY_PIN, PIN_MODE_OUTPUT);
    pin_mode_set(BIN1_PIN, PIN_MODE_OUTPUT);
    pin_mode_set(BIN2_PIN, PIN_MODE_OUTPUT);

    /* Enable driver (STBY high) */
    //rt_pin_set(STBY_PIN, 1);

    motor_initialized = 1;
    rt_kprintf("[MOTOR] HW initialized\n");
    return 0;
}

int motor_is_ready(void)
{
    return motor_initialized;
}

void motor_set(int left_duty, int right_duty)
{
    uint32_t left_time, right_time;

    if (!motor_initialized)
        return;

    /* Clamp */
    if (left_duty > MAX_DUTY) left_duty = MAX_DUTY;
    if (left_duty < MIN_DUTY) left_duty = MIN_DUTY;
    if (right_duty > MAX_DUTY) right_duty = MAX_DUTY;
    if (right_duty < MIN_DUTY) right_duty = MIN_DUTY;

    /* Left motor direction */
    if (left_duty >= 0)
    {
        rt_pin_set(AIN2_PIN, 0);
        rt_pin_set(AIN1_PIN, 1);
    }
    else
    {
        rt_pin_set(AIN1_PIN, 0);
        rt_pin_set(AIN2_PIN, 1);
    }

    /* Right motor direction */
    if (right_duty >= 0)
    {
        rt_pin_set(BIN2_PIN, 0);
        rt_pin_set(BIN1_PIN, 1);
    }
    else
    {
        rt_pin_set(BIN1_PIN, 0);
        rt_pin_set(BIN2_PIN, 1);
    }

    /* Convert duty to PWM time (absolute value) */
    left_time = PWM_PERIOD * (left_duty < 0 ? -left_duty : left_duty) / 10000;
    right_time = PWM_PERIOD * (right_duty < 0 ? -right_duty : right_duty) / 10000;

    rt_pwm_set(pwma1_device, 1, PWM_PERIOD, left_time);
    rt_pwm_set(pwma1_device, 2, PWM_PERIOD, right_time);
}

void motor_stop(void)
{
    motor_set(0, 0);
}

static int32_t encoder_read_and_clear(rt_device_t dev)
{
    struct rt_encoder_configuration enc;
    if (dev == RT_NULL)
        return 0;
    rt_device_control(dev, PULSE_ENCODER_CMD_GET_COUNT, &enc);
    int32_t res = enc.get_count;
    enc.set_count = 0;
    rt_device_control(dev, PULSE_ENCODER_CMD_SET_COUNT, &enc);
    return res;
}

int32_t encoder_read_left(void)
{
    return encoder_read_and_clear(gptim1_device);
}

int32_t encoder_read_right(void)
{
    return 0;
}

float pulse_to_rpm(int32_t pulse)
{
    return (float)pulse * 50.0f / PPR * 60.0f;
}

int rpm_to_pulse(float rpm)
{
    return (int)(rpm / 60.0f * PPR / 50.0f);
}
