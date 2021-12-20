/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_hal_serdes.h
 * @brief   serdes module
 * @author  HiMobileCam NDK develop team
 * @date  2019-3-26
 */
#ifndef __HI_MAPI_HAL_SERDES_H__
#define __HI_MAPI_HAL_SERDES_H__

#include "hi_mapi_hal_serdes_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/** \addtogroup     SERDES */
/** @{ */ /** <!-- [SERDES] */

/* Interface */
/**
 * @brief reg serdes module.
 * @param[in] SerdesHdl HI_HANDLE:handle of serdes device.
 * @param[in] pstHalDev HI_HAL_SERDES_DEV_S*:serdes attribute
 * @return 0  reg serdes module success.
 * @return Non 0  reg serdes module fail.
 */
HI_S32 HI_MAPI_VCAP_RegSerdesModule(HI_HANDLE SerdesHdl, HI_HAL_SERDES_DEV_S *pstHalDev);

/**
 * @brief UnReg serdes Module.
 * @param[in] SerdesHdl HI_HANDLE:handle of serdes device.
 * @return 0  UnReg serdes Module success.
 * @return Non 0  UnReg serdes Module fail.
 */
HI_S32 HI_MAPI_VCAP_UnRegSerdesModule(HI_HANDLE SerdesHdl);

/** @} */ /** <!-- ==== serdes End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_MAPI_HAL_SERDES_H__ */
