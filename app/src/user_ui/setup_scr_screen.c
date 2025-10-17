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
    ui->screen_xiaozhiui_bg = lv_animimg_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_bg, 0, 0);
    lv_obj_set_size(ui->screen_xiaozhiui_bg, 390, 450);
    lv_animimg_set_src(ui->screen_xiaozhiui_bg, (const void **) screen_xiaozhiui_bg_imgs, 30);
    lv_animimg_set_duration(ui->screen_xiaozhiui_bg, 80*30);
    lv_animimg_set_repeat_count(ui->screen_xiaozhiui_bg, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->screen_xiaozhiui_bg);

    //Write codes screen_xiaozhiui_txt
    ui->screen_xiaozhiui_txt = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_txt, 247, 260);
    lv_obj_set_size(ui->screen_xiaozhiui_txt, 100, 32);
    lv_label_set_text(ui->screen_xiaozhiui_txt, "Waiting XiaoZhi Connect");
    lv_label_set_long_mode(ui->screen_xiaozhiui_txt, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for screen_xiaozhiui_txt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_txt, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_txt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_txt, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_txt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_txt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_txt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_txt, 38, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiaozhiui_txt, lv_color_hex(0x8b8b8b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiaozhiui_txt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_txt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_txt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_xiaozhiui_txt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_xiaozhiui_txt, 82, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_xiaozhiui_txt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_xiaozhiui_txt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_xiaozhiui_txt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_weather
    ui->screen_xiaozhiui_weather = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_weather, 109, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_weather, 170, 21);
    lv_label_set_text(ui->screen_xiaozhiui_weather, "Todays 's Weather & other information");
    lv_label_set_long_mode(ui->screen_xiaozhiui_weather, LV_LABEL_LONG_SCROLL_CIRCULAR);

    //Write style for screen_xiaozhiui_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_weather, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_weather, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_weather, &lv_font_AlexBrush_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_weather, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiaozhiui_weather, lv_color_hex(0x868686), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiaozhiui_weather, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_xiaozhiui_weather, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_xiaozhiui_weather, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_xiaozhiui_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_xiaozhiui_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_xiaozhiui_weather, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_time
    ui->screen_xiaozhiui_time = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_time, 72, 56);
    lv_obj_set_size(ui->screen_xiaozhiui_time, 244, 80);
    lv_label_set_text(ui->screen_xiaozhiui_time, "00:00");
    lv_label_set_long_mode(ui->screen_xiaozhiui_time, LV_LABEL_LONG_WRAP);

    //Write style for screen_xiaozhiui_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_time, &lv_font_AlexBrush_Regular_70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_time, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_bleC
    ui->screen_xiaozhiui_bleC = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_bleC, 68, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_bleC, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_bleC, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_xiaozhiui_bleC, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_bleC, &_bluetooth1_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_bleC, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_bleC, 0);

    //Write style for screen_xiaozhiui_bleC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_bleC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_bleC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_bleN
    ui->screen_xiaozhiui_bleN = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_bleN, 68, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_bleN, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_bleN, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_bleN, &_bluetooth2_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_bleN, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_bleN, 0);

    //Write style for screen_xiaozhiui_bleN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_bleN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_bleN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_wifiC
    ui->screen_xiaozhiui_wifiC = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_wifiC, 33, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_wifiC, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_wifiC, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_xiaozhiui_wifiC, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_wifiC, &_WiFi_Y_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_wifiC, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_wifiC, 0);

    //Write style for screen_xiaozhiui_wifiC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_wifiC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_wifiC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_wifiN
    ui->screen_xiaozhiui_wifiN = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_wifiN, 33, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_wifiN, 25, 25);
    lv_obj_add_flag(ui->screen_xiaozhiui_wifiN, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_xiaozhiui_wifiN, &_WiFi_N_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_xiaozhiui_wifiN, 50,50);
    lv_image_set_rotation(ui->screen_xiaozhiui_wifiN, 0);

    //Write style for screen_xiaozhiui_wifiN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_xiaozhiui_wifiN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_xiaozhiui_wifiN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_battery
    ui->screen_xiaozhiui_battery = lv_bar_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_battery, 306, 15);
    lv_obj_set_size(ui->screen_xiaozhiui_battery, 48, 17);
    lv_obj_set_style_anim_duration(ui->screen_xiaozhiui_battery, 1000, 0);
    lv_bar_set_mode(ui->screen_xiaozhiui_battery, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_xiaozhiui_battery, 0, 100);
    lv_bar_set_value(ui->screen_xiaozhiui_battery, 50, LV_ANIM_OFF);

    //Write style for screen_xiaozhiui_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_battery, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiaozhiui_battery, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiaozhiui_battery, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_battery, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_battery, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_xiaozhiui_battery, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_xiaozhiui_battery, 120, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_xiaozhiui_battery, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_xiaozhiui_battery, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_xiaozhiui_battery, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_xiaozhiui_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_battery, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_xiaozhiui_battery, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_xiaozhiui_battery, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_battery, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_xiaozhiui_data
    ui->screen_xiaozhiui_data = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_xiaozhiui_data, 116, 136);
    lv_obj_set_size(ui->screen_xiaozhiui_data, 159, 34);
    lv_label_set_text(ui->screen_xiaozhiui_data, "2024/04/22");
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_data, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->screen_xiaozhiui_data, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->screen_xiaozhiui_data, screen_xiaozhiui_data_event_handler, LV_EVENT_ALL, NULL);

    //Write style for screen_xiaozhiui_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_xiaozhiui_data, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_xiaozhiui_data, &lv_font_AlexBrush_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_xiaozhiui_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_xiaozhiui_data, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_xiaozhiui_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_xiaozhiui_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_xiaozhiui_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_xiaozhiui_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_xiaozhiui_data, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_xiaozhiui_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_xiaozhiui_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_xiaozhiui_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
