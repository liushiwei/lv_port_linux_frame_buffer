#include "HAL.h"
#include "App/Version.h"


#if CONFIG_SENSOR_ENABLE
static void HAL_Sensor_Init()
{
#if CONFIG_SENSOR_IMU_ENABLE
    HAL::IMU_Init();
#endif

#if CONFIG_SENSOR_MAG_ENABLE
    HAL::MAG_Init();
#endif
}
#endif

void HAL::HAL_Init()
{
    Display_Init();
    Power_Init();    
    SD_Init();
    Backlight_Init();
    Encoder_Init();
    Clock_Init();
    Buzz_init();
    GPS_Init();
#if CONFIG_SENSOR_ENABLE
    HAL_Sensor_Init();
#endif
    Audio_Init();
    USB_Init();
}

#if CONFIG_SENSOR_ENABLE
static void HAL_SensorUpdate()
{
#if CONFIG_SENSOR_IMU_ENABLE
    HAL::IMU_Update();
#endif

#if CONFIG_SENSOR_MAG_ENABLE
    HAL::MAG_Update();
#endif
}
#endif

void HAL::HAL_Update()
{
    __IntervalExecute(SD_Update(), 500);
#if CONFIG_SENSOR_ENABLE
    __IntervalExecute(HAL_SensorUpdate(), 1000);
#endif
    Power_EventMonitor();
}
