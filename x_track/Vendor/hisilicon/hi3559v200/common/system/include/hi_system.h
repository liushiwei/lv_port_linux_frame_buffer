/**
 * @file    hi_system.h
 * @brief   system module struct and interface declaration
 *
 * Copyright (c) 2017 Huawei Tech.Co.,Ltd
 *
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/4/10
 * @version   1.0

 */
#ifndef __HI_SYSTEM_H__
#define __HI_SYSTEM_H__

#include "hi_mapi_ao_define.h"
#include "hi_appcomm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/**\addtogroup     SYSTEM */
/**@{ */  /**<!-- [SYSTEM] */

/** wakeup up source of startup Define */
typedef enum hiSYSTEM_STARTUP_SRC_E
{
    HI_SYSTEM_STARTUP_SRC_WAKEYP = 0,
    HI_SYSTEM_STARTUP_SRC_RTC,
    HI_SYSTEM_STARTUP_SRC_STARTUP,
    HI_SYSTEM_STARTUP_SRC_BUTT
} HI_SYSTEM_STARTUP_SRC_E;

/** wakeup up level Define */
typedef enum hiSYSTEM_WAKEUP_LEVEL_E
{
    HI_SYSTEM_WAKEUP_LEVEL_LOW = 0,
    HI_SYSTEM_WAKEUP_LEVEL_HIGH,
    HI_SYSTEM_WAKEUP_LEVEL_BUTT
} HI_SYSTEM_WAKEUP_LEVEL_E;

/**
  * @brief ircut state enum
  * @note none
  */
typedef enum hiHI_SYETEM_IRCUT_STATE_E
{
    HI_SYETEM_IRCUT_STATE_SLEEP,  /* IN1 - L, IN2 - L */
    HI_SYETEM_IRCUT_STATE_ON,     /* IN1 - L, IN2 - H */
    HI_SYETEM_IRCUT_STATE_OFF,    /* IN1 - H, IN2 - L */
    HI_SYETEM_IRCUT_STATE_LOCK,   /* IN1 - H, IN2 - H */
    HI_SYETEM_IRCUT_STATE_BUTT
} HI_SYSTEM_IRCUT_STATE_E;

typedef struct hiSYSTEM_TM_S
{
    HI_S32 s32sec;         /**< seconds.range[0,59] */
    HI_S32 s32min;         /**< minutes.range[0,59] */
    HI_S32 s32hour;        /**< hours.range[0,23] */
    HI_S32 s32mday;        /**< day of the month.range[1,31] */
    HI_S32 s32mon;         /**< month.range[1,12] */
    HI_S32 s32year;        /**< year.>1970 */
} HI_SYSTEM_TM_S;

typedef struct hiSYSTEM_BREATH_LIGHT_S
{
    HI_BOOL bEnable;
    HI_U32 u32GpioGrp;      /**< GPIO grp not use */
    HI_U32 u32GpioNum;      /**< GPIO num not use */
} HI_SYSTEM_BREATH_LIGHT_S;

typedef struct hiHI_SYSTEM_Sound_S
{
    HI_HANDLE AoHdl;
    HI_U64 u64PhyAddr;
    HI_U32 u32DataLen;
} HI_SYSTEM_Sound_S;

#define MSG_MOD_SOUND                          HI_APPCOMM_MSG_ID(HI_APP_MOD_SOUND, 0)

#define MSG_VGS_DRAW_RECT                      HI_APPCOMM_MSG_ID(HI_APP_MOD_VGS_DRAW_RECT, 0)
#define MSG_VO_BIND_VPSS                       HI_APPCOMM_MSG_ID(HI_APP_MOD_VO_BIND_VPSS, 0)
#define FACE_DETECT_RECT_BUFF_SIZE             (64 * 1024)

#if defined(AMP_LINUX_HUAWEILITE)&&defined(__HuaweiLite__)
/**
 * @brief    init system msg service
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_ServiceInit(HI_VOID);
#endif

#if (defined(AMP_LINUX_HUAWEILITE)&& !defined(__HuaweiLite__))
/**
 * @brief     wait sharefs ready
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_BOOL HI_SYSTEM_WaitSharefsReady(HI_S32 s32Timeout_s);
#endif


#ifdef CFG_BOOT_SOUND_ON

#define     BODYCAM_INFO_MAX_LEN            32

typedef struct tagSYSTEM_SOUND_S
{
    HI_U8* pu8PCMData;
    HI_U32 u32DataLen;
} SYSTEM_SOUND_S;

typedef struct boot_sound_mgr
{
    HI_HANDLE AoHdl;
    HI_CHAR   userNo[BODYCAM_INFO_MAX_LEN];    /*执法记录仪使用者警号，不可为空*/
    SYSTEM_SOUND_S sound[11];
}BOOT_SOUND_MGR;
/**
 * @brief    play boot sound.
 * @param[in] AoHdl:ao handle
 * @param[in] pu8PCMData:pcm_s16le data
 * @param[in] u32DataLen:pcm_s16le data lenght
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/8
 */
HI_S32 HI_SYSTEM_BootSound(HI_HANDLE AoHdl, const HI_VOID* pData, HI_U32 u32DataLen);
#endif

#ifdef CFG_BOOT_LOGO_ON
/**
 * @brief    show boot logo.
 * @param[in] DispHdl:diap handle
 * @param[in] WndHdl:window handle
 * @param[in] stRes:logo resolution
 * @param[in] pu8YUVData:YUV420 planer data
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/8
 */
HI_S32 HI_SYSTEM_BootLogo(HI_HANDLE DispHdl, HI_HANDLE WndHdl, SIZE_S stRes, const HI_U8* pu8YUVData);
#endif

