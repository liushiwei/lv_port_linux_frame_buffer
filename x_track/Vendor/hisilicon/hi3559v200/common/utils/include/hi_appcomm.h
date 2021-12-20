/**
* @file    hi_appcomm.h
* @brief   application common header.
*
* Copyright (c) 2017 Huawei Tech.Co.,Ltd
*
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
* @version   1.0

 */
#ifndef __HI_APPCOMM_H__
#define __HI_APPCOMM_H__

#include <stdlib.h>
#include <time.h>
#include "hi_appcomm_log.h"
#include "hi_appcomm_errno.h"
#include "hi_appcomm_util.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/** \addtogroup     APPCOMM */
/** @{ *//** <!-- [APPCOMM] */

/** Invalid FD */
#define HI_APPCOMM_FD_INVALID_VAL (-1)

/** General String Length */
#define HI_APPCOMM_COMM_STR_LEN (64)

/** Path Maximum Length */
#define HI_APPCOMM_MAX_PATH_LEN (64)

/** FileName Maximum Length */
#define HI_APPCOMM_MAX_FILENAME_LEN (64)

/** Appfs Root Path */
#define HI_APPFS_PATH "/app"
/** Appfs Komod Path */
#define HI_APPFS_KOMOD_PATH HI_APPFS_PATH "/komod"
/** Appfs lib Path */
#define HI_APP_LIB_PATH HI_APPFS_PATH "/lib"
/** Sharefs Root Path */
#define HI_SHAREFS_ROOT_PATH HI_APPFS_PATH "/sharefs"

/** Pointer Check */
#define HI_APPCOMM_CHECK_POINTER(p, errcode)    \
    do {                                        \
        if (!(p)) {                             \
            MLOGE("pointer[%s] is NULL\n", #p); \
            return errcode;                     \
        }                                       \
    } while (0)

/** Expression Check */
#define HI_APPCOMM_CHECK_EXPR(expr, errcode)  \
    do {                                      \
        if (!(expr)) {                        \
            MLOGE("expr[%s] false\n", #expr); \
            return errcode;                   \
        }                                     \
    } while (0)

/** Expression Check With ErrInformation */
#define HI_APPCOMM_CHECK_EXPR_WITH_ERRINFO(expr, errcode, errstring) \
    do {                                                             \
        if (!(expr)) {                                               \
            MLOGE("[%s] failed\n", errstring);                       \
            return errcode;                                          \
        }                                                            \
    } while (0)

/** Return Result Check */
#define HI_APPCOMM_CHECK_RETURN(ret, errcode)       \
    do {                                            \
        if (HI_SUCCESS != ret) {                    \
            MLOGE("Error Code: [0x%08X]\n\n", ret); \
            return errcode;                         \
        }                                           \
    } while (0)

/** Return Result Check With ErrInformation */
#define HI_APPCOMM_CHECK_RETURN_WITH_ERRINFO(ret, errcode, errstring) \
    do {                                                              \
        if (HI_SUCCESS != ret) {                                      \
            MLOGE("[%s] failed[0x%08X]\n", errstring, ret);           \
            return errcode;                                           \
        }                                                             \
    } while (0)

/** Expression Check Without Return */
#define HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN(expr, errstring) \
    do {                                                      \
        if (!(expr)) {                                        \
            MLOGE("[%s] failed\n", errstring);                \
        }                                                     \
    } while (0)

/** Range Check */
#define HI_APPCOMM_CHECK_RANGE(value, min, max) (((value) <= (max) && (value) >= (min)) ? 1 : 0)

/** Memory Safe Free */
#define HI_APPCOMM_SAFE_FREE(p) \
    do {                        \
        if (NULL != (p)) {      \
            free(p);            \
            (p) = NULL;         \
        }                       \
    } while (0)

/** Value Align */
#define HI_APPCOMM_ALIGN(value, base) (((value) + (base)-1) / (base) * (base))

/** strcmp enum string and value */
#define HI_APPCOMM_STRCMP_ENUM(enumStr, enumValue) strncmp(enumStr, #enumValue, HI_APPCOMM_COMM_STR_LEN)

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

#ifndef MAX
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#endif

#ifndef MIN
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#endif

#ifndef SWAP
#define SWAP(a, b) (a = (a) + (b), b = (a) - (b), a = (a) - (b))
#endif

/** Mutex Lock */
#define HI_MUTEX_INIT_LOCK(mutex)                   \
    do {                                            \
        (HI_VOID)pthread_mutex_init(&mutex, NULL); \
    } while (0)
#define HI_MUTEX_LOCK(mutex)                  \
    do {                                      \
        (HI_VOID)pthread_mutex_lock(&mutex); \
    } while (0)
#define HI_MUTEX_UNLOCK(mutex)                  \
    do {                                        \
        (HI_VOID)pthread_mutex_unlock(&mutex); \
    } while (0)
#define HI_MUTEX_DESTROY(mutex)                  \
    do {                                         \
        (HI_VOID)pthread_mutex_destroy(&mutex); \
    } while (0)

/** Cond */
#ifndef __HuaweiLite__
#define HI_COND_INIT(cond)                                               \
    do {                                                                 \
        pthread_condattr_t condattr;                                     \
        (HI_VOID)pthread_condattr_init(&condattr);                      \
        (HI_VOID)pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC); \
        (HI_VOID)pthread_cond_init(&cond, &condattr);                   \
        (HI_VOID)pthread_condattr_destroy(&condattr);                   \
    } while (0)
#define HI_COND_TIMEDWAIT(cond, mutex, usec)                  \
    do {                                                      \
        struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };   \
        (HI_VOID)clock_gettime(CLOCK_MONOTONIC, &ts);        \
        ts.tv_sec += (usec / 1000000LL);                      \
        ts.tv_nsec += (usec * 1000LL % 1000000000LL);         \
        (HI_VOID)pthread_cond_timedwait(&cond, &mutex, &ts); \
    } while (0)
