/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_venc.h
 * @brief   venc module
 * @author  HiMobileCam NDK develop team
 * @date  2019-3-26
 */
#ifndef __HI_MAPI_VENC_H__
#define __HI_MAPI_VENC_H__

#include "hi_mapi_venc_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/**
 * @brief create video encode instance
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] pstVencAttr HI_MAPI_VENC_ATTR_S: the attribute of VENC instance
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_Init(HI_HANDLE VencHdl, const HI_MAPI_VENC_ATTR_S *pstVencAttr);

/**
 * @brief destroy video encode instance
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_Deinit(HI_HANDLE VencHdl);

/**
 * @brief register call back for video encode instance
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] pstVencCB HI_MAPI_VENC_CALLBACK_S: call back function of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_RegisterCallback(HI_HANDLE VencHdl, HI_MAPI_VENC_CALLBACK_S *pstVencCB);

/**
 * @brief unregister call back for video encode instance
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] pstVencCB HI_MAPI_VENC_CALLBACK_S: call back function of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_UnRegisterCallback(HI_HANDLE VencHdl, HI_MAPI_VENC_CALLBACK_S *pstVencCB);

/**
 * @brief start video encode instance
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] s32FrameCnt HI_S32: the frame count of VENC will to do; HI_MAPI_VENC_LIMITLESS_FRAME_COUNT :VENC Will not automatically stop
 *          N( N > 0) :VENC will automatically stop after encode N frame data.
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_Start(HI_HANDLE VencHdl, HI_S32 s32FrameCnt);

/**
 * @brief stop video encode instance
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_Stop(HI_HANDLE VencHdl);

/**
 * @brief  VENC bind VCap
 * @param[in] VcapPipeHdl HI_HANDLE:handle of video capture PIPE.
 * @param[in] PipeChnHdl HI_HANDLE:handle of video capture PIPE's channel.
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_BindVCap(HI_HANDLE VcapPipeHdl, HI_HANDLE PipeChnHdl, HI_HANDLE VencHdl);

/**
 * @brief  VENC unbind VCap
 * @param[in] VcapPipeHdl HI_HANDLE:handle of video capture PIPE.
 * @param[in] PipeChnHdl HI_HANDLE:handle of video capture PIPE's channel.
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_UnBindVCap(HI_HANDLE VcapPipeHdl, HI_HANDLE PipeChnHdl, HI_HANDLE VencHdl);

/**
 * @brief VENC bind VProc
 * @param[in] VProcHdl HI_HANDLE: handle of video processor
 * @param[in] VPortHdl HI_HANDLE: handle of video port
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] bStitch HI_BOOL: stitch or not
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_BindVProc(HI_HANDLE VProcHdl, HI_HANDLE VPortHdl, HI_HANDLE VencHdl, HI_BOOL bStitch);

/**
 * @brief VENC unbind VProc
 * @param[in] VProcHdl HI_HANDLE: handle of video processor
 * @param[in] VPortHdl HI_HANDLE: handle of video port
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] bStitch HI_BOOL: stitch or not
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_UnBindVProc(HI_HANDLE VProcHdl, HI_HANDLE VPortHdl, HI_HANDLE VencHdl, HI_BOOL bStitch);

/**
 * @brief set video encode attribute
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] pstStreamAttr HI_MAPI_VENC_ATTR_S: the attribute of VENC instance
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_SetAttr(HI_HANDLE VencHdl, const HI_MAPI_VENC_ATTR_S *pstStreamAttr);

/**
 * @brief get video encode attribute
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[out] pstStreamAttr HI_MAPI_VENC_ATTR_S: the attribute of VENC instance
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_GetAttr(HI_HANDLE VencHdl, HI_MAPI_VENC_ATTR_S *pstStreamAttr);

/**
 * @brief request IDR frame
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @return Non 0 indicate failed
 * @return  0 indicate success
 */
HI_S32 HI_MAPI_VENC_RequestIDR(HI_HANDLE VencHdl);

/**
 * @brief set video encode extend attribute
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] enCMD HI_MAPI_VENC_CMD_E: command of set VENC extend attribute
 * @param[in] pAttr HI_VOID: the extend attribute of VENC instance
 * @param[in] u32Len HI_U32: length of the extend attribute
 * @return Non 0 indicate set failed
 * @return  0 indicate set success
 */
HI_S32 HI_MAPI_VENC_SetAttrEx(HI_HANDLE VencHdl, HI_MAPI_VENC_CMD_E enCMD, HI_VOID *pAttr, HI_U32 u32Len);

/**
 * @brief get video encode extend attribute
 * @param[in] VencHdl HI_HANDLE: handle of VENC
 * @param[in] enCMD HI_MAPI_VENC_CMD_E: command of get VENC extend attribute
 * @param[out] pAttr HI_VOID: the extend attribute of VENC instance
 * @param[in] u32Len HI_U32: length of the extend attribute
 * @return Non 0 indicate get failed
 * @return 0 indicate get success
 */
HI_S32 HI_MAPI_VENC_GetAttrEx(HI_HANDLE VencHdl, HI_MAPI_VENC_CMD_E enCMD, HI_VOID *pAttr, HI_U32 u32Len);


/**
 * @brief Stop osd instance.Osd region will be destroyed from capture.
 * @param[in] VencHdl HI_HANDLE:handle of video encode.
 * @param[in] enType VENC_HEAD_INFO_TYPE_E:[0,HI_VENC_HEAD_INFO_TYPE_BUTT).
 * @param[out] pcHeadInfo :pointer of venc headinfo
 * @param[out] pu32HeadInfoLength :pointer of venc headinfo len
 * @return Non 0 indicate get failed
 * @return 0 indicate get success
 */
HI_S32 HI_MAPI_VENC_GetStreamHeadInfo(HI_HANDLE VencHdl, VENC_HEAD_INFO_TYPE_E enType, HI_CHAR *pcHeadInfo, HI_U32 *pu32HeadInfoLength);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_MAPI_VENC_H__ */
