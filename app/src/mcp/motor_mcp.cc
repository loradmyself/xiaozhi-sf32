#include "rtthread.h"
#include "motor_mcp.h"
#include "../motor/motor_app.h"
#include "../motor/motor_control.h"
#include <string.h>
#include <string>
#include <finsh.h>

extern "C" {
    int msh_exec(char *cmd, rt_size_t length);


// MCP工具: 启动电机
// 参数: direction (string) - "forward" 或 "reverse"
//        speed (int) - 转速 RPM, 范围 0~300
//        rotations (int) - 圈数, 0表示连续转动
void MotorTool::RegisterMotorTool(McpServer* server) {

    // 启动电机工具
    server->AddTool(
        "self.motor.start",
        "Start the motor. Set direction (forward/reverse), speed in RPM (0-300), and rotations (0 for continuous).",
        PropertyList({
            Property("direction", kPropertyTypeString, std::string("forward")),
            Property("speed", kPropertyTypeInteger, 100, 0, 300),
            Property("rotations", kPropertyTypeInteger, 0, 0, 1000)
        }),
        [](const PropertyList& properties) -> ReturnValue {
            std::string dir = properties["direction"].value<std::string>();
            int speed = properties["speed"].value<int>();
            int rotations = properties["rotations"].value<int>();

            // 通过finsh命令控制电机
            // motor [dir] [spd] [num]
            // dir: 0=forward, 1=reverse
            int dir_val = (dir == "reverse") ? 1 : 0;

            // 构造finsh命令字符串
            char cmd[64];
            rt_snprintf(cmd, sizeof(cmd), "motor %d %d %d", dir_val, speed, rotations);

            // 通过finsh执行命令
            msh_exec(cmd, strlen(cmd));

            std::string result = "Motor started: " + dir + " at " + std::to_string(speed) + " RPM, " + std::to_string(rotations) + " rotations";
            return result;
        }
    );

    // 停止电机工具
    server->AddTool(
        "self.motor.stop",
        "Stop the motor immediately.",
        PropertyList(),
        [](const PropertyList&) -> ReturnValue {
            motor_app_stop();
            return std::string("Motor stopped");
        }
    );

    // 设置电机速度工具
    server->AddTool(
        "self.motor.set_speed",
        "Set motor speed. Speed range 0-300 RPM. 0 means stop.",
        PropertyList({
            Property("speed", kPropertyTypeInteger, 100, 0, 300)
        }),
        [](const PropertyList& properties) -> ReturnValue {
            int speed = properties["speed"].value<int>();

            if (speed == 0) {
                motor_app_stop();
                return std::string("Motor stopped (speed=0)");
            }

            // 正转指定速度，连续转动
            char cmd[64];
            rt_snprintf(cmd, sizeof(cmd), "motor 0 %d 0", speed);
            msh_exec(cmd, strlen(cmd));

            return "Motor speed set to " + std::to_string(speed) + " RPM";
        }
    );

    // 获取电机状态工具
    server->AddTool(
        "self.motor.get_status",
        "Get the current motor status (running or stopped).",
        PropertyList(),
        [](const PropertyList&) -> ReturnValue {
            return motor_is_ready() ? std::string("Motor ready") : std::string("Motor not initialized");
        }
    );
}

} // extern "C"