#define HI_COND_TIMEDWAIT_WITH_RETURN(cond, mutex, usec, ret) \
    do {                                                      \
        struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };   \
        (HI_VOID)clock_gettime(CLOCK_MONOTONIC, &ts);        \
        ts.tv_sec += (usec / 1000000LL);                      \
        ts.tv_nsec += (usec * 1000LL % 1000000000LL);         \
        ret = pthread_cond_timedwait(&cond, &mutex, &ts);     \
    } while (0)
#else
#define HI_COND_INIT(cond)                        \
    do {                                          \
        (HI_VOID)pthread_cond_init(&cond, NULL); \
    } while (0)
#define HI_COND_TIMEDWAIT(cond, mutex, usec)                  \
    do {                                                      \
        struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };   \
        ts.tv_sec += (usec / 1000000LL);                      \
        ts.tv_nsec += (usec * 1000LL % 1000000000LL);         \
        (HI_VOID)pthread_cond_timedwait(&cond, &mutex, &ts); \
    } while (0)
#define HI_COND_TIMEDWAIT_WITH_RETURN(cond, mutex, usec, ret) \
    do {                                                      \
        struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };   \
        ts.tv_sec += (usec / 1000000LL);                      \
        ts.tv_nsec += (usec * 1000LL % 1000000000LL);         \
        ret = pthread_cond_timedwait(&cond, &mutex, &ts);     \
    } while (0)
#endif
#define HI_COND_WAIT(cond, mutex)                   \
    do {                                            \
        (HI_VOID)pthread_cond_wait(&cond, &mutex); \
    } while (0)
#define HI_COND_SIGNAL(cond)                  \
    do {                                      \
        (HI_VOID)pthread_cond_signal(&cond); \
    } while (0)
#define HI_COND_DESTROY(cond)                  \
    do {                                       \
        (HI_VOID)pthread_cond_destroy(&cond); \
    } while (0)

/** App Event BaseId : [28bit~31bit] unique */
#define HI_APPCOMM_EVENT_BASEID (0x10000000L)

/** App Event ID Rule [ --base[4bit]--|--module[8bit]--|--event[20bit]--]
    * module : module enum value [HI_APP_MOD_E]
    * event_code : event code in specified module, unique in module
 */
#define HI_APPCOMM_EVENT_ID(module, event) \
    ((HI_S32)((HI_APPCOMM_EVENT_BASEID) | ((module) << 20) | (event)))

/** App Error BaseId : [28bit~31bit] unique */
#define HI_APPCOMM_ERR_BASEID (0x80000000L)

/** App Error Code Rule [ --base[4bit]--|--module[8bit]--|--error[20bit]--]
    * module : module enum value [HI_APP_MOD_E]
    * event_code : event code in specified module, unique in module
 */
#define HI_APPCOMM_ERR_ID(module, err) \
    ((HI_S32)((HI_APPCOMM_ERR_BASEID) | ((module) << 20) | (err)))

