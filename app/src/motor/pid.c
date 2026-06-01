#include "pid.h"
/**
 * @brief Initialize a PID controller structure
 *
 * @param pid Pointer to the pid_controller_t structure to initialize
 * @param Kp Proportional gain
 * @param Ki Integral gain
 * @param Kd Derivative gain
 * @return 0 on success, -1 on invalid parameter
 */
int pid_controller_init(pid_controller_t *pid, float Kp, float Ki, float Kd, float MaxOutput, float MinOutput)
{
    if (pid == RT_NULL)
        return -1;

    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;

    // pid->Target = 0.0f;
    // pid->Measure = 0.0f;

    pid->NowError = 0.0f;
    pid->LastError = 0.0f;
    pid->LLastError = 0.0f;
    pid->TotalError = 0.0f;

    pid->Result = 0.0f;
    pid->LastResult = 0.0f;

    pid->MaxOutput = MaxOutput;
    pid->MinOutput = MinOutput;

    return 0;
}

/**
 * @brief Set PID controller parameters
 *
 * @param pid Pointer to pid_controller_t structure
 * @param Kp Proportional gain
 * @param Ki Integral gain
 * @param Kd Derivative gain
 * @return 0 on success, -1 on invalid parameter
 */
int pid_controller_set_params(pid_controller_t *pid, float Kp, float Ki,
                              float Kd)
{
    if (pid == RT_NULL)
        return -1;

    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;

    return 0;
}

/**
 * @brief Compute PID output (no anti-windup)
 *
 * Uses the incremental form to compute the PID output and updates historical
 * errors and the previous output.
 *
 * @param pid Pointer to pid_controller_t structure
 * @param setpoint Target setpoint
 * @param measure Measured value
 * @return Computed control value (float)
 */
float pid_controller_cal(pid_controller_t *pid, float setpoint, float measure)
{
    if (pid == RT_NULL)
        return 0.0f;

    pid->NowError = setpoint - measure;
    pid->TotalError += pid->NowError;

    // PID calculation
    pid->Result =
        pid->LastResult + pid->Kp * (pid->NowError - pid->LastError) +
        pid->Ki * pid->NowError +
        pid->Kd * (pid->NowError - 2 * pid->LastError + pid->LLastError);

    // Save historical data
    pid->LLastError = pid->LastError;
    pid->LastError = pid->NowError;
    pid->LastResult = pid->Result;

    return pid->Result;
}

/**
 * @brief Compute PID output (with anti-integral-windup)
 *
 * Similar to pid_controller_cal but applies saturation limits after calculation
 * to prevent integral accumulation from causing outputs to go out of range.
 *
 * @param pid Pointer to pid_controller_t structure
 * @param setpoint Target setpoint
 * @param measure Measured value
 * @return Computed and clipped control value (float)
 */
float pid_controller_cal_sat(pid_controller_t *pid, float setpoint,
                             float measure)
{
    if (pid == RT_NULL)
        return 0.0f;

    pid->NowError = setpoint - measure;
    pid->TotalError += pid->NowError;

    // PID calculation
    pid->Result =
        pid->LastResult + pid->Kp * (pid->NowError - pid->LastError) +
        pid->Ki * pid->NowError +
        pid->Kd * (pid->NowError - 2 * pid->LastError + pid->LLastError);

    // Save historical data
    pid->LLastError = pid->LastError;
    pid->LastError = pid->NowError;
    pid->LastResult = pid->Result;

    // Anti-integral-windup (saturation handling)
    if (pid->LastResult > pid->MaxOutput)
        pid->LastResult = pid->MaxOutput;
    if (pid->LastResult < pid->MinOutput)
        pid->LastResult = pid->MinOutput;
    if (pid->Result > pid->MaxOutput)
        pid->Result = pid->MaxOutput;
    if (pid->Result < pid->MinOutput)
        pid->Result = pid->MinOutput;

    return pid->Result;
}

int pid_controller_init_factory(pid_controller_t *pid, float Kp, float Ki, float Kd, float MaxOutput, float MinOutput, float integral_max, float T)
{
    if (pid == RT_NULL)
        return -1;

    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->dt = T;

    pid->Target = 0.0f;
    pid->Measure = 0.0f;

    pid->NowError = 0.0f;
    pid->LastError = 0.0f;
    pid->LLastError = 0.0f;
    pid->TotalError = 0.0f;

    pid->Result = 0.0f;
    pid->LastResult = 0.0f;

    pid->MaxOutput = MaxOutput;
    pid->MinOutput = MinOutput;
    pid->IntegralMax = integral_max;

    return 0;
}

