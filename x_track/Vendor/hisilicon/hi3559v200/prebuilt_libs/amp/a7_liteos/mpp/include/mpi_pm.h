/******************************************************************************

  copyright (C), 2017, hisilicon tech. co., ltd.

 ******************************************************************************
  file name     : mpi_pm.h
  version       : initial draft
  author        : hisilicon multimedia software group
  created       : 2018/09/17
  description   :
  history       :


******************************************************************************/
#ifndef __MPI_PM_H__
#define __MPI_PM_H__

#include "hi_comm_video.h"
#include "hi_comm_pm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */


hi_s32 hi_mpi_pm_set_media_param(hi_mpi_pm_media_cfg *pm_param);
hi_s32 hi_mpi_pm_get_media_param(hi_mpi_pm_media_cfg *pm_param);
hi_s32 hi_mpi_pm_set_single_media_param(hi_mpi_pm_sigle_media_cfg *pm_param);
hi_s32 hi_mpi_pm_get_temperature(hi_s32 *pm_tempe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /*__MPI_SNAP_H__ */


