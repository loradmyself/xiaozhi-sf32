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



void setup_scr_xiaozhiUI(lv_ui *ui)
{
    //Write codes xiaozhiUI
    ui->xiaozhiUI = lv_obj_create(NULL);
    lv_obj_set_size(ui->xiaozhiUI, 390, 450);
    lv_obj_set_scrollbar_mode(ui->xiaozhiUI, LV_SCROLLBAR_MODE_OFF);

    //Write style for xiaozhiUI, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->xiaozhiUI, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_xiaozhiUI_bg
    ui->xiaozhiUI_xiaozhiUI_bg = lv_animimg_create(ui->xiaozhiUI);
    lv_animimg_set_src(ui->xiaozhiUI_xiaozhiUI_bg, (const void **) xiaozhiUI_xiaozhiUI_bg_imgs, 41, false);
    lv_animimg_set_duration(ui->xiaozhiUI_xiaozhiUI_bg, 80*41);
    lv_animimg_set_repeat_count(ui->xiaozhiUI_xiaozhiUI_bg, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->xiaozhiUI_xiaozhiUI_bg);
    lv_obj_set_pos(ui->xiaozhiUI_xiaozhiUI_bg, 0, 0);
    lv_obj_set_size(ui->xiaozhiUI_xiaozhiUI_bg, 390, 450);

    //Write codes xiaozhiUI_xiaozhiUI_time
    ui->xiaozhiUI_xiaozhiUI_time = lv_label_create(ui->xiaozhiUI);
    lv_label_set_text(ui->xiaozhiUI_xiaozhiUI_time, "00:00");
    lv_label_set_long_mode(ui->xiaozhiUI_xiaozhiUI_time, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->xiaozhiUI_xiaozhiUI_time, 78, 56);
    lv_obj_set_size(ui->xiaozhiUI_xiaozhiUI_time, 233, 81);

    //Write style for xiaozhiUI_xiaozhiUI_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->xiaozhiUI_xiaozhiUI_time, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->xiaozhiUI_xiaozhiUI_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->xiaozhiUI_xiaozhiUI_time, LV_BORDER_SIDE_FULL | LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_xiaozhiUI_time, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->xiaozhiUI_xiaozhiUI_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->xiaozhiUI_xiaozhiUI_time, &lv_font_AlexBrush_Regular_70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->xiaozhiUI_xiaozhiUI_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->xiaozhiUI_xiaozhiUI_time, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->xiaozhiUI_xiaozhiUI_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->xiaozhiUI_xiaozhiUI_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_xiaozhiUI_weather
    ui->xiaozhiUI_xiaozhiUI_weather = lv_btn_create(ui->xiaozhiUI);
    ui->xiaozhiUI_xiaozhiUI_weather_label = lv_label_create(ui->xiaozhiUI_xiaozhiUI_weather);
    lv_label_set_text(ui->xiaozhiUI_xiaozhiUI_weather_label, "上海 晴 30 ℃");
    lv_label_set_long_mode(ui->xiaozhiUI_xiaozhiUI_weather_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->xiaozhiUI_xiaozhiUI_weather_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->xiaozhiUI_xiaozhiUI_weather, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->xiaozhiUI_xiaozhiUI_weather_label, LV_PCT(100));
    lv_obj_set_pos(ui->xiaozhiUI_xiaozhiUI_weather, 95, 15);
    lv_obj_set_size(ui->xiaozhiUI_xiaozhiUI_weather, 200, 20);

    //Write style for xiaozhiUI_xiaozhiUI_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_xiaozhiUI_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->xiaozhiUI_xiaozhiUI_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_xiaozhiUI_weather, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->xiaozhiUI_xiaozhiUI_weather, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->xiaozhiUI_xiaozhiUI_weather, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->xiaozhiUI_xiaozhiUI_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->xiaozhiUI_xiaozhiUI_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->xiaozhiUI_xiaozhiUI_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->xiaozhiUI_xiaozhiUI_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->xiaozhiUI_xiaozhiUI_weather, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->xiaozhiUI_xiaozhiUI_weather, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->xiaozhiUI_xiaozhiUI_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->xiaozhiUI_xiaozhiUI_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_WIFI_NC
    ui->xiaozhiUI_WIFI_NC = lv_img_create(ui->xiaozhiUI);
    lv_obj_add_flag(ui->xiaozhiUI_WIFI_NC, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->xiaozhiUI_WIFI_NC, &_WiFi_N_alpha_32x32);
    lv_img_set_pivot(ui->xiaozhiUI_WIFI_NC, 50,50);
    lv_img_set_angle(ui->xiaozhiUI_WIFI_NC, 0);
    lv_obj_set_pos(ui->xiaozhiUI_WIFI_NC, 20, 12);
    lv_obj_set_size(ui->xiaozhiUI_WIFI_NC, 32, 32);

    //Write style for xiaozhiUI_WIFI_NC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->xiaozhiUI_WIFI_NC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->xiaozhiUI_WIFI_NC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_WIFI_NC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->xiaozhiUI_WIFI_NC, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_WIFI_C
    ui->xiaozhiUI_WIFI_C = lv_img_create(ui->xiaozhiUI);
    lv_obj_add_flag(ui->xiaozhiUI_WIFI_C, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->xiaozhiUI_WIFI_C, &_WiFi_Y_alpha_32x32);
    lv_img_set_pivot(ui->xiaozhiUI_WIFI_C, 50,50);
    lv_img_set_angle(ui->xiaozhiUI_WIFI_C, 0);
    lv_obj_set_pos(ui->xiaozhiUI_WIFI_C, 20, 12);
    lv_obj_set_size(ui->xiaozhiUI_WIFI_C, 32, 32);
    lv_obj_add_flag(ui->xiaozhiUI_WIFI_C, LV_OBJ_FLAG_HIDDEN);

    //Write style for xiaozhiUI_WIFI_C, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->xiaozhiUI_WIFI_C, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->xiaozhiUI_WIFI_C, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_WIFI_C, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->xiaozhiUI_WIFI_C, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_battery
    ui->xiaozhiUI_battery = lv_bar_create(ui->xiaozhiUI);
    lv_obj_set_style_anim_time(ui->xiaozhiUI_battery, 0, 0);
    lv_bar_set_mode(ui->xiaozhiUI_battery, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->xiaozhiUI_battery, 0, 100);
    lv_bar_set_value(ui->xiaozhiUI_battery, 100, LV_ANIM_OFF);
    lv_obj_set_pos(ui->xiaozhiUI_battery, 305, 22);
    lv_obj_set_size(ui->xiaozhiUI_battery, 30, 15);

    //Write style for xiaozhiUI_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_battery, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->xiaozhiUI_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for xiaozhiUI_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_battery, 191, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->xiaozhiUI_battery, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->xiaozhiUI_battery, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_battery, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_datetext
    ui->xiaozhiUI_datetext = lv_label_create(ui->xiaozhiUI);
    lv_label_set_text(ui->xiaozhiUI_datetext, "2023/07/31");
    lv_obj_set_style_text_align(ui->xiaozhiUI_datetext, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->xiaozhiUI_datetext, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->xiaozhiUI_datetext, xiaozhiUI_datetext_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->xiaozhiUI_datetext, 113, 131);
    lv_obj_set_size(ui->xiaozhiUI_datetext, 164, 21);

    //Write style for xiaozhiUI_datetext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->xiaozhiUI_datetext, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->xiaozhiUI_datetext, &lv_font_ArchitectsDaughter_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->xiaozhiUI_datetext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->xiaozhiUI_datetext, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->xiaozhiUI_datetext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->xiaozhiUI_datetext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_BLE_C
    ui->xiaozhiUI_BLE_C = lv_img_create(ui->xiaozhiUI);
    lv_obj_add_flag(ui->xiaozhiUI_BLE_C, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->xiaozhiUI_BLE_C, &_bluetooth1_alpha_32x32);
    lv_img_set_pivot(ui->xiaozhiUI_BLE_C, 50,50);
    lv_img_set_angle(ui->xiaozhiUI_BLE_C, 0);
    lv_obj_set_pos(ui->xiaozhiUI_BLE_C, 55, 12);
    lv_obj_set_size(ui->xiaozhiUI_BLE_C, 32, 32);

    //Write style for xiaozhiUI_BLE_C, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->xiaozhiUI_BLE_C, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->xiaozhiUI_BLE_C, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_BLE_C, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->xiaozhiUI_BLE_C, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_BLE_NC
    ui->xiaozhiUI_BLE_NC = lv_img_create(ui->xiaozhiUI);
    lv_obj_add_flag(ui->xiaozhiUI_BLE_NC, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->xiaozhiUI_BLE_NC, &_bluetooth2_alpha_32x32);
    lv_img_set_pivot(ui->xiaozhiUI_BLE_NC, 50,50);
    lv_img_set_angle(ui->xiaozhiUI_BLE_NC, 0);
    lv_obj_set_pos(ui->xiaozhiUI_BLE_NC, 55, 12);
    lv_obj_set_size(ui->xiaozhiUI_BLE_NC, 32, 32);

    //Write style for xiaozhiUI_BLE_NC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->xiaozhiUI_BLE_NC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->xiaozhiUI_BLE_NC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_BLE_NC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->xiaozhiUI_BLE_NC, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_xiaozhi_connection
    ui->xiaozhiUI_xiaozhi_connection = lv_label_create(ui->xiaozhiUI);
    lv_label_set_text(ui->xiaozhiUI_xiaozhi_connection, "xiaozhi Connected");
    lv_label_set_long_mode(ui->xiaozhiUI_xiaozhi_connection, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_pos(ui->xiaozhiUI_xiaozhi_connection, 247, 264);
    lv_obj_set_size(ui->xiaozhiUI_xiaozhi_connection, 89, 28);

    //Write style for xiaozhiUI_xiaozhi_connection, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->xiaozhiUI_xiaozhi_connection, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_xiaozhi_connection, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->xiaozhiUI_xiaozhi_connection, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->xiaozhiUI_xiaozhi_connection, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->xiaozhiUI_xiaozhi_connection, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->xiaozhiUI_xiaozhi_connection, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->xiaozhiUI_xiaozhi_connection, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->xiaozhiUI_xiaozhi_connection, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_xiaozhi_connection, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->xiaozhiUI_xiaozhi_connection, lv_color_hex(0xd8ecfe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->xiaozhiUI_xiaozhi_connection, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->xiaozhiUI_xiaozhi_connection, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->xiaozhiUI_xiaozhi_connection, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->xiaozhiUI_xiaozhi_connection, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->xiaozhiUI_xiaozhi_connection, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->xiaozhiUI_xiaozhi_connection, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->xiaozhiUI_xiaozhi_connection, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->xiaozhiUI_xiaozhi_connection, 148, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->xiaozhiUI_xiaozhi_connection, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->xiaozhiUI_xiaozhi_connection, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->xiaozhiUI_xiaozhi_connection, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes xiaozhiUI_battery_txt
    ui->xiaozhiUI_battery_txt = lv_label_create(ui->xiaozhiUI);
    lv_label_set_text(ui->xiaozhiUI_battery_txt, "100%");
    lv_label_set_long_mode(ui->xiaozhiUI_battery_txt, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->xiaozhiUI_battery_txt, 336, 30);
    lv_obj_set_size(ui->xiaozhiUI_battery_txt, 23, 6);

    //Write style for xiaozhiUI_battery_txt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->xiaozhiUI_battery_txt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->xiaozhiUI_battery_txt, &lv_font_montserratMedium_7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->xiaozhiUI_battery_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->xiaozhiUI_battery_txt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->xiaozhiUI_battery_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of xiaozhiUI.


    //Update current screen layout.
    lv_obj_update_layout(ui->xiaozhiUI);

    //Init events for screen.
    events_init_xiaozhiUI(ui);
}
