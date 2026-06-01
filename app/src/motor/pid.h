#ifndef _PID_H
#define _PID_H

#include "rtthread.h"
#include "rthw.h"
#include "bf0_hal.h"
#include "drv_io.h"
#include "stdio.h"
#include "string.h"
#include "board.h"






typedef struct _pid_controller
{
    float Kp; // Proportional gain
    float Ki; // Integral gain
    float Kd; // Derivative gain

    float NowError;   // e(k) (current error)
    float LastError;  // e(k-1) (previous error)
    float LLastError; // e(k-2) (error two steps ago)
    float TotalError; // e(j) (accumulated/integral error)
    float Integral;   // Integral term
    float IntegralMax;

    float Result;     // U(k) (current control output)
    float LastResult; // U(k-1) (previous control output)

    float Target;
    float Measure;
    float LastMeasure;

    float MaxOutput; // Maximum control output (saturation limit)
    float MinOutput; // Minimum control output (saturation limit)
    float Resultoffset; // Output offset for dead zone compensation

    float dt;
} pid_controller_t;

typedef struct {
    pid_controller_t angle_pid;
    pid_controller_t speed_pid;
    pid_controller_t turn_pid;
    pid_controller_t pos_left_pid;
    pid_controller_t pos_right_pid;
    int is_flag_updated; // 标志位，指示PID参数是否被更新
    float speed; // 速度值，供外部访问
    float angle; // 角度值，供外部访问
} pid_manager_t;



void pid_shared_init(void);
pid_manager_t pid_shared_get(void);
void pid_shared_update(const char *name, float value);
void speed_control_update(float value);


int pid_controller_init(pid_controller_t *pid, float Kp, float Ki, float Kd, float MaxOutput, float MinOutput);
int pid_controller_set_params(pid_controller_t *pid, float Kp, float Ki,float Kd);
float pid_controller_cal(pid_controller_t *pid, float setpoint, float measure);
float pid_controller_cal_sat(pid_controller_t *pid, float setpoint,float measure);
float pid_controller_cal_sat_factory(pid_controller_t *pid);
int pid_controller_init_factory(pid_controller_t *pid, float Kp, float Ki, float Kd, float MaxOutput, float MinOutput, float integral_max, float T);
float pid_controller_cal_sat_y(pid_controller_t *pid);


#endif // PID_H