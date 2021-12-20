#include "HAL.h"

#ifndef LINUX
#include <windows.h>
#endif

#include "hi_hal_gauge.h"

#include "hi_appcomm.h"
#include "hi_appcomm_util.h"
#include "hi_appcomm_log.h"


/**
  * @brief  电源初始化
  * @param  无
  * @retval 无
  */
void HAL::Power_Init()
{
    HI_S32 s32Ret = HI_SUCCESS;

    s32Ret = HI_HAL_GAUGE_Init();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "GAUGE Init");
}

void HAL::Power_GetInfo(Power_Info_t* info)
{
    HI_BOOL bCharge = HI_FALSE;
    HI_S32 s32Voltage = 3700;
    HI_S32 s32Level = 80;

    (void)HI_HAL_GAUGE_GetChargeState(&bCharge);
    (void)HI_HAL_GAUGE_GetLevel(&s32Level);

    info->isCharging = bCharge;
    info->voltage = s32Voltage;
    info->usage = s32Level;
}

void HAL::Power_SetEventCallback(Power_CallbackFunction_t callback)
{

}

void HAL::Power_EventMonitor()
{
    
}


