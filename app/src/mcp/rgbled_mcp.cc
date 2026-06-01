#include "rtthread.h"
#include "rgbled_mcp.h"
#include "drv_io.h"
#include "stdio.h"
#include "string.h"
#include <string>
#include "drivers/rt_drv_pwm.h"
#include "bf0_hal.h"
#include "../board/board_hardware.h" 
#define LED_PIN 32 
RGBLEDController& GetRGBLEDController() {
    static RGBLEDController instance;
    return instance;
}

bool RGBLEDTool::is_color_cycling_ = false;
void RGBLEDTool::ColorCycleThreadEntry(void* param) 
{
    open_led();    
}
bool RGBLEDTool::IsLightOn() {
    // 如果正在循环变色，则认为灯是开启状态
    return is_color_cycling_;
}
void RGBLEDTool::RegisterRGBLEDTool(McpServer* server) {
    // 循环变色工具
        server->AddTool(
            "self.led.turn_on_the_light",
            "turn on the light.",
            PropertyList(),
            [](const PropertyList&) -> ReturnValue {
            if (is_color_cycling_) return true;
            is_color_cycling_ = true;
            // 配置PA32为GPIO输出模式并输出低电平（点亮）
            set_mode_led(); 
            rt_thread_t thread = rt_thread_create("rgb_cycle",
                            ColorCycleThreadEntry, 
                            nullptr,
                            1024,
                            10,
                            10);
            if (thread) rt_thread_startup(thread);
            return true;
    }
    );

    server->AddTool(
        "self.led.turn_off_the_light",
        "turn off the light.",
        PropertyList(),
        [](const PropertyList&) -> ReturnValue {
            close_led();
            is_color_cycling_ = false;
            return true;
        }
    );

    server->AddTool(
        "self.led.get_light_status",
        "Get the current status of the LED (on or off).",
        PropertyList(),
        [](const PropertyList&) -> ReturnValue {
            return RGBLEDTool::IsLightOn();
        }
    );

    // 指定颜色亮灯工具
    server->AddTool(
        "self.led.set_color",
        "Set the LED to a specific color. Supported colors: red, green, blue, yellow, cyan, purple, white, black(off).",
        PropertyList({
            Property("color", kPropertyTypeString, std::string("red"))
        }),
        [](const PropertyList& properties) -> ReturnValue {
            std::string color_name = properties["color"].value<std::string>();

            // 在颜色表中查找
            uint32_t color = 0;
            bool found = false;
            for (size_t i = 0; i < sizeof(rgb_color_arry) / sizeof(rgb_color_arry[0]); i++) {
                if (color_name == rgb_color_arry[i].color_name) {
                    color = rgb_color_arry[i].color;
                    found = true;
                    break;
                }
            }

            if (!found) {
                return std::string("Unknown color: " + color_name + ". Supported: red, green, blue, yellow, cyan, purple, white, black");
            }

            // 黑色表示关灯
            if (color == 0x000000) {
                close_led();
                is_color_cycling_ = false;
                return std::string("LED turned off (black)");
            }

            // 设置颜色
            GetRGBLEDController().SetColor(color);
            is_color_cycling_ = true;
            return std::string("LED set to " + color_name);
        }
    );
}

// finsh测试命令: led_test red
static void led_test(int argc, char **argv)
{
    if (argc != 2) {
        rt_kprintf("Usage: led_test <color>\n");
        rt_kprintf("  color: red, green, blue, yellow, cyan, purple, white, off\n");
        return;
    }

    std::string color_name = argv[1];

    if (color_name == "off") {
        close_led();
        rt_kprintf("LED off\n");
        return;
    }

    uint32_t color = 0;
    bool found = false;
    for (size_t i = 0; i < sizeof(rgb_color_arry) / sizeof(rgb_color_arry[0]); i++) {
        if (color_name == rgb_color_arry[i].color_name) {
            color = rgb_color_arry[i].color;
            found = true;
            break;
        }
    }

    if (!found) {
        rt_kprintf("Unknown color: %s\n", color_name.c_str());
        return;
    }

    GetRGBLEDController().SetColor(color);
    rt_kprintf("LED set to %s (0x%06X)\n", color_name.c_str(), color);
}
MSH_CMD_EXPORT(led_test, LED test : led_test[color]);
