#include "HAL.h"
#include <stdlib.h>
#include "Common/DataProc/DataProc.h"
static HAL::CommitFunc_t CommitFunc = nullptr;
static void* UserData = nullptr;

void HAL::IMU_Update()
{
    static int16_t steps;
    steps++;
    if (steps > 9999)
    {
        steps = 0;
    }

    IMU_Info_t imu;
    imu.steps = steps;

    imu.ax = rand() % 1000 - 500;
    imu.ay = rand() % 1000 - 500;
    imu.az = rand() % 1000 - 500;
    imu.gx = rand() % 1000 - 500;
    imu.gy = rand() % 1000 - 500;
    imu.gz = rand() % 1000 - 500;

    // DataProc::IMU_Commit(&imu);
}
void HAL::IMU_Init()
{
    //Serial.print("IMU: init...");
    //Serial.println(imu.Init() ? "success" : "failed");
}

void HAL::IMU_SetCommitCallback(CommitFunc_t func, void* userData)
{
    CommitFunc = func;
    UserData = userData;
}