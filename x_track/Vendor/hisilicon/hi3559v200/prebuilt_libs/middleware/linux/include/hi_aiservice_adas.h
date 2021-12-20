/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: aiservice adas module
 * Author: HiMobileCam middleware develop team
 * Create: 2019-07-30
 */

#ifndef HI_AISERVICE_ADAS_H
#define HI_AISERVICE_ADAS_H

#include "hi_type.h"
#include "hi_aiservice_adas_comm.h"
#include "hi_aiservice_adas_algo.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef HI_VOID* HiAiserviceAdasHandle;

typedef enum {
    HI_ADAS_EVENT_RESULT_PER_IMAGE,
    HI_ADAS_EVENT_ERROR,
    HI_ADAS_EVENT_BUTT
}HiAdasEventType;

typedef enum {
    HI_ADAS_ERROR_IMG_ERROR,
    HI_ADAS_ERROR_RESOURCE_CONFLICT,
    HI_ADAS_ERROR_BUTT
}HiAdasErrorType;

typedef struct {
    union {
        HiAdasAlgoProcessResult result;
        HiAdasErrorType errorType;
    };
}HiAdasEventData;

typedef HI_VOID (*HI_AISERVICE_ADAS_EventCallback)(HiAiserviceAdasHandle adas,
    HiAdasEventType eventType, const HiAdasEventData* dataInfo);

typedef HI_VOID (*HI_AISERVICE_ADAS_CalibrateCallback)(HiAiserviceAdasHandle adas,
    HI_S32 result, HiAdasCalibrateResult* caliResult);

typedef struct {
    HI_AISERVICE_ADAS_EventCallback eventCallback;
    HI_AISERVICE_ADAS_CalibrateCallback caliCallback;
    HiAdasAlgoPara initAlgo;
    HI_CHAR algoName[HI_ADAS_MAX_NAME_LEN];
}HiAdasCreatePara;

HI_S32 HI_AISERVICE_ADAS_Init(HI_VOID);

HI_S32 HI_AISERVICE_ADAS_Register(const HiAdasAlgorithm* algorithm);

HI_S32 HI_AISERVICE_ADAS_Unregister(const HI_CHAR* adasAlgoName);

HI_S32 HI_AISERVICE_ADAS_GetCapability(const HI_CHAR* adasAlgoName, HiAdasCapability* capability);

HI_S32 HI_AISERVICE_ADAS_Create(HiAiserviceAdasHandle* adasHandle,  const HiAdasCreatePara* createPara);

HI_S32 HI_AISERVICE_ADAS_Destroy(HiAiserviceAdasHandle adasHandle);

HI_S32 HI_AISERVICE_ADAS_ProcessImage(HiAiserviceAdasHandle adasHandle,
    const HiAdasImage* image, HiAdasAlgoProcessResult* result);

HI_S32 HI_AISERVICE_ADAS_AsyncProcessImage(HiAiserviceAdasHandle adasHandle, const HiAdasImage* image);

HI_S32 HI_AISERVICE_ADAS_SetAttr(HiAiserviceAdasHandle adasHandle, HiAdasAttrType type, const HiAdasAttr* attr);

HI_S32 HI_AISERVICE_ADAS_GetAttr(HiAiserviceAdasHandle adasHandle, HiAdasAttrType type, HiAdasAttr* attr);

HI_S32 HI_AISERVICE_ADAS_Invoke(HiAiserviceAdasHandle adasHandle, HI_U32 cmd, const HiAdasCmdPara* cmdPara);

HI_S32 HI_AISERVICE_ADAS_Deinit(HI_VOID);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
