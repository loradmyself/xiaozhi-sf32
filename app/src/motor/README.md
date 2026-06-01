# 电机控制模块

小智工程电机驱动模块，基于 TB6612FNG 双路电机驱动，支持速度/位置 PID 闭环控制。

## 模块架构

```
motor/
├── motor_control.c/.h   # 硬件抽象层 (HAL)：PWM、GPIO方向、编码器
├── motor_app.c/.h       # 应用层：PID控制线程、finsh命令接口
└── pid.c/.h             # PID算法：增量式PID，带抗饱和
```

## 功能特性

- 双路直流减速电机独立控制
- 速度环 + 位置环双闭环 PID 控制
- 正交编码器读取转速/位置
- finsh 命令行接口：`motor [dir] [spd] [num]`
- 编译时可开关（Kconfig `BSP_USING_MOTOR`）
- 电机参数通过 Kconfig 配置，无需修改代码

## 启用/禁用

在 `app/project/proj.conf` 中设置：

```
CONFIG_BSP_USING_MOTOR=y    # 启用
# CONFIG_BSP_USING_MOTOR is not set  # 禁用
```

或通过 `menuconfig` 进入 `Project configuration → Enable motor control module`。

## Kconfig 配置项

| 配置项              | 说明           | 默认值 |
| :------------------ | :------------- | :----: |
| `BSP_USING_MOTOR` | 启用电机模块   |   n   |
| `MOTOR_TOTAL_PPR` | 总脉冲数/转    |  1061  |
| `MOTOR_MAX_RPM`   | 最大转速 (RPM) |  300  |

## 更换电机参数指南

当使用不同型号的电机时，只需修改 `proj.conf` 中的两个值：

```
CONFIG_MOTOR_TOTAL_PPR=xxxx   # 总脉冲数
CONFIG_MOTOR_MAX_RPM=xxx      # 最大转速
```

### 如何计算 TOTAL_PPR

```
TOTAL_PPR = 编码器PPR × 减速比 × 4 (四倍频)
```

查阅电机数据手册获取编码器PPR和减速比，代入公式计算。

**常见电机参考：**

| 电机型号  | 编码器PPR | 减速比 | TOTAL_PPR 计算                    | 额定RPM |
| :-------- | :-------: | :----: | :-------------------------------- | :-----: |
| MG310     |    13    | 20.409 | 13 × 20.409 × 4 =**1061** |   300   |
| JGB37-520 |    11    |   20   | 11 × 20 × 4 =**880**      |   350   |
| JGA25-370 |    11    |   34   | 11 × 34 × 4 =**1496**     |   200   |
| GA12-N20  |    12    |   30   | 12 × 30 × 4 =**1440**     |   150   |

> **注意**：如果电机没有编码器，无法使用闭环控制，需修改代码为开环模式。

### 验证配置

编译后通过finsh命令验证：

```
motor 0 60 1    # 低速正转1圈
```

观察：

1. 电机是否按预期方向转动
2. 转速是否接近设定值（串口日志会打印实际转速）
3. 转动圈数是否准确

### PID 调参（如需）

如果速度控制不准确，修改 `motor_app.c` 中的 `pid_controller_init()` 参数：

```c
// 速度环PID (默认: Kp=100, Ki=20, Kd=0)
pid_controller_init(&pid_speed_l, Kp, Ki, Kd, MAX_DUTY, MIN_DUTY);

// 位置环PID (默认: Kp=1, Ki=0, Kd=0)
pid_controller_init(&pid_pos_l, Kp, Ki, Kd, MAX_DUTY, MIN_DUTY);
```

调参顺序：先设 Ki=0, Kd=0 → 增大 Kp → 加 Ki 消除稳态误差 → 微调 Kd。

## finsh 命令

```
motor [dir] [spd] [num]
```

| 参数 | 说明 | 取值范围                          |
| ---- | ---- | --------------------------------- |
| dir  | 方向 | 0=正转, 1=反转                    |
| spd  | 转速 | rpm (0 ~ MOTOR_MAX_RPM)           |
| num  | 圈数 | 0=连续转动, >0=转动指定圈数后停止 |

