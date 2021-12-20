#include "HAL.h"
#include "TinyGPSPlus/src/TinyGPS++.h"

#include "hi_appcomm.h"
#include "hi_hal_gps.h"
#include "hi_appcomm_log.h"

#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define GPS_READ_TIMEOUT_MS     200

static TinyGPSPlus gps;


static HI_VOID *GPS_ReadThread(HI_VOID* pArgs)
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_GPSDATA gpsData = {0};
    gpsData.wantReadLen = 1;

    s32Ret = HI_HAL_GPS_Init(HI_GPS_MODE_DOUBLE);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "GPS Init");

    pthread_detach(pthread_self());

    for (;;)
    {
        gpsData.actualReadLen = 0;

        s32Ret = HI_HAL_GPS_GetRawData(&gpsData, GPS_READ_TIMEOUT_MS);
        if ((s32Ret >= 0) && (gpsData.actualReadLen == 1))
        {
            gps.encode(gpsData.rawData[0]);
        }

        if (0 == gpsData.actualReadLen)
        {
            HI_usleep(50 * 1000);
        }
    }

    return HI_NULL;
}

void HAL::GPS_Init()
{
    HI_S32 s32Ret = HI_SUCCESS;
    pthread_t gpsReadThd;

    s32Ret = pthread_create(&gpsReadThd, HI_NULL, GPS_ReadThread, HI_NULL);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "GPS ReadThread");

    MLOGI("GPS: TinyGPS++ library v%s by Mikal Hart\n", 
        TinyGPSPlus::libraryVersion());
}

bool HAL::GPS_GetInfo(GPS_Info_t* info)
{
    memset(info, 0, sizeof(GPS_Info_t));

    info->isVaild = gps.location.isValid();
    info->longitude = gps.location.lng();
    info->latitude = gps.location.lat();
    info->altitude = gps.altitude.meters();
    info->speed = gps.speed.kmph();
    info->course = gps.course.deg();

    info->clock.year = gps.date.year();
    info->clock.month = gps.date.month();
    info->clock.day = gps.date.day();
    info->clock.hour = gps.time.hour();
    info->clock.minute = gps.time.minute();
    info->clock.second = gps.time.second();
    info->satellites = gps.satellites.value();

    return info->isVaild;
}

bool HAL::GPS_LocationIsValid()
{
    return gps.location.isValid();
}

double HAL::GPS_GetDistanceOffset(GPS_Info_t* info,  double preLong, double preLat)
{
    return gps.distanceBetween(info->latitude, info->longitude, preLat, preLong);
}

