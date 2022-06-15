#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include "generated/gui_guider.h"

static lv_obj_t *label;

static lv_color_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX];
static lv_disp_draw_buf_t  disp_buf;

lv_disp_drv_t disp_drv;

lv_disp_t *disp;

lv_ui guider_ui;

#define DEMO_MUSIC 0

int main(int argc, char **argv)
{
	lv_init(); 

	fbdev_init();

	lv_disp_draw_buf_init(&disp_buf, buf, NULL, (LV_HOR_RES_MAX * LV_VER_RES_MAX));

	lv_disp_drv_init(&disp_drv);
	disp_drv.draw_buf = &disp_buf;
	disp_drv.flush_cb = fbdev_flush;
	disp_drv.hor_res = LV_HOR_RES_MAX;
	disp_drv.ver_res = LV_VER_RES_MAX;     
	disp = lv_disp_drv_register(&disp_drv);

	lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
	evdev_init();
	indev_drv.type = LV_INDEV_TYPE_POINTER; /*See below.*/
	indev_drv.read_cb = evdev_read;            /*See below.*/
	lv_indev_drv_register(&indev_drv);      /*Register the driver in LittlevGL*/

#if DEMO_MUSIC
	lv_demo_music();
#else
	/* jump to generated/gui_guider->setup_ui() */
	setup_ui(&guider_ui);
	events_init(&guider_ui);
#endif
	while(1)
	{
		lv_task_handler();
		usleep(5000);
	}
}
