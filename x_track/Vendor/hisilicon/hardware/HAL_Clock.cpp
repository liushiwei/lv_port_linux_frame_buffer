#include <time.h> 
#include <string.h>

#include "HAL.h"

#include "hi_appcomm.h"
#include "hi_system.h"


void HAL::Clock_Init()
{
    Clock_Info_t info;
    Clock_GetInfo(&info);
    MLOGI("Clock: %04d-%02d-%02d %s %02d:%02d:%02d\r\n",
        info.year,
        info.month,
        info.day,
        Clock_GetWeekString(info.week),
        info.hour,
        info.minute,
        info.second
    );
}

void HAL::Clock_GetInfo(Clock_Info_t* info)
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_SYSTEM_TM_S stRTCTime;
    memset(&stRTCTime, 0, sizeof(HI_SYSTEM_TM_S));
    s32Ret = HI_SYSTEM_GetRTCDateTime(&stRTCTime);
    if (s32Ret)
    {
        MLOGE("HI_SYSTEM_GetRTCDateTime failed: %x\n", s32Ret);
    }

    time_t t; 
    char buff[10]; 
    struct tm *tm = NULL;

    t = time(NULL);
    if (t != -1) 
    {
        tm = localtime(&t);
        info->week = tm->tm_wday;
    }
    else 
    {
        info->week = 0;
    }

    info->year = stRTCTime.s32year;
    info->month = stRTCTime.s32mon;
    info->day = stRTCTime.s32mday;
    info->hour = stRTCTime.s32hour;
    info->minute = stRTCTime.s32min;
    info->second = stRTCTime.s32sec;
    info->millisecond = 0;
}

void HAL::Clock_SetInfo(const Clock_Info_t* info)
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_SYSTEM_TM_S stDateTime;
    memset(&stDateTime, 0, sizeof(HI_SYSTEM_TM_S));

    stDateTime.s32year = info->year;
    stDateTime.s32mon  = info->month;
    stDateTime.s32mday = info->day;
    stDateTime.s32hour = info->hour;
    stDateTime.s32min  = info->minute;
    stDateTime.s32sec  = info->second;
    s32Ret = HI_SYSTEM_SetDateTime(&stDateTime);
    if (s32Ret)
    {
        MLOGE("HI_SYSTEM_SetDateTime failed: %x\n", s32Ret);
    }
}

const char* HAL::Clock_GetWeekString(uint8_t week)
{
    const char* week_str[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    return week < 7 ? week_str[week] : "";
}
