#include <stdio.h>
#include "./../xiaozhi_weather.h"
extern date_time_t g_current_time ;
//time_ui_update_callback
#define TIME_GET xiaozhi_time_get_current(&g_current_time)
//xiaozhi_time_get_current(&g_current_time)
#define TIME_DATA g_current_time.time_str