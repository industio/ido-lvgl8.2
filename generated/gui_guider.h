/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_img2;
	lv_obj_t *screen_slider0;
	lv_obj_t *screen_label3;
	lv_obj_t *screen_label4;
	lv_obj_t *screen_img_1;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_scan_example_224x174);
LV_IMG_DECLARE(_bootlogo_500x150);

#ifdef __cplusplus
}
#endif
#endif