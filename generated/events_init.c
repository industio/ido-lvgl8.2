/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"


void events_init(lv_ui *ui)
{
}

static void screen_slider0_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		static char buf[4];
		int slider_value = lv_slider_get_value(guider_ui.screen_slider0);
		lv_obj_set_style_img_opa(guider_ui.screen_img2, slider_value * 2.5, LV_STATE_DEFAULT);
		snprintf(buf, 4, "%u" , slider_value);
		lv_label_set_text(guider_ui.screen_label4, buf);
	}
		break;
	default:
		break;
	}
}

void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_slider0, screen_slider0_event_handler, LV_EVENT_ALL, NULL);
}
