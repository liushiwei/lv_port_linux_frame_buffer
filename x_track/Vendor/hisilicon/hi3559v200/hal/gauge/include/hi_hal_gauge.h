
/**
* @file    hi_hal_gauge.h
* @brief   product hal gauge struct and interface
*
* Copyright (c) 2017 Huawei Tech.Co.,Ltd
*
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
* @version   1.0

*/
#ifndef __HI_HAL_GAUGE_H__
#define __HI_HAL_GAUGE_H__
#include "hi_type.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/** \addtogroup     HAL_GAUGE */
/** @{ */  /** <!-- [HAL_GAUGE] */

#define IOCTL_CMD_READ_VOL              _IOR(10, 0, unsigned long)	//read voltage of the battery
#define IOCTL_CMD_READ_CAPACITY         _IOR(10, 1, unsigned long)	//read capacity of the battery
#define IOCTL_CMD_READ_RRT              _IOR(10, 2, unsigned long)	//read remaining run time of the battery
#define IOCTL_CMD_READ_ALRT             _IOR(10, 3, unsigned long)	//read alert flag low capacity of the battery
#define IOCTL_CMD_READ_CHARGE           _IOR(10, 4, unsigned long)	//read battery charge state


/**
* @brief     hal gauge initialization,insmod driver
* @return 0 success,non-zero error code.
* @exception    None
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
*/
HI_S32 HI_HAL_GAUGE_Init(HI_VOID);

/**
* @brief    brief Get gauge Level
* @param[out] ps32Level:,range is 0~100 percent,0 mean zero electric quantity,100 mean full electric quantity
* @return 0 success,non-zero error code.
* @exception    None
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
*/
HI_S32 HI_HAL_GAUGE_GetLevel(HI_S32* ps32Level);

/**
* @brief    brief Get gauge Voltage
* @param[out] ps32Vol:,gauge Voltage, unit : mV
* @return 0 success,non-zero error code.
* @exception    None
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
*/
HI_S32 HI_HAL_GAUGE_GetVol(HI_S32* ps32Vol);

/**
* @brief    brief Get Charge State
* @param[out] pbCharge: True is Charge Now
* @return 0 success,non-zero error code.
* @exception    None
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
*/
HI_S32 HI_HAL_GAUGE_GetChargeState(HI_BOOL* pbCharge);

/**
* @brief    HAL gauge deinitialization,rmmod driver
* @return 0 success,non-zero error code.
* @exception    None
* @author    HiMobileCam Reference Develop Team
* @date      2017/12/12
*/
HI_S32 HI_HAL_GAUGE_Deinit(HI_VOID);


/** @}*/  /** <!-- ==== HAL_GAUGE End ====*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of __HI_HAL_GAUGE_H__*/
