/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *xiaozhiUI;
	bool xiaozhiUI_del;
	lv_obj_t *xiaozhiUI_xiaozhiUI_bg;
	lv_obj_t *xiaozhiUI_xiaozhiUI_time;
	lv_obj_t *xiaozhiUI_xiaozhiUI_weather;
	lv_obj_t *xiaozhiUI_xiaozhiUI_weather_label;
	lv_obj_t *xiaozhiUI_WIFI_NC;
	lv_obj_t *xiaozhiUI_WIFI_C;
	lv_obj_t *xiaozhiUI_battery;
	lv_obj_t *xiaozhiUI_datetext;
	lv_obj_t *xiaozhiUI_BLE_C;
	lv_obj_t *xiaozhiUI_BLE_NC;
	lv_obj_t *xiaozhiUI_xiaozhi_connection;
	lv_obj_t *xiaozhiUI_battery_txt;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_xiaozhiUI(lv_ui *ui);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_0);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_1);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_10);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_11);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_12);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_13);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_14);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_15);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_16);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_17);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_18);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_19);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_20);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_21);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_22);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_23);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_24);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_25);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_26);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_27);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_28);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_29);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_30);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_31);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_32);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_33);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_34);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_35);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_36);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_37);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_38);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_39);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_40);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_41);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_42);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_43);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_5);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_6);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_7);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_8);
LV_IMG_DECLARE(xiaozhiUI_xiaozhiUI_bgpreview6_9);
LV_IMG_DECLARE(_WiFi_N_alpha_32x32);
LV_IMG_DECLARE(_WiFi_Y_alpha_32x32);
LV_IMG_DECLARE(_bluetooth1_alpha_32x32);
LV_IMG_DECLARE(_bluetooth2_alpha_32x32);

LV_FONT_DECLARE(lv_font_AlexBrush_Regular_70)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_ArchitectsDaughter_15)
LV_FONT_DECLARE(lv_font_AlexBrush_Regular_20)
LV_FONT_DECLARE(lv_font_montserratMedium_7)


#ifdef __cplusplus
}
#endif
#endif