**示例：**

```
motor 0 120 10   # 正转 120rpm，转10圈后停止
motor 1 180 0    # 反转 180rpm，连续转动
motor 0 0 0      # 停止
```

## 硬件连接

### TB6612FNG 驱动器

| 功能              |     宏名     | 引脚号 | 引脚名 |
| :---------------- | :----------: | :----: | :----: |
| PWM A 输出        | `PWMA_PIN` |   29   |  PA29  |
| PWM B 输出        | `PWMB_PIN` |   20   |  PA20  |
| AIN1 (左电机方向) | `AIN1_PIN` |   35   |  PA35  |
| AIN2 (左电机方向) | `AIN2_PIN` |   36   |  PA36  |
| STBY (使能)       | `STBY_PIN` |   -   |   -   |
| BIN1 (右电机方向) | `BIN1_PIN` |   27   |  PA27  |
| BIN2 (右电机方向) | `BIN2_PIN` |   28   |  PA28  |

### 编码器

| 功能        |     宏名     | 引脚号 | 引脚名 |
| :---------- | :-----------: | :----: | :----: |
| 编码器1 A相 | `ENC1A_PIN` |   25   |  PA25  |
| 编码器1 B相 | `ENC1B_PIN` |   24   |  PA24  |
| 编码器2 A相 | `ENC2A_PIN` |   30   |  PA30  |
| 编码器2 B相 | `ENC2B_PIN` |   26   |  PA26  |

### 电机接线

- 左电机 M+ → 驱动器 AO1，M- → AO2
- 右电机 M+ → 驱动器 BO2，M- → BO1

## 硬件参数 (默认值)

| 参数             | 值             | Kconfig 配置项      |
| :--------------- | :------------- | :------------------ |
| 总 PPR (含4倍频) | 1061           | `MOTOR_TOTAL_PPR` |
| PWM 周期         | 50000 (0.5ms)  | 固定                |
| 占空比范围       | -10000 ~ 10000 | 固定                |
| 最大转速         | 300 rpm        | `MOTOR_MAX_RPM`   |

## API 接口

### motor_control.h (HAL层)

```c
int  motor_hw_init(void);                           // 硬件初始化 (0=成功, -1=失败)
int  motor_is_ready(void);                          // 检查是否初始化成功
void motor_set(int left_duty, int right_duty);     // 直接设置占空比 (-10000~10000)
void motor_stop(void);                              // 停止电机
int32_t encoder_read_left(void);                    // 读取左编码器脉冲
int32_t encoder_read_right(void);                   // 读取右编码器脉冲
float pulse_to_rpm(int32_t pulse);                  // 脉冲→RPM转换
int rpm_to_pulse(float rpm);                        // RPM→脉冲转换
```

### motor_app.h (应用层)

```c
void motor_app_start(void); // 启动PID控制线程
void motor_app_stop(void);  // 停止PID控制线程
```

## 线程参数

| 参数     | 值          |
| :------- | :---------- |
| 线程名   | `motor`   |
| 栈大小   | 2048 bytes  |
| 优先级   | 10          |
| 时间片   | 10          |
| 控制频率 | 50Hz (20ms) |

## PID 参数

| 环路   | Kp | Ki | Kd | 输出范围 |
| :----- | :-: | :-: | :-: | :------: |
| 速度环 | 100 | 20 | 0 | ±10000 |
| 位置环 |  1  | 0 | 0 | ±10000 |

可通过修改 `motor_app.c` 中的 `pid_controller_init()` 参数进行调参。

## 编译依赖

- `CONFIG_BSP_USING_MOTOR=y`
- `CONFIG_MOTOR_TOTAL_PPR=1061` (根据电机调整)
- `CONFIG_MOTOR_MAX_RPM=300` (根据电机调整)
- `CONFIG_RT_USING_PULSE_ENCODER=y` (已在 proj.conf 中启用)