float pid_controller_cal_sat_factory(pid_controller_t *pid)
{
    if (pid == RT_NULL)
        return 0.0f;

    // 1. 计算误差
    pid->NowError = pid->Target - pid->Measure;
    
    // 处理角度跳变（如果是角度控制）
    // if (pid->NowError > 180.0f) pid->NowError -= 360.0f;
    // if (pid->NowError < -180.0f) pid->NowError += 360.0f;

    // 2. 比例项
    float p_out = pid->Kp * pid->NowError;

    // 3. 积分项（带抗积分饱和）
    pid->Integral += pid->NowError * pid->dt;
    
    // 积分限幅
    if (pid->Integral > pid->IntegralMax)
        pid->Integral = pid->IntegralMax;
    if (pid->Integral < -pid->IntegralMax)
        pid->Integral = -pid->IntegralMax;
    
    float i_out = pid->Ki * pid->Integral;

    // 4. 微分项（带低通滤波）
    float d_out = 0;
    static float d_filtered = 0;
    if (pid->dt > 0) {
        float derivative = (pid->NowError - pid->LastError) / pid->dt;
        // 一阶低通滤波
        d_filtered = 0.8f * d_filtered + 0.2f * derivative;
        d_out = pid->Kd * d_filtered;
    }

    // 5. 计算输出
    pid->Result = p_out + i_out + d_out;

    // 6. 输出限幅和抗积分饱和
    float pre_sat = pid->Result;
    
    if (pid->Result > pid->MaxOutput) {
        pid->Result = pid->MaxOutput;
        
        // 抗积分饱和：当输出饱和且误差同向时，停止积分
        if (pid->NowError * pid->Ki > 0) {
            // 反向计算积分：撤消这次的积分增加
            pid->Integral -= pid->NowError * pid->dt;
        }
    }
    
    if (pid->Result < pid->MinOutput) {
        pid->Result = pid->MinOutput;
        
        if (pid->NowError * pid->Ki < 0) {
            pid->Integral -= pid->NowError * pid->dt;
        }
    }

    // 7. 保存历史数据
    pid->LLastError = pid->LastError;
    pid->LastError = pid->NowError;
    pid->LastResult = pid->Result;


    return pid->Result;
}

float pid_controller_cal_sat_y(pid_controller_t *pid)
{
    pid->LastError = pid->NowError;
	pid->NowError = pid->Target - pid->Measure;
	
	if (pid->Ki != 0)
	{
		pid->Integral += pid->NowError;
	}
	else
	{
		pid->Integral = 0;
	}

    float max_integral = pid->MaxOutput / 2.0 / pid->Ki;  // 防止积分过大
    if (pid->Integral > max_integral)
        pid->Integral = max_integral;
    if (pid->Integral < -max_integral)
        pid->Integral = -max_integral;

	
	pid->Result = pid->Kp * pid->NowError
		        + pid->Ki * pid->Integral
                - pid->Kd * (pid->Measure - pid->LastMeasure); //weifenxiangxing
		        //+ pid->Kd * (pid->NowError - pid->LastError)*2;

	if (pid->Result > pid->MaxOutput) {pid->Result = pid->MaxOutput;}
	if (pid->Result < pid->MinOutput) {pid->Result = pid->MinOutput;}

    if(pid->Result >0) 
    {
        pid->Result += pid->Resultoffset;
    }
    if(pid->Result <0) 
    {
        pid->Result -= pid->Resultoffset;
    }

    pid->LastMeasure = pid->Measure;

    return pid->Result;
}



static struct rt_mutex pid_mutex;
static struct rt_mutex speed_mutex;
static pid_manager_t g_pid;

void pid_shared_init(void)
{
    rt_mutex_init(&pid_mutex, "pid_lock", RT_IPC_FLAG_FIFO);
    
    // 默认值
    g_pid.angle_pid.Kp = 4.7;
    g_pid.angle_pid.Ki = 0.12;
    g_pid.angle_pid.Kd = 3.9;
    g_pid.angle_pid.Resultoffset = 0;

    g_pid.speed_pid.Kp = 0.23;
    g_pid.speed_pid.Ki = 0.01;
    g_pid.speed_pid.Kd = 0;
    g_pid.speed_pid.Resultoffset = 0;

    g_pid.turn_pid.Kp = 1.0;
    g_pid.turn_pid.Ki = 0.01;
    g_pid.turn_pid.Kd = 0.0;
    g_pid.turn_pid.Resultoffset = 0;
    
    g_pid.speed = 0;
    g_pid.is_flag_updated = 0;
}

pid_manager_t pid_shared_get(void)
{
    pid_manager_t copy;
    
    rt_mutex_take(&pid_mutex, RT_WAITING_FOREVER);
    copy = g_pid;  // 结构体拷贝
    rt_mutex_release(&pid_mutex);
    
    return copy;
}

void speed_control_update(float value)
{
    rt_mutex_take(&pid_mutex, RT_WAITING_FOREVER);
    //g_pid.speed = value;
    rt_mutex_release(&pid_mutex);
}

void pid_shared_update(const char *name, float value)
{
    rt_mutex_take(&pid_mutex, RT_WAITING_FOREVER);
    g_pid.is_flag_updated = 1;
    if (strcmp(name, "angle_p") == 0) {
        g_pid.angle_pid.Kp = value;
    } else if (strcmp(name, "angle_i") == 0) {
        g_pid.angle_pid.Ki = value;
    } else if (strcmp(name, "angle_d") == 0) {
        g_pid.angle_pid.Kd = value;
    } else if (strcmp(name, "speed_p") == 0) {
        g_pid.speed_pid.Kp = value;
    } else if (strcmp(name, "speed_i") == 0) {
        g_pid.speed_pid.Ki = value;
    } else if (strcmp(name, "speed_d") == 0) {
        g_pid.speed_pid.Kd = value;
    } else if (strcmp(name, "turn_p") == 0) {
        g_pid.turn_pid.Kp = value;
    } else if (strcmp(name, "turn_i") == 0) {
        g_pid.turn_pid.Ki = value;
    } else if (strcmp(name, "turn_d") == 0) {
        g_pid.turn_pid.Kd = value;
    } else if (strcmp(name, "spd_ofs") == 0) {
        g_pid.speed_pid.Resultoffset = value;
    } else if (strcmp(name, "ang_ofs") == 0) {
        g_pid.angle_pid.Resultoffset = value;
    }else if(strcmp(name, "spd_val") == 0) {
        g_pid.speed = value;
    }else if(strcmp(name, "ang_val") == 0) {
        g_pid.angle = value;
    }

    rt_mutex_release(&pid_mutex);
}