/** App Module ID */
typedef enum hiAPP_MOD_E {
    HI_APP_MOD_MEDIA = 0,
    HI_APP_MOD_RECMNG,
    HI_APP_MOD_PHOTOMNG,
    HI_APP_MOD_FILEMNG,
    HI_APP_MOD_PLAYBACK,
    HI_APP_MOD_LIVESVR,
    HI_APP_MOD_USBMNG,
    HI_APP_MOD_STORAGEMNG,
    HI_APP_MOD_KEYMNG,
    HI_APP_MOD_GAUGEMNG,
    HI_APP_MOD_GSENSORMNG,
    HI_APP_MOD_LEDMNG,
    HI_APP_MOD_AHDMNG,
    HI_APP_MOD_SCENE,
    HI_APP_MOD_WEBSRV,
    HI_APP_MOD_CONFACCESS,
    HI_APP_MOD_HAL,
    HI_APP_MOD_PM,
    HI_APP_MOD_SYSTEM,
    HI_APP_MOD_RAWCAP,
    HI_APP_MOD_UPGRADE,
    HI_APP_MOD_OSD,
    HI_APP_MOD_VIDEODETECT,
    HI_APP_MOD_VGS_DRAW_RECT,
    HI_APP_MOD_VO_BIND_VPSS,

    HI_APP_MOD_STATEMNG,
    HI_APP_MOD_PARAM,
    HI_APP_MOD_NETCTRL,
    HI_APP_MOD_UI,
    HI_APP_MOD_GPSMNG,
    HI_APP_MOD_ACCMNG,
    HI_APP_MOD_FACEDETECT,
    HI_APP_MOD_SOUND,
    HI_APP_MOD_USBCTRL,
    HI_APP_MOD_ALGADAPTER_ADAS,
    HI_APP_MOD_VIDEOANALYSIS_ADAS,
    HI_APP_MOD_VIDEOPROCESS,
    HI_APP_MOD_BUTT
} HI_APP_MOD_E;

#define PDT_UI_VOICE_MAX_NUM                (39)
#define PDT_UI_VOICE_SD_NO_EXIST_IDX        (0)
#define PDT_UI_VOICE_SD_NO_EXIST_SRC        "/app/bin/res/voice/sd_no_exist.m4a"
#define PDT_UI_VOICE_EMR_START_IDX          (1)
#define PDT_UI_VOICE_EMR_START_SRC          "/app/bin/res/voice/emr_start.m4a"
#define PDT_UI_VOICE_WIFI_IDX               (2)
#define PDT_UI_VOICE_WIFI_SRC               "/app/bin/res/voice/wifi.m4a"
#define PDT_UI_VOICE_OPEN_IDX               (3)
#define PDT_UI_VOICE_OPEN_SRC               "/app/bin/res/voice/open.m4a"
#define PDT_UI_VOICE_CLOSE_IDX              (4)
#define PDT_UI_VOICE_CLOSE_SRC              "/app/bin/res/voice/close.m4a"
#define PDT_UI_VOICE_LOW_LEVEL_IDX          (5)
#define PDT_UI_VOICE_LOW_LEVEL_SRC          "/app/bin/res/voice/low_level.m4a"
#define PDT_UI_VOICE_INNER_LOW_LEVEL_IDX    (6)
#define PDT_UI_VOICE_INNER_LOW_LEVEL_SRC    "/app/bin/res/voice/inner_low_level.m4a"
#define PDT_UI_VOICE_DINGDONG_IDX           (7)
#define PDT_UI_VOICE_DINGDONG_SRC           "/app/bin/res/voice/dingdong.m4a"
#define PDT_UI_VOICE_NOWTIME_IDX            (8)
#define PDT_UI_VOICE_NOWTIME_SRC            "/app/bin/res/voice/nowtime.m4a"
#define PDT_UI_VOICE_SPOT_IDX               (9)
#define PDT_UI_VOICE_SPOT_SRC               "/app/bin/res/voice/Spot.m4a"
#define PDT_UI_VOICE_0_IDX                  (10)
#define PDT_UI_VOICE_0_SRC                  "/app/bin/res/voice/0dot.m4a"
#define PDT_UI_VOICE_1_IDX                  (11)
#define PDT_UI_VOICE_1_SRC                  "/app/bin/res/voice/1dot.m4a"
#define PDT_UI_VOICE_2_IDX                  (12)
#define PDT_UI_VOICE_2_SRC                  "/app/bin/res/voice/2dot.m4a"
#define PDT_UI_VOICE_3_IDX                  (13)
#define PDT_UI_VOICE_3_SRC                  "/app/bin/res/voice/3dot.m4a"
#define PDT_UI_VOICE_4_IDX                  (14)
#define PDT_UI_VOICE_4_SRC                  "/app/bin/res/voice/4dot.m4a"
#define PDT_UI_VOICE_5_IDX                  (15)
#define PDT_UI_VOICE_5_SRC                  "/app/bin/res/voice/5dot.m4a"
#define PDT_UI_VOICE_6_IDX                  (16)
#define PDT_UI_VOICE_6_SRC                  "/app/bin/res/voice/6dot.m4a"
#define PDT_UI_VOICE_7_IDX                  (17)
#define PDT_UI_VOICE_7_SRC                  "/app/bin/res/voice/7dot.m4a"
#define PDT_UI_VOICE_8_IDX                  (18)
#define PDT_UI_VOICE_8_SRC                  "/app/bin/res/voice/8dot.m4a"
#define PDT_UI_VOICE_9_IDX                  (19)
#define PDT_UI_VOICE_9_SRC                  "/app/bin/res/voice/9dot.m4a"
#define PDT_UI_VOICE_10_IDX                 (20)
#define PDT_UI_VOICE_10_SRC                 "/app/bin/res/voice/10dot.m4a"
#define PDT_UI_VOICE_11_IDX                 (21)
#define PDT_UI_VOICE_11_SRC                 "/app/bin/res/voice/11dot.m4a"
#define PDT_UI_VOICE_12_IDX                 (22)
#define PDT_UI_VOICE_12_SRC                 "/app/bin/res/voice/12dot.m4a"

