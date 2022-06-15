/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
	static lv_style_t style_screen_main_main_default;
	lv_style_reset(&style_screen_main_main_default);
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main_main_default, 0);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img2
	ui->screen_img2 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img2, 400, 220);
	lv_obj_set_size(ui->screen_img2, 224, 174);

	//Write style state: LV_STATE_DEFAULT for style_screen_img2_main_main_default
	static lv_style_t style_screen_img2_main_main_default;
	lv_style_reset(&style_screen_img2_main_main_default);
	lv_style_set_img_recolor(&style_screen_img2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img2_main_main_default, 125);
	lv_obj_add_style(ui->screen_img2, &style_screen_img2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img2,&_scan_example_224x174);
	lv_img_set_pivot(ui->screen_img2, 0,0);
	lv_img_set_angle(ui->screen_img2, 0);

	//Write codes screen_slider0
	ui->screen_slider0 = lv_slider_create(ui->screen);
	lv_obj_set_pos(ui->screen_slider0, 421, 462);
	lv_obj_set_size(ui->screen_slider0, 160, 10);

	//Write style state: LV_STATE_DEFAULT for style_screen_slider0_main_main_default
	static lv_style_t style_screen_slider0_main_main_default;
	lv_style_reset(&style_screen_slider0_main_main_default);
	lv_style_set_radius(&style_screen_slider0_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_slider0_main_main_default, lv_color_make(0xc4, 0xcf, 0xcf));
	lv_style_set_bg_grad_color(&style_screen_slider0_main_main_default, lv_color_make(0xc1, 0xcc, 0xcd));
	lv_style_set_bg_grad_dir(&style_screen_slider0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_slider0_main_main_default, 255);
	lv_style_set_outline_color(&style_screen_slider0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_screen_slider0_main_main_default, 0);
	lv_style_set_outline_opa(&style_screen_slider0_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_slider0_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_slider0_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_slider0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_slider0_main_main_default, 0);
	lv_obj_add_style(ui->screen_slider0, &style_screen_slider0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_slider0_main_indicator_default
	static lv_style_t style_screen_slider0_main_indicator_default;
	lv_style_reset(&style_screen_slider0_main_indicator_default);
	lv_style_set_radius(&style_screen_slider0_main_indicator_default, 50);
	lv_style_set_bg_color(&style_screen_slider0_main_indicator_default, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_slider0_main_indicator_default, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_slider0_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_slider0_main_indicator_default, 255);
	lv_obj_add_style(ui->screen_slider0, &style_screen_slider0_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_slider0_main_knob_default
	static lv_style_t style_screen_slider0_main_knob_default;
	lv_style_reset(&style_screen_slider0_main_knob_default);
	lv_style_set_radius(&style_screen_slider0_main_knob_default, 50);
	lv_style_set_bg_color(&style_screen_slider0_main_knob_default, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_slider0_main_knob_default, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_slider0_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_slider0_main_knob_default, 255);
	lv_obj_add_style(ui->screen_slider0, &style_screen_slider0_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->screen_slider0,0, 100);
	lv_slider_set_value(ui->screen_slider0,50,false);

	//Write codes screen_label3
	ui->screen_label3 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label3, 412, 490);
	lv_obj_set_size(ui->screen_label3, 200, 50);
	lv_label_set_text(ui->screen_label3, "Please slide");
	lv_label_set_long_mode(ui->screen_label3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_label3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_label3_main_main_default
	static lv_style_t style_screen_label3_main_main_default;
	lv_style_reset(&style_screen_label3_main_main_default);
	lv_style_set_radius(&style_screen_label3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label3_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_screen_label3_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_label3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label3_main_main_default, 0);
	lv_obj_add_style(ui->screen_label3, &style_screen_label3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label4
	ui->screen_label4 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label4, 462, 396);
	lv_obj_set_size(ui->screen_label4, 100, 80);
	lv_label_set_text(ui->screen_label4, "50");
	lv_label_set_long_mode(ui->screen_label4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_label4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_label4_main_main_default
	static lv_style_t style_screen_label4_main_main_default;
	lv_style_reset(&style_screen_label4_main_main_default);
	lv_style_set_radius(&style_screen_label4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label4_main_main_default, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen_label4_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_label4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label4_main_main_default, 0);
	lv_obj_add_style(ui->screen_label4, &style_screen_label4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img_1, 262, 40);
	lv_obj_set_size(ui->screen_img_1, 500, 150);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_1_main_main_default
	static lv_style_t style_screen_img_1_main_main_default;
	lv_style_reset(&style_screen_img_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_1, &style_screen_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1,&_bootlogo_500x150);
	lv_img_set_pivot(ui->screen_img_1, 0,0);
	lv_img_set_angle(ui->screen_img_1, 0);

	//Init events for screen
	events_init_screen(ui);
}