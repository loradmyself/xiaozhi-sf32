#ifndef _XIAOZHI_UI_H_
#define _XIAOZHI_UI_H_

#include "lv_image_dsc.h"
#include "lv_timer.h"
#include "lv_display.h"
#include "lv_obj_pos.h"


#ifdef __cplusplus
extern "C" {
#endif

void xiaozhi_ui_update_ble(char *string); // ble
void xiaozhi_ui_update_emoji(char *string);
void xiaozhi_ui_chat_status(char *string);
void xiaozhi_ui_chat_output(char *string);
void xiaozhi_ui_standby_chat_output(char *string);
void ui_swith_to_standby_screen(void);
void ui_switch_to_xiaozhi_screen(void);
void xiaozhi_ui_task(void *args);
void ui_sleep_callback(lv_timer_t *timer);
void ui_switch_to_xiaozhi_screen(void);
void xiaozhi_ui_tts_output(char *string);
void xiaozhi_ui_update_standby_emoji(char *string);
void show_shutdown(void);
void show_sleep_countdown_and_sleep(void);
void xiaozhi_ui_update_charge_status(uint8_t is_charging);
float get_scale_factor(void);

extern const lv_image_dsc_t * cool[60];
extern const lv_image_dsc_t * user_ui_bg[25];

extern const lv_image_dsc_t cool_1;
extern const lv_image_dsc_t cool_2;
extern const lv_image_dsc_t cool_3;
extern const lv_image_dsc_t cool_4;
extern const lv_image_dsc_t cool_5;
extern const lv_image_dsc_t cool_6;
extern const lv_image_dsc_t cool_7;
extern const lv_image_dsc_t cool_8;
extern const lv_image_dsc_t cool_9;
extern const lv_image_dsc_t cool_10;
extern const lv_image_dsc_t cool_11;
extern const lv_image_dsc_t cool_12;
extern const lv_image_dsc_t cool_13;
extern const lv_image_dsc_t cool_14;
extern const lv_image_dsc_t cool_15;
extern const lv_image_dsc_t cool_16;
extern const lv_image_dsc_t cool_17;
extern const lv_image_dsc_t cool_18;
extern const lv_image_dsc_t cool_19;
extern const lv_image_dsc_t cool_20;
extern const lv_image_dsc_t cool_21;
extern const lv_image_dsc_t cool_22;
extern const lv_image_dsc_t cool_23;
extern const lv_image_dsc_t cool_24;
extern const lv_image_dsc_t cool_25;
extern const lv_image_dsc_t cool_26;
extern const lv_image_dsc_t cool_27;
extern const lv_image_dsc_t cool_28;
extern const lv_image_dsc_t cool_29;
extern const lv_image_dsc_t cool_30;
extern const lv_image_dsc_t cool_31;
extern const lv_image_dsc_t cool_32;
extern const lv_image_dsc_t cool_33;
extern const lv_image_dsc_t cool_34;
extern const lv_image_dsc_t cool_35;
extern const lv_image_dsc_t cool_36;
extern const lv_image_dsc_t cool_37;
extern const lv_image_dsc_t cool_38;
extern const lv_image_dsc_t cool_39;
extern const lv_image_dsc_t cool_40;
extern const lv_image_dsc_t cool_41;
extern const lv_image_dsc_t cool_42;
extern const lv_image_dsc_t cool_43;
extern const lv_image_dsc_t cool_44;
extern const lv_image_dsc_t cool_45;
extern const lv_image_dsc_t cool_46;
extern const lv_image_dsc_t cool_47;
extern const lv_image_dsc_t cool_48;
extern const lv_image_dsc_t cool_49;
extern const lv_image_dsc_t cool_50;
extern const lv_image_dsc_t cool_51;
extern const lv_image_dsc_t cool_52;
extern const lv_image_dsc_t cool_53;
extern const lv_image_dsc_t cool_54;
extern const lv_image_dsc_t cool_55;







extern const lv_image_dsc_t user_ui_bg_1;
extern const lv_image_dsc_t user_ui_bg_2;
extern const lv_image_dsc_t user_ui_bg_3;
extern const lv_image_dsc_t user_ui_bg_4;
extern const lv_image_dsc_t user_ui_bg_5;
extern const lv_image_dsc_t user_ui_bg_6;
extern const lv_image_dsc_t user_ui_bg_7;
extern const lv_image_dsc_t user_ui_bg_8;
extern const lv_image_dsc_t user_ui_bg_9;
extern const lv_image_dsc_t user_ui_bg_10;
extern const lv_image_dsc_t user_ui_bg_11;
extern const lv_image_dsc_t user_ui_bg_12;
extern const lv_image_dsc_t user_ui_bg_13;
extern const lv_image_dsc_t user_ui_bg_14;
extern const lv_image_dsc_t user_ui_bg_15;
extern const lv_image_dsc_t user_ui_bg_16;
extern const lv_image_dsc_t user_ui_bg_17;
extern const lv_image_dsc_t user_ui_bg_18;
extern const lv_image_dsc_t user_ui_bg_19;
extern const lv_image_dsc_t user_ui_bg_20;
extern const lv_image_dsc_t user_ui_bg_21;
extern const lv_image_dsc_t user_ui_bg_22;
extern const lv_image_dsc_t user_ui_bg_23;
extern const lv_image_dsc_t user_ui_bg_24;
extern const lv_image_dsc_t user_ui_bg_25;



#ifdef __cplusplus
}
#endif

#endif // _XIAOZHI_UI_H_