/******************************************************************************

  Copyright (C), 2018-2019, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_comm_svp_alg.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software (SVP) group
  Created       : 2018/05/30
  Description   :
  History       :
  1.Date        : 2018/05/30
    Author      :
    Modification: Created file
******************************************************************************/
#ifndef _HI_COMM_SVP_ALG_H_
#define _HI_COMM_SVP_ALG_H_

#include "hi_comm_svp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**************************************SVP_ALG Error Code**************************************/
typedef enum hiEN_SVP_ALG_ERR_CODE_E {
    ERR_SVP_ALG_SYS_TIMEOUT = 0x40, /* SVP ALG process timeout */
    ERR_SVP_ALG_QUERY_TIMEOUT = 0x41, /* SVP ALG query timeout */

    ERR_SVP_ALG_BUTT
} EN_SVP_ALG_ERR_CODE_E;

/* Invalid device ID */
#define HI_ERR_SVP_ALG_INVALID_DEVID HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_INVALID_DEVID)
/* Invalid channel ID */
#define HI_ERR_SVP_ALG_INVALID_CHNID HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_INVALID_CHNID)
/* At least one parameter is illegal. For example, an illegal enumeration value exists. */
#define HI_ERR_SVP_ALG_ILLEGAL_PARAM HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_ILLEGAL_PARAM)
/* The channel exists. */
#define HI_ERR_SVP_ALG_EXIST         HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_EXIST)
/* The UN exists. */
#define HI_ERR_SVP_ALG_UNEXIST       HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_UNEXIST)
/* A null point is used. */
#define HI_ERR_SVP_ALG_NULL_PTR      HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_NULL_PTR)
/* Try to enable or initialize the system, device, or channel before configuring attributes. */
#define HI_ERR_SVP_ALG_NOT_CONFIG    HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_CONFIG)
/* The operation is not supported currently. */
#define HI_ERR_SVP_ALG_NOT_SURPPORT  HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_SUPPORT)
/* The operation, changing static attributes for example, is not permitted. */
#define HI_ERR_SVP_ALG_NOT_PERM      HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_NOT_PERM)
/* A failure caused by the malloc memory occurs. */
#define HI_ERR_SVP_ALG_NOMEM         HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_NOMEM)
/* A failure caused by the malloc buffer occurs. */
#define HI_ERR_SVP_ALG_NOBUF         HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_NOBUF)
/* The buffer is empty. */
#define HI_ERR_SVP_ALG_BUF_EMPTY     HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_BUF_EMPTY)
/* No buffer is provided for storing new data. */
#define HI_ERR_SVP_ALG_BUF_FULL      HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_BUF_FULL)
/* The system is not ready because it may be not initialized or loaded.
 * The error code is returned when a device file fails to be opened. */
#define HI_ERR_SVP_ALG_NOTREADY      HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_SYS_NOTREADY)
/* The source address or target address is incorrect during the operations. */
#define HI_ERR_SVP_ALG_BADADDR       HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_BADADDR)
/* The resource is busy during the operations */
#define HI_ERR_SVP_ALG_BUSY          HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, EN_ERR_BUSY)
/* SVP_ALG process timeout */
#define HI_ERR_SVP_ALG_SYS_TIMEOUT   HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, ERR_SVP_ALG_SYS_TIMEOUT)
/* SVP_ALG query timeout */
#define HI_ERR_SVP_ALG_QUERY_TIMEOUT HI_DEF_ERR(HI_ID_SVP_ALG, EN_ERR_LEVEL_ERROR, ERR_SVP_ALG_QUERY_TIMEOUT)

/*
* Definition of svp alg type
*/
typedef enum hiSVP_ALG_TYPE_E {
    SVP_ALG_TYPE_FD = 0x0, /* Face detection */
    SVP_ALG_TYPE_BUTT
} SVP_ALG_TYPE_E;

/*
* Definition of svp alg ctrl struct
*/
typedef struct hiSVP_ALG_CTRL_S {
    HI_U32 u32DstBlobNum;
} SVP_ALG_CTRL_S;

/*
* Definition of svp alg attribute
*/
typedef struct hiSVP_ALG_ATTR_S {
    SVP_ALG_TYPE_E enAlgType; /* SVP algorithm type */
} SVP_ALG_ATTR_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* _HI_COMM_SVP_ALG_H_ */
