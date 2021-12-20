/*
 * PROJECT:   LVGL ported to Windows Desktop
 * FILE:      LVGL.Windows.Desktop.cpp
 * PURPOSE:   Implementation for LVGL ported to Windows Desktop
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */
#ifndef LINUX
#include <Windows.h>

#include "resource.h"
#endif

#include "App.h"
#include "Common/HAL/HAL.h"

#include <stdio.h>

#ifndef LINUX
#if _MSC_VER >= 1200
 // Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable:4244)
#endif
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#ifndef LINUX
#include "lv_drivers/win32drv/win32drv.h"
#else
#include "lv_drivers/display/fbdev.h"
#endif
#include "lv_fs_if/lv_fs_if.h"

#ifndef LINUX
#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif
#endif

#ifdef LINUX
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

static bool g_mouse_pressed = false;
static int g_mouse_value = 0;
static bool g_keyboard_pressed = false;
static int g_keyboard_value = 0;
static bool g_mousewheel_pressed = false;
static int  g_mousewheel_value = 0;


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

static void lv_mouse_driver_read_callback(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{
    data->state = (lv_indev_state_t)(
        g_mouse_pressed ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);
    data->point.x = g_mouse_value;
    data->point.y = g_mouse_value;
}

static void lv_keyboard_driver_read_callback(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{
    data->state = (lv_indev_state_t)(
        g_keyboard_pressed ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);
    data->key = 0;
}

static void lv_mousewheel_driver_read_callback(
    lv_indev_drv_t* indev_drv,
    lv_indev_data_t* data)
{
    data->state = (lv_indev_state_t)(
        g_mousewheel_pressed ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);
    data->enc_diff = g_mousewheel_value;
    g_mousewheel_value = 0;
}

static void lv_display_init(void)
{
    /*Linux frame buffer device init*/
    fbdev_init();

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t draw_buf;
    lv_disp_draw_buf_init(&draw_buf, 
        (lv_color_t*)malloc(DISP_HOR_RES * DISP_VER_RES * sizeof(lv_color_t)),
        NULL,
        DISP_HOR_RES * DISP_VER_RES * sizeof(lv_color_t));

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = DISP_HOR_RES;
    disp_drv.ver_res = DISP_VER_RES;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = lv_mouse_driver_read_callback;
    lv_indev_drv_register(&indev_drv);

    static lv_indev_drv_t kb_drv;
    lv_indev_drv_init(&kb_drv);
    kb_drv.type = LV_INDEV_TYPE_KEYPAD;
    kb_drv.read_cb = lv_keyboard_driver_read_callback;
    lv_indev_drv_register(&kb_drv);

    static lv_indev_drv_t enc_drv;
    lv_indev_drv_init(&enc_drv);
    enc_drv.type = LV_INDEV_TYPE_ENCODER;
    enc_drv.read_cb = lv_mousewheel_driver_read_callback;
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
#endif

int main()
{
    lv_init();

    lv_fs_if_init();

#ifndef LINUX // Windows
    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        240,
        240,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return -1;
    }
    
    HAL::HAL_Init();

    App_Init();

    while (!lv_win32_quit_signal)
    {
        lv_timer_handler();
        HAL::HAL_Update();
        Sleep(1);
    }

    App_Uninit();

#else // LINUX

    /* Display init */
    lv_display_init();

    HAL::HAL_Init();

    App_Init();

    while (1)
    {
        lv_task_handler();
        HAL::HAL_Update();
        lv_usleep(5 * 1000);
        lv_tick_inc(5000);
    }

    App_Uninit();
#endif

    return 0;
}
