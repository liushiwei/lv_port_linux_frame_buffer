/**
 * @file    hi_notify_client.h
 * @brief   notify client function.
 *
 * Copyright (c) 2017 Huawei Tech.Co.,Ltd
 *
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 * @version   1.0

 */
#ifndef __HI_NOTIFY_CLIENT_H__
#define __HI_NOTIFY_CLIENT_H__

#include "hi_notify.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/** \addtogroup     MSG */
/** @{ */  /** <!-- [MSG] */

/**Client API */
/**
 * @brief    init the msg client.
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_CLIENT_Init(HI_VOID);

/**
 * @brief    deinit the msg client.
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_CLIENT_Deinit(HI_VOID);

/** @}*/  /** <!-- ==== MSG End ====*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_NOTIFY_CLIENT_H__ */
