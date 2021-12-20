/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_hal_serdes_define.h
 * @brief   serdes module
 * @author  HiMobileCam NDK develop team
 * @date  2019-3-26
 */
#ifndef __HI_MAPI_HAL_SERDES_DEFINE_H__
#define __HI_MAPI_HAL_SERDES_DEFINE_H__

#include "hi_mapi_comm_define.h"
#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/** \addtogroup     SERDES */
/** @{ */ /** <!-- [SERDES] */

#define HI_MAPI_VCAP_SERDES_MAX_NUM           4
#define HI_MAPI_VCAP_SERDES_BINDDEV_MAX_NUM   4

/* struct */
typedef struct hi_HAL_SERDES_DEV_S {
    HI_BOOL         multiInput;
    WDR_MODE_E      enWdrMode;
    HI_U32          u32BindNum;
    HI_HANDLE       BindDevHdl[HI_MAPI_VCAP_SERDES_BINDDEV_MAX_NUM];
} HI_HAL_SERDES_DEV_S;

/** @} */ /** <!-- ==== SERDES End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_MAPI_HAL_SERDES_DEFINE_H__ */
