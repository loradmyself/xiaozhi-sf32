#include <stdio.h>
#include "./../xiaozhi_weather.h"
#include "lvgl.h"
#include <stdio.h>
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "gui_guider.h"

extern lv_ui standby_screen;
extern date_time_t g_current_time ;
extern weather_info_t g_current_weather;

//time_ui_update_callback
#define TIME_GET xiaozhi_time_get_current(&g_current_time)
//xiaozhi_time_get_current(&g_current_time)
#define TIME_DATA g_current_time.time_str
#define Current_Date g_current_time.date_str

#define user_ui_time_text_set lv_label_set_text(standby_screen.screen_xiaozhiui_time, TIME_DATA)
#define user_ui_data_text_set lv_label_set_text(standby_screen.screen_xiaozhiui_weather, Current_Date)


#define user_ui_update lv_obj_update_layout(standby_screen.screen)