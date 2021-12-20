/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_osd_define.h
 * @brief   osd module
 * @author  HiMobileCam NDK develop team
 * @date  2019-8-7
 */
#ifndef __HI_MAPI_VGS_DEFINE_H__
#define __HI_MAPI_VGS_DEFINE_H__

#include "hi_comm_vgs.h"
#include "hi_mapi_comm_define.h"
#include "hi_mapi_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */


/* error code for osd */
#define HI_MAPI_VGS_EHANDLE_ILLEGAL \
    HI_MAPI_DEF_ERR(HI_MAPI_MOD_VGS, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_INVALID_CHNID)
#define HI_MAPI_VGS_EILLEGAL_PARAM \
    HI_MAPI_DEF_ERR(HI_MAPI_MOD_VGS, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_ILLEGAL_PARAM)
#define HI_MAPI_VGS_ENULL_PTR   HI_MAPI_DEF_ERR(HI_MAPI_MOD_VGS, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_NULL_PTR)
#define HI_MAPI_VGS_EOPERATE_FAIL   HI_MAPI_DEF_ERR(HI_MAPI_MOD_VGS, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_OPERATE_FAIL)

typedef struct {
    HI_MAPI_FRAME_DATA_S frameDataIn;   /* Input Vedio frame */
    HI_MAPI_FRAME_DATA_S frameDataOut;  /* Output Vedio frame */
} HI_MAPI_VGS_TaskAttr;

typedef enum {
    HI_MAPI_VGS_SCLCOEF_NORMAL  = 0,    /* normal scale coefficient*/
    HI_MAPI_VGS_SCLCOEF_TAP2    = 1,    /* scale coefficient of 2 tap */
    HI_MAPI_VGS_SCLCOEF_TAP4    = 2,    /* scale coefficient of 4 tap */
    HI_MAPI_VGS_SCLCOEF_TAP6    = 3,    /* scale coefficient of 6 tap*/
    HI_MAPI_VGS_SCLCOEF_TAP8    = 4,    /* scale coefficient of 8 tap */
    HI_MAPI_VGS_SCLCOEF_BUTT
} HI_MAPI_VGS_ScaleCoefMode;

typedef struct {
    HI_MAPI_VGS_TaskAttr   vgsTaskAttr;
    HI_MAPI_VGS_ScaleCoefMode scaleCoefMode;
} HI_MAPI_VGS_ScaleTaskAttr;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_MAPI_VGS_DEFINE_H__ */
