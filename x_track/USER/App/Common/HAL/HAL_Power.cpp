#include "HAL.h"

#ifndef LINUX
#include <windows.h>
#endif

void HAL::Power_GetInfo(Power_Info_t* info)
{
#ifndef LINUX
    SYSTEM_POWER_STATUS sysPower = { 0 };
    GetSystemPowerStatus(&sysPower);

    int usage = sysPower.BatteryLifePercent;

    if (usage > 100)
    {
        usage = 100;
    }

    info->isCharging = sysPower.ACLineStatus;
#else
    int usage = 90;
    info->isCharging = false;
#endif

    info->voltage = 3700;
    info->usage = usage;
}

void HAL::Power_SetEventCallback(Power_CallbackFunction_t callback)
{

}
