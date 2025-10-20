/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 390, 450);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_bg
    ui->screen_xiaozhiui_bg = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_bg, 0, 0);
    lv_obj_set_size(ui->screen_xiaozhiui_bg, 390, 450);
    lv_obj_add_flag(ui->screen_xiaozhiui_bg, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_bg, &_preview_RGB565A8_390x450);
    lv_image_set_pivot(ui->screen_xiaozhiui_bg, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_bg, 0);

    //Write style for screen_xiaozhiui_bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_bg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_time
    ui->screen_xiaozhiui_time = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_time, 95, 60);
    lv_obj_set_size(ui->screen_xiaozhiui_time, 200, 60);
    lv_label_set_text(ui->screen_xiaozhiui_time, "00:00");
    lv_label_set_long_mode(ui->screen_xiaozhiui_time, LV_LABEL_LONG_WRAP);

    //Write style for screen_xiaozhiui_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_time, &lv_font_AlexBrush_Regular_70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_weather
    ui->screen_xiaozhiui_weather = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_weather, 95, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_weather, 200, 25);
    lv_label_set_text(ui->screen_xiaozhiui_weather, "xiaozhiui_weather information 年月日 天气 晴雨雪大小中风冰雾沙 周一二三四五六末");
    lv_label_set_long_mode(ui->screen_xiaozhiui_weather, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for screen_xiaozhiui_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_weather, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_xiaozhiui_weather, 114, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_xiaozhiui_weather, lv_color_hex(0x474747), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_xiaozhiui_weather, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_weather, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_weather, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_weather, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_weather, 42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiaozhiui_weather, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiaozhiui_weather, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_connect
    ui->screen_xiaozhiui_connect = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_connect, 258, 205);
    lv_obj_set_size(ui->screen_xiaozhiui_connect, 91, 29);
    lv_label_set_text(ui->screen_xiaozhiui_connect, "连接中...请按按键连接小智...初始化请稍等");
    lv_label_set_long_mode(ui->screen_xiaozhiui_connect, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for screen_xiaozhiui_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_connect, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_xiaozhiui_connect, 137, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_xiaozhiui_connect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_xiaozhiui_connect, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_connect, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_connect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_connect, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_connect, 69, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiaozhiui_connect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiaozhiui_connect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_date
    ui->screen_xiaozhiui_date = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_date, 255, 126);
    lv_obj_set_size(ui->screen_xiaozhiui_date, 123, 36);
    lv_label_set_text(ui->screen_xiaozhiui_date, "2025年12月30日 周三");
    lv_label_set_long_mode(ui->screen_xiaozhiui_date, LV_LABEL_LONG_WRAP);

    //Write style for screen_xiaozhiui_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_date, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_date, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_ble_N
    ui->screen_xiaozhiui_ble_N = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_ble_N, 60, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_ble_N, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_ble_N, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_ble_N, &_bluetooth2_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_ble_N, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_ble_N, 0);

    //Write style for screen_xiaozhiui_ble_N, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_ble_N, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_ble_N, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_ble_Y
    ui->screen_xiaozhiui_ble_Y = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_ble_Y, 60, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_ble_Y, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_ble_Y, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_xiaozhiui_ble_Y, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_ble_Y, &_bluetooth1_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_ble_Y, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_ble_Y, 0);

    //Write style for screen_xiaozhiui_ble_Y, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_ble_Y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_ble_Y, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_wifi_Y
    ui->screen_xiaozhiui_wifi_Y = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_wifi_Y, 30, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_wifi_Y, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_wifi_Y, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_xiaozhiui_wifi_Y, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_wifi_Y, &_WiFi_Y_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_wifi_Y, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_wifi_Y, 0);

    //Write style for screen_xiaozhiui_wifi_Y, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_wifi_Y, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_wifi_Y, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_wifi_N
    ui->screen_xiaozhiui_wifi_N = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_wifi_N, 30, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_wifi_N, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_wifi_N, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_wifi_N, &_WiFi_N_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_wifi_N, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_wifi_N, 0);

    //Write style for screen_xiaozhiui_wifi_N, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_wifi_N, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_wifi_N, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiazhiui_battery
    ui->screen_xiazhiui_battery = lv_bar_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiazhiui_battery, 300, 17);
    lv_obj_set_size(ui->screen_xiazhiui_battery, 50, 20);
    lv_obj_set_style_anim_duration(ui->screen_xiazhiui_battery, 1000, 0);
    lv_bar_set_mode(ui->screen_xiazhiui_battery, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_xiazhiui_battery, 0, 100);
    lv_bar_set_value(ui->screen_xiazhiui_battery, 50, LV_ANIM_OFF);

    //Write style for screen_xiazhiui_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_xiazhiui_battery, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiazhiui_battery, lv_color_hex(0x2c2c2c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiazhiui_battery, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiazhiui_battery, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiazhiui_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_xiazhiui_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_xiazhiui_battery, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiazhiui_battery, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiazhiui_battery, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiazhiui_battery, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_battery_percent
    ui->screen_xiaozhiui_battery_percent = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_battery_percent, 349, 23);
    lv_obj_set_size(ui->screen_xiaozhiui_battery_percent, 28, 18);
    lv_label_set_text(ui->screen_xiaozhiui_battery_percent, "100%");
    lv_label_set_long_mode(ui->screen_xiaozhiui_battery_percent, LV_LABEL_LONG_WRAP);

    //Write style for screen_xiaozhiui_battery_percent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_battery_percent, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_battery_percent, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_battery_percent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_battery_percent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_battery_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
