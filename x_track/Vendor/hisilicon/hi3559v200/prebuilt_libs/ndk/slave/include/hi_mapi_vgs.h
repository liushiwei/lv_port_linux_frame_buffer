/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_vgs.h
 * @brief   vgs module
 * @author  HiMobileCam NDK develop team
 * @date  2019-8-8
 */
#ifndef __HI_MAPI_VGS_H__
#define __HI_MAPI_VGS_H__

#include "hi_mapi_vgs_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/**
 * @brief Register vgs message module
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VGS_RegMsg(HI_VOID);

/**
 * @brief start job
 * @param[out] vgsHdl HI_HANDLE *: handle pointer of VGS
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VGS_BeginJob(HI_HANDLE *vgsHdl);

/**
 * @brief add scale task
 * @param[in] vgsHdl HI_HANDLE: handle of VGS
 * @param[in] pstVgsAttr HI_MAPI_VGS_ScaleTaskAttr *: the attribute pointer of VGS scale
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VGS_AddScaleTask(HI_HANDLE vgsHdl, const HI_MAPI_VGS_ScaleTaskAttr *scaleTaskAttr);

/**
 * @brief commit job
 * @param[in] vgsHdl HI_HANDLE: handle of VGS
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VGS_EndJob(HI_HANDLE vgsHdl);

/**
 * @brief cabce job
 * @param[in] vgsHdl HI_HANDLE: handle of VGS
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VGS_CanceJob(HI_HANDLE vgsHdl);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_MAPI_VGS_H__ */
