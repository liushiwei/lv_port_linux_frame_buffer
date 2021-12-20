/**
 * @file    hi_notify_server.h
 * @brief   notify server function.
 *
 * Copyright (c) 2017 Huawei Tech.Co.,Ltd
 *
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 * @version   1.0

 */
#ifndef __HI_NOTIFY_SERVER_H__
#define __HI_NOTIFY_SERVER_H__

#include "hi_notify.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/** \addtogroup     NOTIFY */
/** @{ */  /** <!-- [NOTIFY] */

/**Server API */
/**
 * @brief    init the msg server.
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_SERVER_Init(HI_VOID);

/**
 * @brief    deinit the msg server.
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_SERVER_Deinit(HI_VOID);

/** @}*/  /** <!-- ==== NOTIFY End ====*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_NOTIFY_SERVER_H__ */