#define PDT_UI_VOICE_AM_IDX                 (23)
#define PDT_UI_VOICE_AM_SRC                 "/app/bin/res/voice/Am.m4a"
#define PDT_UI_VOICE_PM_IDX                 (24)
#define PDT_UI_VOICE_PM_SRC                 "/app/bin/res/voice/Pm.m4a"
#define PDT_UI_VOICE_NOON_IDX               (25)
#define PDT_UI_VOICE_NOON_SRC               "/app/bin/res/voice/noon.m4a"
#define PDT_UI_VOICE_NIGHT_IDX              (26)
#define PDT_UI_VOICE_NIGHT_SRC              "/app/bin/res/voice/night.m4a"
#define PDT_UI_VOICE_SOS_IDX                (27)
#define PDT_UI_VOICE_SOS_SRC                "/app/bin/res/voice/SOS.m4a"
#define PDT_UI_VOICE_DI_IDX                 (28)
#define PDT_UI_VOICE_DI_SRC                 "/app/bin/res/voice/Di.m4a"
#define PDT_UI_VOICE_REC_START_IDX          (29)
#define PDT_UI_VOICE_REC_START_SRC          "/app/bin/res/voice/rec_start.m4a"
#define PDT_UI_VOICE_REC_STOP_IDX           (30)
#define PDT_UI_VOICE_REC_STOP_SRC           "/app/bin/res/voice/rec_stop.m4a"
#define PDT_UI_VOICE_AUDIO_START_IDX        (31)
#define PDT_UI_VOICE_AUDIO_START_SRC        "/app/bin/res/voice/audio_start.m4a"
#define PDT_UI_VOICE_AUDIO_STOP_IDX         (32)
#define PDT_UI_VOICE_AUDIO_STOP_SRC         "/app/bin/res/voice/audio_stop.m4a"
#define PDT_UI_VOICE_PHOTO_IDX              (33)
#define PDT_UI_VOICE_PHOTO_SRC              "/app/bin/res/voice/photo.m4a"
#define PDT_UI_VOICE_TALK_IDX               (34)
#define PDT_UI_VOICE_TALK_SRC               "/app/bin/res/voice/talk.m4a"
#define PDT_UI_VOICE_TALK_OFF_IDX           (35)
#define PDT_UI_VOICE_TALK_OFF_SRC           "/app/bin/res/voice/talk_off.m4a"
#define PDT_UI_VOICE_CONF_IDX               (36)
#define PDT_UI_VOICE_CONF_SRC               "/app/bin/res/voice/conf.m4a"
#define PDT_UI_VOICE_CONF_OFF_IDX           (37)
#define PDT_UI_VOICE_CONF_OFF_SRC           "/app/bin/res/voice/conf_off.m4a"
#define PDT_UI_VOICE_UPGRADE_IDX            (38)
#define PDT_UI_VOICE_UPGRADE_SRC            "/app/bin/res/voice/upgrade.m4a"

/** @} *//** <!-- ==== APPCOMM End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_APPCOMM_H__ */

