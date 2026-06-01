# 电机模块移植指南

本文档说明如何将 motor 模块迁移到其他 SiFli 工程。

## 文件清单

```
motor/
├── motor_control.c       # 硬件抽象层：PWM/GPIO/编码器
├── motor_control.h
├── motor_app.c           # 应用层：PID控制线程与finsh命令
├── motor_app.h
├── pid.c                 # PID算法库
└── pid.h
```

## 移植步骤

### 1. 复制文件

将 `motor/` 目录下所有 `.c` 和 `.h` 文件复制到目标工程的 `app/src/motor/` 或 `personal/motor/` 下。

### 2. 适配引脚

修改 `motor_control.c` 顶部的引脚宏定义：

```c
#define PWMA_PIN  xx   // PWM A 输出
#define PWMB_PIN  xx   // PWM B 输出
#define AIN1_PIN  xx   // 左电机方向1
#define AIN2_PIN  xx   // 左电机方向2
#define STBY_PIN  xx   // 驱动器使能
#define BIN1_PIN  xx   // 右电机方向1
#define BIN2_PIN  xx   // 右电机方向2
#define ENC1A_PIN xx   // 编码器1 A相
#define ENC1B_PIN xx   // 编码器1 B相
#define ENC2A_PIN xx   // 编码器2 A相
#define ENC2B_PIN xx   // 编码器2 B相
```

同时修改对应的 HAL_PIN_Set() 引脚复用映射。

### 3. 适配电机参数

电机参数通过 Kconfig 配置，无需修改代码。在目标工程的 `proj.conf` 中设置：

```
CONFIG_MOTOR_TOTAL_PPR=xxxx       # 总脉冲数/转
CONFIG_MOTOR_MAX_RPM=xxx          # 最大转速
```

**计算 TOTAL_PPR：**
```
TOTAL_PPR = 编码器PPR × 减速比 × 4 (四倍频)
```
示例：MG310 → 13 × 20.409 × 4 = 1061

### 4. 添加 Kconfig 配置

将本模块的 `Kconfig.proj` 内容合并到目标工程的 `Kconfig.proj` 中（包含 `BSP_USING_MOTOR` 及其子配置项）。

在 `proj.conf` 中启用：

```
CONFIG_BSP_USING_MOTOR=y
```

### 5. 集成到 main.c

在 `main.c` 中添加：

```c
#ifdef BSP_USING_MOTOR
    #include "motor/motor_app.h"
#endif

// 在 main() 函数中，set_pinmux() 之后：
#ifdef BSP_USING_MOTOR
    motor_hw_init();
    motor_app_start();
#endif
```

### 6. 添加源文件到构建

在目标工程的 `app/src/SConscript` 中添加 motor 源文件编译：

```python
src = src + Glob('./motor/*.c')
```

### 7. 确认编译依赖

确保以下 Kconfig 选项已启用：

```
CONFIG_RT_USING_PULSE_ENCODER=y    # 编码器驱动
CONFIG_BSP_PWM3_UPDATE_USING_DMA=y # PWM DMA (视硬件而定)
```

## 注意事项

- 如果不使用编码器（开环控制），需要修改 `motor_control.c` 中的编码器初始化代码
- 如果驱动器极性不同（低电平有效），需要在 `motor_set()` 中反转方向逻辑
- PID 参数需根据实际电机特性进行调参
- 电机电源需提供足够启动电流，建议独立供电
