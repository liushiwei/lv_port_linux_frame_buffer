#include "HAL.h"

bool HAL::SD_Init()
{
    return true;
}

bool HAL::SD_GetReady()
{
    return true;
}

float HAL::SD_GetCardSizeMB()
{
    return 32 * 1024;
}

static void SD_Check(bool isInsert)
{
   
}

void HAL::SD_SetEventCallback(SD_CallbackFunction_t callback)
{
    
}

void HAL::SD_Update()
{
    
}
const char* HAL::SD_GetTypeName()
{
    const char* type = "Unknown";
failed:
    return type;
}