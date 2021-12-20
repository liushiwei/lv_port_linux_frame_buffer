/**
* @file    hi_ahdmng_msg.h
* @brief   product ahd struct and interface
*
* Copyright (c) 2017 Huawei Tech.Co.,Ltd
*
* @author    HiMobileCam Reference Develop Team
* @date      2018/04/10
* @version   1.0

*/

#ifndef __HI_AHDMNG_MSG_H__
#define __HI_AHDMNG_MSG_H__

#include "hi_appcomm_msg.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef enum tagMSG_AHDMNG_E
{
    MSG_AHDMNG_VIDEOLOSTSTATUS = HI_APPCOMM_MSG_ID(HI_APP_MOD_AHDMNG, 0),   /**<AHD Plug  msg*/
    MSG_AHDMNG_BUTT
} MSG_AHDMNG_E;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* #ifdef __cplusplus */

#endif /* #ifdef __HI_AHDMNG_MSG_H__ */

