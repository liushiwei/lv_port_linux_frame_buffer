/**
* @file    hi_logmng.h
* @brief   product logmng struct and interface
*
* Copyright (c) 2017 Unionman Tech.Co.,Ltd
*
* @author    MinJie.YU
* @date      2019/05/28
* @version   1.0

*/

#ifndef _HI_LOGMNG_H
#define _HI_LOGMNG_H

#include "hi_appcomm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/** \addtogroup     LOGMNG */
/** @{ */  /** <!-- [LOGMNG] */

/** macro define */
#define LOGMNG_MAX_DATA_LEN         128
#define LOGMNG_PRIVATE_DATA_LEN     64
#define LOGMNG_INFO_MAX_LEN         32

/** log level enum */
typedef enum hiLOGMNG_LEVEL_E
{
    HI_LOGMNG_ERROR_LEVEL   = 0,
    HI_LOGMNG_WARN_LEVEL    = 1,
    HI_LOGMNG_INFO_LEVEL    = 2,
    HI_LOGMNG_LEVEL_BUTT,
} HI_LOGMNG_LEVEL_E;

/** log type enum */
typedef enum hiLOGMNG_TYPE_E
{
    LOGMNG_POWER_ON,
    LOGMNG_POWER_OFF,
    LOGMNG_VIDEO_REC_START,
    LOGMNG_VIDEO_REC_STOP,
    LOGMNG_VIDEO_REC_NEWFILE,
    LOGMNG_AUDIO_REC_START,
    LOGMNG_AUDIO_REC_STOP,
    LOGMNG_AUDIO_REC_NEWFILE,
    LOGMNG_PHOTO_START,
    LOGMNG_PHOTO_STOP,
    LOGMNG_WIFI_STA_ON,
    LOGMNG_WIFI_STA_OFF,
    LOGMNG_WIFI_AP_ON,
    LOGMNG_WIFI_AP_OFF,
    LOGMNG_GPS_ON,
    LOGMNG_GPS_OFF,
    LOGMNG_LTE_ON,
    LOGMNG_LTE_OFF,
    LOGMNG_KEY_DOWN,
    LOGMNG_KEY_HOLD,
    LOGMNG_KEY_UP,
    LOGMNG_USB_CHARGE_IN,
    LOGMNG_USB_CHARGE_OUT,
    LOGMNG_USB_PC_IN,
    LOGMNG_USB_PC_OUT,
    LOGMNG_FACTORY_RESET,
    LOGMNG_SDCARD_SPACE_FULL,
    LOGMNG_SYSTEM_ERROR,
    LOGMNG_SYSTEM_WARNING,
    LOGMNG_SYSTEM_INFO,
    LOGMNG_BLUETOOTH_ON,
    LOGMNG_BLUETOOTH_OFF,
    LOGMNG_TYPE_BUTT
}HI_LOGMNG_TYPE_E;


typedef struct hiLOGMNG_INFO_S
{
    HI_U32 u32UserPrivate;  /* reseale for key or device on or off, and so on */
    HI_CHAR azPrivateData[LOGMNG_PRIVATE_DATA_LEN];
}HI_LOGMNG_INFO_S;

/*
*   Note : HI_LOGMNG_CFG_S should be compatible with 
*           UM_BODYCAMMNG_CFG_S
*/
typedef struct hiLOGMNG_CFG_S
{
    HI_CHAR cSerial[LOGMNG_INFO_MAX_LEN];
    HI_CHAR userNo[LOGMNG_INFO_MAX_LEN];
    HI_CHAR userName[LOGMNG_INFO_MAX_LEN];
    HI_CHAR unitNo[LOGMNG_INFO_MAX_LEN];
    HI_CHAR unitName[LOGMNG_INFO_MAX_LEN];
    HI_CHAR province[LOGMNG_INFO_MAX_LEN];
    HI_S32 s32SystemLanguage;
}HI_LOGMNG_CFG_S;


/**
* @brief    init logmng
* @return 0 success,non-zero error code.
* @exception    None
* @author    MinJie.YU
* @date      2019/05/29
*/
HI_S32 HI_LOGMNG_Init(const HI_CHAR *pszRootDir, HI_LOGMNG_CFG_S *pstCfg);

/**
* @brief    log save async
* @return 0 success,non-zero error code.
* @exception    None
* @author    MinJie.YU
* @date      2019/05/29
*/
HI_S32 HI_LOGMNG_AsyncWrite(HI_LOGMNG_TYPE_E enType, HI_LOGMNG_INFO_S *pstInfo);

/**
* @brief    log update config
* @return 0 success,non-zero error code.
* @exception    None
* @author    MinJie.YU
* @date      2019/05/29
*/
HI_S32 HI_LOGMNG_Update(const HI_CHAR *pszRootDir, HI_LOGMNG_CFG_S *pstCfg);

/**
* @brief    deinit logmng
* @return 0 success,non-zero error code.
* @exception    None
* @author    MinJie.YU
* @date      2019/05/29
*/
HI_S32 HI_LOGMNG_DeInit(HI_VOID);

/** @}*/  /** <!-- ==== LOGMNG End ====*/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* #ifdef __cplusplus */

#endif /* #ifdef _HI_LOGMNG_H */

