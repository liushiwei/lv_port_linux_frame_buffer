/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: host uvc mode interface
 * Author: HiMobileCam Reference Develop Team
 * Create: 2019-09-17
 */

#ifndef __HI_HOST_UVC_H__
#define __HI_HOST_UVC_H__

#include "hi_usb.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

HI_S32 USB_HostUvcInit(HI_VOID);

HI_VOID USB_HostUvcDeinit(HI_VOID);

HI_BOOL USB_HostUvcIsConnected(HI_VOID);

HI_S32 USB_HostUvcOpenDevice(HI_VOID);

HI_VOID USB_HostUvcCloseDevice(HI_VOID);

HI_S32 USB_HostUvcGetCapability(HI_USB_HostUvcCapability *capability);

HI_S32 USB_HostUvcStart(const HI_USB_HostUvcCfg *cfg);

HI_VOID USB_HostUvcStop(HI_VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __HI_HOST_UVC_H__ */