/**
 * @brief    set system date time
 * @param[in] pstDateTime: date time
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetDateTime(const HI_SYSTEM_TM_S* pstDateTime);

/**
 * @brief    get rtc date time
 * @param[out] pstDateTime: date time
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_GetRTCDateTime(HI_SYSTEM_TM_S* pstDateTime);

/**
 * @brief    set system breath light
 * @param[in] pstBreathLight: breath light attr
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetBreathLight(const HI_SYSTEM_BREATH_LIGHT_S *pstBreathLight);

/**
 * @brief    produce a system sound for key tone.
 * @param[in] AoHdl:ao handle
 * @param[in] pstAoAttr:ao attribute
 * @param[in] u64PhyAddr:pcm_s16le data phyaddr
 * @param[in] u32DataLen:pcm_s16le data lenght
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_Sound(HI_HANDLE AoHdl, const HI_MAPI_AO_ATTR_S* pstAoAttr, HI_U64 u64PhyAddr, HI_U32 u32DataLen);

/**
 * @brief    halt system
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_VOID HI_SYSTEM_Poweroff(HI_VOID);

/**
 * @brief    reboot system.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_VOID HI_SYSTEM_Reboot(HI_VOID);


/**
 * @brief    set Wakeup enable.
 * @param[in] enable: Wakeup enable
 * @param[in] enLevel: Wakeup level
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_VOID HI_SYSTEM_SetWakeUpEnable(HI_BOOL bEnable,HI_SYSTEM_WAKEUP_LEVEL_E enLevel);

/**
 * @brief    set power_on enable.
 * @param[in] bEnable:
              HI_TRUE mean poweren_bit is true,and output high level
              HI_FALSE mean poweren_bit is false,and output low leve
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_VOID HI_SYSTEM_SetSystemPwrEnable(HI_BOOL bEnable);

/**
 * @brief    get Wakeup Source of Startup.
 * @param[in] penStartupSrc: Wakeup Source
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_GetStartupWakeupSource(HI_SYSTEM_STARTUP_SRC_E* penStartupSrc);

/**
 * @brief    get light adc level
 * @param[out] ps32Level: light adc level
 * @return 0 success,non-zero error code.
 * @exception    adc level should transform by application
 * @author    HiMobileCam Reference Develop Team
 * @date      2019/3/28
 */
HI_S32 HI_SYSTEM_GetLightLevel(HI_S32 *ps32Level);

/**
 * @brief    get internal battery adc level
 * @param[out] ps32Level: battery adc level
 * @return 0 success,non-zero error code.
 * @exception    adc level should transform by application
 * @author    HiMobileCam Reference Develop Team
 * @date      2019/3/28
 */
HI_S32 HI_SYSTEM_GetInternalBatLevel(HI_S32 *ps32Level);

/**
 * @brief    get external battery insert or not
 * @param  none
 * @return HI_TRUE battery is insert,  HI_FALSE battery is not insert or error.
 * @exception    adc level should transform by application
 * @author    HiMobileCam Reference Develop Team
 * @date      2019/3/28
 */
HI_BOOL HI_SYSTEM_GetExternalBatInsert(HI_VOID);

/**
 * @brief    get external cam insert or not
 * @param  none
 * @return HI_TRUE cam is insert,  HI_FALSE cam is not insert or error.
 * @exception    adc level should transform by application
 * @author    HiMobileCam Reference Develop Team
 * @date      2019/3/28
 */
HI_BOOL HI_SYSTEM_GetExternalCamInsert(HI_VOID);

/**
 * @brief    get USB insert or not
 * @param  none
 * @return HI_TRUE USB is insert,  HI_FALSE USB is not insert or error.
 * @exception    adc level should transform by application
 * @author    HiMobileCam Reference Develop Team
 * @date      2019/3/28
 */
HI_BOOL HI_SYSTEM_GetUSBInsert(HI_VOID);

/**
 * @brief    set Vibrate.
 * @param[in] u32MilliSeconds: vibrate time, unit : ms
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetVibrate(HI_U32 u32MilliSeconds);

/**
 * @brief    set IRCUT state.
 * @param[in] enIRCutState: IRCUT state
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetIRCUTState(HI_SYSTEM_IRCUT_STATE_E enIRCutState);

/**
 * @brief    Get LTE on state.
 * @param[in] none
 * @exception    None 
 * @return  HI_TRUE LTE module is power on, other is power off
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_BOOL HI_SYSMNG_GetLTEState(HI_VOID);

/**
 * @brief    set LTE state.
 * @param[in] bEnable: LTE on or off
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetLTEState(HI_BOOL bEnable);

/**
 * @brief    set LTE power off.
 * @param[in] none
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @note     LTE hardware close
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetLTEPowerOff(HI_VOID);

/*
* @brief     set Boot Mute State.
* @param[in] HI_TRUE:mute;HI_FALSE: unmute
*/
HI_S32 HI_SYSTEM_BootMute(HI_BOOL bMute);

/**
 * @brief    set Senosr power on or off.
 * @param[in] bPowerOn : HI_BOOL
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @note     Sensro power on or off
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_SetSensorState(HI_BOOL bPowerOn);

/**
 * @brief    get Senosr power on or off.
 * @param[in] pbPowerOn : HI_BOOL *
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @note     Sensro power on or off
 * @date      2018/5/4
 */
HI_S32 HI_SYSTEM_GetSensorState(HI_BOOL *pbPowerOn);

/**@}*/  /**<!-- ==== SYSTEM End ====*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_SYSTEM_H__ */


