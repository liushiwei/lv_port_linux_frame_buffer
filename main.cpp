#include "lvgl/lvgl.h"
#include <stdlib.h>
#include "lv_drivers/display/fbdev.h"
#include "lv_demos/lv_demo.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include "lv_drivers/indev/evdev.h"
#include "App.h"
#include "lv_fs_if/lv_fs_if.h"
#define DISP_BUF_SIZE (128 * 1024)


static bool g_keyboard_pressed = false;
static int g_keyboard_value = 0;

static void lv_keyboard_driver_read_callback(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{
    data->state = (lv_indev_state_t)(
        g_keyboard_pressed ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);
    data->key = g_keyboard_value;
}

static void lv_lencoder_driver_read_callback(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{
    // static bool lastState;
    // data->enc_diff = HAL::Encoder_GetDiff();

    // bool isPush = HAL::Encoder_GetIsPush();
    
    // data->state = isPush ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;

    // if (isPush != lastState)
    // {
    //     HAL::Buzz_Tone(isPush ? 500 : 700, 20);
    //     lastState = isPush;
    // }
}

static void lv_display_init(void)
{
    /*Linux frame buffer device init*/
    fbdev_init();

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t draw_buf;
    lv_disp_draw_buf_init(&draw_buf, 
        (lv_color_t*)malloc(DISP_HOR_RES * DISP_VER_RES * sizeof(lv_color_t)),
        (lv_color_t*)malloc(DISP_HOR_RES * DISP_VER_RES * sizeof(lv_color_t)),
        DISP_HOR_RES * DISP_VER_RES * sizeof(lv_color_t));

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = DISP_HOR_RES;
    disp_drv.ver_res = DISP_VER_RES;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // /* Add the mouse (or touchpad) as input device
    // * Use the 'mouse' driver which reads the PC's mouse*/
    evdev_init();
    evdev_set_file("/dev/input/event2");
    /* Set up touchpad input device interface */
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = evdev_read;
    lv_indev_t *indev = lv_indev_drv_register(&indev_drv);

    static lv_indev_drv_t kb_drv;
    lv_indev_drv_init(&kb_drv);
    kb_drv.type = LV_INDEV_TYPE_KEYPAD;
    kb_drv.read_cb = lv_keyboard_driver_read_callback;
    lv_indev_drv_register(&kb_drv);

    static lv_indev_drv_t enc_drv;
    lv_indev_drv_init(&enc_drv);
    enc_drv.type = LV_INDEV_TYPE_ENCODER;
    enc_drv.read_cb = lv_lencoder_driver_read_callback;
    lv_indev_drv_register(&enc_drv);
}

int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    // fbdev_init();
    

    // evdev_init();
    
    // /*A small buffer for LittlevGL to draw the screen's content*/
    // static lv_color_t buf[DISP_BUF_SIZE];

    // /*Initialize a descriptor for the buffer*/
    // static lv_disp_draw_buf_t disp_buf;
    // lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    // /*Initialize and register a display driver*/
    // static lv_disp_drv_t disp_drv;
    // lv_disp_drv_init(&disp_drv);
    // disp_drv.draw_buf   = &disp_buf;
    // disp_drv.flush_cb   = fbdev_flush;
    // disp_drv.hor_res    = 320;
    // disp_drv.ver_res    = 240;
    // lv_disp_drv_register(&disp_drv);


    // /* Add the mouse (or touchpad) as input device
    // * Use the 'mouse' driver which reads the PC's mouse*/
    // evdev_init();
    // evdev_set_file("/dev/input/event2");
    // /* Set up touchpad input device interface */
    // lv_indev_drv_t indev_drv;
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = evdev_read;
    // lv_indev_t *indev = lv_indev_drv_register(&indev_drv);

    //lv_obj_t *cursor_img = lv_img_create(lv_scr_act());
    //lv_img_set_src(cursor_img, LV_SYMBOL_OK);
    //lv_indev_set_cursor(indev, cursor_img);
    /*Create a Demo*/
    // lv_demo_widgets();
    // lv_demo_music();
    /*Handle LitlevGL tasks (tickless mode)*/
    lv_fs_if_init();
    lv_display_init();
    // DataProc_Init();
    App_Init();
    while(1) {
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
