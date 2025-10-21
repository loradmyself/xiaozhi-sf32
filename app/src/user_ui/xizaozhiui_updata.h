#include <stdio.h>
#include "./../xiaozhi_weather.h"
#include "lvgl.h"
#include <stdio.h>
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "gui_guider.h"

extern lv_ui standby_screen;                /*小智的待机界面*/
extern date_time_t g_current_time ;         /*当前时间结构体*/
extern weather_info_t g_current_weather;    /*当前天气结构体*/

//time_ui_update_callback
#define TIME_GET xiaozhi_time_get_current(&g_current_time)          /*获取当前时间信息*/

#define Current_Time    g_current_time.time_str                        /*获取当前时间字符串*/   
#define Current_Date    g_current_time.date_str                        /*获取当前日期字符串*/
#define Current_Weather g_current_weather.weather_str                  /*获取当前天气文本信息*/

//#define Current_Connect  (g_bt_app_env.bt_connected ? "已连接" : "未连接") /*获取当前连接状态字符串*/
//#define Current_BLE     (g_bt_app_env.bt_connected ? "蓝牙已连接" : "蓝牙未连接") /*获取当前蓝牙连接状态字符串*/
//#define Current_wifi    (g_pan_connected ? "WiFi已连接" : "WiFi未连接") /*获取当前WiFi连接状态字符串*/
//#define Current_Battery g_battery_level_str                          /*获取当前电池电量字符串*/
//


/*设置时间/日期/天气*/
#define user_ui_time_text_set    lv_label_set_text(standby_screen.screen_xiaozhiui_time, Current_Time)              /*设置时间标签文本*/
#define user_ui_date_text_set    lv_label_set_text(standby_screen.screen_xiaozhiui_date, Current_Date)              /*设置日期标签文本*/
#define user_ui_weather_text_set lv_label_set_text(standby_screen.screen_xiaozhiui_weather, Current_Weather)        /*设置天气标签文本*/
//#define user_ui_connect_text_set lv_label_set_text(standby_screen.screen_xiaozhiui_connect, Current_Connect) /*设置连接标签文本*/

#define user_ui_update lv_obj_update_layout(standby_screen.screen)