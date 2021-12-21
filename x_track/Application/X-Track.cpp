/*
 * PROJECT:   LVGL ported to Linux
 * FILE:      X-Track.cpp
 * PURPOSE:   Implementation for LVGL ported to Linux
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: AlgoIdeas
 */

#include "App.h"
#include "Common/HAL/HAL.h"

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_fs_if/lv_fs_if.h"
#include "lv_drivers/display/fbdev.h"


static bool g_keyboard_pressed = false;
static int g_keyboard_value = 0;


// uint32_t custom_tick_get(void)
// {
//     static uint32_t basic_ms = 0;
//     uint32_t ms = 0;
//     struct timespec monotonic_time;

//     memset(&monotonic_time, 0, sizeof(struct timespec));
//     if (basic_ms == 0)
//     {
//         clock_gettime(CLOCK_MONOTONIC, &monotonic_time);
//         basic_ms = monotonic_time.tv_sec * 1000 + monotonic_time.tv_nsec/1000000;
//     }

//     clock_gettime(CLOCK_MONOTONIC, &monotonic_time);
//     ms = monotonic_time.tv_sec * 1000 + monotonic_time.tv_nsec/1000000;

//     return (ms - basic_ms);
// }

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
    static bool lastState;
    data->enc_diff = HAL::Encoder_GetDiff();

    bool isPush = HAL::Encoder_GetIsPush();
    
    data->state = isPush ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;

    if (isPush != lastState)
    {
        HAL::Buzz_Tone(isPush ? 500 : 700, 20);
        lastState = isPush;
    }
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

static int lv_usleep(unsigned int usec)
{
    int ret;
    struct timespec requst;
    struct timespec remain;
    remain.tv_sec = usec / 1000000;
    remain.tv_nsec = (usec % 1000000) * 1000;
    do {
        requst = remain;
        ret = nanosleep(&requst, &remain);
    } while (-1 == ret && errno == EINTR);
    return ret;
}

// int main()
// {
//     lv_init();

//     lv_fs_if_init();

//     HAL::HAL_Init();

//     /* Display init */
//     lv_display_init();

//     App_Init();

//     while (1)
//     {
//         lv_task_handler();
//         HAL::HAL_Update();
//         lv_usleep(5 * 1000);
//         lv_tick_inc(5000);
//     }

//     App_Uninit();

//     return 0;
// }
