/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_osd.h
 * @brief   osd module
 * @author  HiMobileCam NDK develop team
 * @date  2019-7-19
 */

#include "hi_mapi_osd_define.h"

#ifndef __HI_MAPI_OSD_H__
#define __HI_MAPI_OSD_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/** \addtogroup     OSD */
/** @{ */  /** <!-- [OSD] */

/** function interface */
/**
 * @brief    osd module initialization, eg. create time osd update task.
 * @param[in] pstFonts:osd fonts lib
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_Init(const HI_MAPI_OSD_FONTS_S* pstFonts);

/**
 * @brief    osd module de-initialization, eg. destroy time osd update task, release resource.
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_Deinit(HI_VOID);

/**
 * @brief    set osd attribute.
 * @param[in] s32OsdIdx:osd index, range[0,HI_MAPI_OSD_MAX_CNT)
 * @param[in] pstAttr:osd configure attribute
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_SetAttr(HI_S32 s32OsdIdx, HI_MAPI_OSD_ATTR_S* pstAttr);

/**
 * @brief    get osd attribute.
 * @param[in] s32OsdIdx:osd index, range[0,HI_MAPI_OSD_MAX_CNT)
 * @param[out] pstAttr:osd configure attribute
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_GetAttr(HI_S32 s32OsdIdx, HI_MAPI_OSD_ATTR_S* pstAttr);

/**
 * @brief    start osd by index.
 * @param[in] s32OsdIdx:osd index, range[0,HI_MAPI_OSD_MAX_CNT)
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_Start(HI_S32 s32OsdIdx);

/**
 * @brief    stop osd by index.
 * @param[in] s32OsdIdx:osd index, range[0,HI_MAPI_OSD_MAX_CNT)
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_Stop(HI_S32 s32OsdIdx);

/**
 * @brief    set osd show by batch.
 * @param[in] u32Batch:user define
 * @param[in] bShow:1-show 0-not show
 * @return 0 success,non-zero error code.
 * @exception    None
 */
HI_S32 HI_MAPI_OSD_Batch(HI_U32 u32Batch, HI_BOOL bShow);

/**
 * @brief    Update osd GpsInfo.
 * @param[in] pstGpsMsg: GpsInfo
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/18
 */
HI_S32 HI_MAPI_OSD_UpdatePosition( const HI_VOID *pstPosition);



/** @} */  /** <!-- ==== OSD End ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
#endif
