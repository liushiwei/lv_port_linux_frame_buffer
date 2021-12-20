/******************************************************************************

  Copyright (C), 2018-2019, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : svp_alg.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software (SVP) group
  Created       : 2018/05/30
  Description   :
  History       :
  1.Date        : 2018/05/30
    Author      :
    Modification: Created file

******************************************************************************/

#ifndef _SVP_ALG_H_
#define _SVP_ALG_H_

#include "hi_comm_svp_alg.h"
#include "hi_comm_video.h"
#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_Init
*   Description  : context initialization.
*   Parameters   : HI_VOID.
*
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_Init(HI_VOID);

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_Deinit
*   Description  : context deinitialization.
*   Parameters   : HI_VOID.
*
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_Deinit(HI_VOID);

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_LoadModel
*   Description  : Svp alg load model.
*   Parameters   : const SVP_SRC_MEM_INFO_S *pstModelBuf  SVP alg model buffer
*                  SVP_ALG_TYPE_E           enSvpAlgType  SVP alg type
*
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_LoadModel(const SVP_SRC_MEM_INFO_S *pstModelBuf, SVP_ALG_TYPE_E enSvpAlgType);

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_UnloadModel
*   Description  : Svp alg unload model.
*   Parameters   : SVP_ALG_TYPE_E enSvpAlgType SVP alg type
*
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_UnloadModel(SVP_ALG_TYPE_E enSvpAlgType);

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_CreateChn
*   Description  : Create Chn.
*   Parameters   : SVP_ALG_CHN            SvpAlgChn     SVP alg chn.
*                  const SVP_ALG_ATTR_S   *pstSvpAlgAttr    SVP alg attribute parameters
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_CreateChn(SVP_ALG_CHN SvpAlgChn, const SVP_ALG_ATTR_S *pstSvpAlgAttr);

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_DestroyChn
*   Description  : Destroy SVP alg chn.
*   Parameters   : SVP_ALG_CHN  SvpAlgChn   SVP alg chn that would be destroy.
*
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_DestroyChn(SVP_ALG_CHN SvpAlgChn);

/*****************************************************************************
*   Prototype    : HI_SVP_ALG_Process
*   Description  : SVP alg process.
*   Parameters   : SVP_ALG_CHN                      SvpAlgChn          SVP alg chn.
*                  const VIDEO_FRAME_INFO_S         *pstSrcFrm         input frame
*                  const SVP_DST_BLOB_S             astDstBlob[]       output blob
*                  const SVP_ALG_CTRL_S             *pstSvpAlgCtrl     SVP alg ctrl info
*   Return Value : HI_SUCCESS: Success;Error codes: Failure.
*   Spec         :
*   History:
*
*       1.  Date         : 2018/05/30
*           Author       :
*           Modification : Created function
*
*****************************************************************************/
HI_S32 HI_SVP_ALG_Process(SVP_ALG_CHN SvpAlgChn, const VIDEO_FRAME_INFO_S*pstSrcFrm,
    const SVP_DST_BLOB_S astDstBlob[], const SVP_ALG_CTRL_S *pstSvpAlgCtrl);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif/*SVP_ALG_H_*/
