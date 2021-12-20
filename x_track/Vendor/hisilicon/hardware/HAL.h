#ifndef __HAL_INTERNAL_H
#define __HAL_INTERNAL_H

#include "App/Common/HAL/HAL.h"

#include "Config/Config.h"
#include "CommonMacro.h"

#define INVALID_HANDLE   (0x0)

namespace HAL {
    void Display_Init();
    void USB_Init();
}

#endif
