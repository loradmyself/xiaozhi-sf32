#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "rtthread.h"
#include "rthw.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Hardware constants */
#define PWM_PERIOD  (50000)
#define MAX_DUTY    (10000)
#define MIN_DUTY    (-10000)

/* Motor parameters from Kconfig */
#ifndef CONFIG_MOTOR_TOTAL_PPR
    #define CONFIG_MOTOR_TOTAL_PPR  1061
#endif
#ifndef CONFIG_MOTOR_MAX_RPM
    #define CONFIG_MOTOR_MAX_RPM    300
#endif

#define PPR  CONFIG_MOTOR_TOTAL_PPR

/* Hardware init and control */
int  motor_hw_init(void);
int  motor_is_ready(void);
void motor_set(int left_duty, int right_duty);
void motor_stop(void);

/* Encoder read (returns pulse count since last read) */
int32_t encoder_read_left(void);
int32_t encoder_read_right(void);

/* Unit conversion */
float pulse_to_rpm(int32_t pulse);
int   rpm_to_pulse(float rpm);

#ifdef __cplusplus
}
#endif

#endif /* MOTOR_CONTROL_H */
