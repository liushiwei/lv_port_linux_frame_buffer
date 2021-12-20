/******************************************************************************

  copyright (C), 2018-2028, hisilicon tech. co., ltd.

 ******************************************************************************
  file name     : hi_comm_pm.h
  version       : initial draft
  author        : hisilicon multimedia software group
  created       :
  last modified :
  description   : common struct definition for pm
  function list :


******************************************************************************/

#ifndef __HI_COMM_PM_H__
#define __HI_COMM_PM_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#include "hi_type.h"
#include "hi_common.h"
#include "hi_errno.h"
#include "hi_comm_video.h"


/* failure caused by malloc buffer */
#define HI_ERR_PM_NOBUF           HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_NOBUF)
#define HI_ERR_PM_BUF_EMPTY       HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_BUF_EMPTY)
#define HI_ERR_PM_NULL_PTR        HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_NULL_PTR)
#define HI_ERR_PM_ILLEGAL_PARAM   HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_ILLEGAL_PARAM)
#define HI_ERR_PM_BUF_FULL        HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_BUF_FULL)
#define HI_ERR_PM_SYS_NOTREADY    HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_SYS_NOTREADY)
#define HI_ERR_PM_NOT_SUPPORT     HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_SUPPORT)
#define HI_ERR_PM_NOT_PERMITTED   HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_PERM)
#define HI_ERR_PM_BUSY            HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_BUSY)
#define HI_ERR_PM_INVALID_CHNID   HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_INVALID_CHNID)
#define HI_ERR_PM_CHN_UNEXIST     HI_DEF_ERR(HI_ID_PM, EN_ERR_LEVEL_ERROR, EN_ERR_UNEXIST)


typedef struct hi_mpi_pm_media_vi_cfg_s{
    hi_u32 au32_vicap_freq[VI_MAX_DEV_NUM];
    hi_u32 au32_vipipe_sum_pixel[VI_MAX_PIPE_NUM];
} hi_mpi_pm_media_vi_cfg;

typedef struct hi_mpi_pm_media_cfg_s{
    hi_mpi_pm_media_vi_cfg vi_cfg;
    hi_u32 vpss_sum_pix;
    hi_u32 venc_sum_pix;
    hi_u32 vdec_sum_pix;
    hi_u32 avsp_sum_pix;
} hi_mpi_pm_media_cfg;


typedef enum hi_mpi_pm_media_mod_e {
    HI_PM_MEDIA_VI,
    HI_PM_MEDIA_PIPEBE,
    HI_PM_MEDIA_VPSS,
    HI_PM_MEDIA_AVSP,
    HI_PM_MEDIA_VEDU,
    HI_PM_MEDIA_VDEC,
    HI_PM_MEDIA_BUIT
} hi_mpi_pm_media_mod;


typedef struct hi_mpi_pm_sigle_media_cfg_s{
    hi_mpi_pm_media_mod mode;
    union {
        hi_mpi_pm_media_vi_cfg vi_cfg;
        hi_u32 vpss_sum_pix;
        hi_u32 venc_sum_pix;
        hi_u32 vdec_sum_pix;
        hi_u32 avsp_sum_pix;
    }  un_media_cfg;
} hi_mpi_pm_sigle_media_cfg;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif /* __HI_COMM_PM_H__ */

