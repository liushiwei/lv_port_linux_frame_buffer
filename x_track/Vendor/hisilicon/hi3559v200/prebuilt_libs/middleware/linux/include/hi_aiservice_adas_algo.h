/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: adas algorithm interface define
 * Author: HiMobileCam middleware develop team
 * Create: 2019-07-30
 */

#ifndef HI_AISERVICE_ADAS_ALGO_H
#define HI_AISERVICE_ADAS_ALGO_H

#include "hi_type.h"
#include "hi_aiservice_adas_comm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define HI_ADAS_MAX_CAP_NUM 5
#define HI_ADAS_INVOKE_BYTE_NUM 256

typedef struct {
    HiAdasSliSign signs[MAX_SLI_SIGNS_PER_FRAME];
    HI_U32 signNum;
}HiAdasAlgoSliResult;

typedef struct {
    HI_U32 warnNum;
    HI_U32 carNum;
    HiAdasCollisonObstacle carList[MAX_CARS_PER_IMG];
}HiAdasAlgoFcwResult;

typedef struct {
    HI_U32 warnNum;
    HI_U32 pedestrianNum;
    HiAdasCollisonObstacle pedestrianList[MAX_PEDESTRIAN_PER_IMG];
}HiAdasAlgoPcwResult;

typedef struct {
    HI_BOOL isFrontCarStart;
    HiAdasObstacle car;
}HiAdasAlgoFcrResult;

typedef struct {
    union {
        HiAdasAlgoSliResult sliResult;
        HiAdasAlgoLdwResult ldwResult;
        HiAdasAlgoFcwResult fcwResult;
        HiAdasAlgoFcrResult fcrResult;
        HiAdasAlgoPcwResult pcwResult;
    };
}HiAdasAlgoResult;

typedef struct {
    HiAdasCapabiltyType type;
    HiAdasAlgoResult result;
}HiAdasAlgoCapablityResult;

typedef struct {
    HiAdasAlgoCapablityResult resultList[HI_ADAS_MAX_CAP_NUM];
    HI_U32 resultNum;
    HI_BOOL isCalibrated;
}HiAdasAlgoProcessResult;

typedef struct {
    HI_BOOL isCached;
    HI_U64 phyAddr;
    const HI_CHAR* name;
}HiAdasAlgoMMZInfo;

typedef HI_VOID* (*HiAdasAlgoBufferAlloc)(HI_U32 bufSize, HiAdasAlgoMMZInfo* mmzInfo);

typedef HI_S32 (*HiAdasAlgoBufferFlush)(HI_VOID* virtualAddr, HI_U64 phyAddr, HI_U32 mmzBufSize);

typedef HI_S32 (*HiAdasAlgoBufferFree)(HI_VOID* virtualAddr, HI_U64 phyAddr);

typedef struct {
    HiAdasAlgoBufferAlloc allocCallback;
    HiAdasAlgoBufferFlush flushCallback;
    HiAdasAlgoBufferFree freeCallback;
    HiAdasCapabilityMask capMask;
    HiAdasCamAttr camAttr;
    HiAdasCalibrateAttr caliAttr;
    HI_FLOAT vehicleWidth;
    HI_FLOAT laneDistance;
    const HI_CHAR* modelPath;
}HiAdasAlgoPara;

typedef struct {
    HI_U8 data[HI_ADAS_INVOKE_BYTE_NUM];
    HI_U32 len;
}HiAdasCmdPara;

typedef struct {
    HI_CHAR algoName[HI_ADAS_MAX_NAME_LEN];
    HI_S32 (*GetCapability)(HiAdasCapability* capability);
    HI_S32 (*Init)(const HiAdasAlgoPara* initPara);
    HI_S32 (*Deinit)();
    HI_S32 (*ProcessImage)(const HiAdasImage* image, HiAdasAlgoProcessResult* result);
    HI_S32 (*SetAttr)(HiAdasAttrType type, const HiAdasAttr* attr);
    HI_S32 (*GetAttr)(HiAdasAttrType type, HiAdasAttr* attr);
    HI_S32 (*Invoke)(HI_U32 cmd, const HiAdasCmdPara* cmdPara);
}HiAdasAlgorithm;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
