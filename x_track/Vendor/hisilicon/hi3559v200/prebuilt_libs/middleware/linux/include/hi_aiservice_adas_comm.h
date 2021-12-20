/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: adas common define
 * Author: HiMobileCam middleware develop team
 * Create: 2019-07-30
 */

#ifndef HI_AISERVICE_ADAS_COMM_H
#define HI_AISERVICE_ADAS_COMM_H

#include "hi_type.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* only permit combining values of HiAdasCapabiltyType*/
typedef HI_U32 HiAdasCapabilityMask;

/* only permit combining values of HiAdasImageDataType*/
typedef HI_U32 HiAdasImgDataTypeMask;

#define MAX_SLI_SIGNS_PER_FRAME 5

#define MAX_CARS_PER_IMG 10

#define MAX_LANE_POINTS_NUM 100

#define MAX_LANES_PER_IMG 5

#define MAX_PEDESTRIAN_PER_IMG 20

#define HI_ADAS_MAX_NAME_LEN 128

typedef enum {
    HI_ADAS_CAP_SLI = 1 << 1,
    HI_ADAS_CAP_FCR = 1 << 2,//forward car reminder
    HI_ADAS_CAP_LDW = 1 << 3,
    HI_ADAS_CAP_PCW = 1 << 4,
    HI_ADAS_CAP_FCW = 1 << 5,
    HI_ADAS_CAP_BUTT
}HiAdasCapabiltyType;

typedef enum {
    HI_AIENGINE_IMAGE_TYPE_BGR = 1 << 1,
    HI_AIENGINE_IMAGE_TYPE_YVU420SP = 1 << 2,
    HI_AIENGINE_IMAGE_TYPE_YVU422SP = 1 << 3,
    HI_AIENGINE_IMAGE_TYPE_BUTT
}HiAdasImageDataType;

typedef enum {
    HI_ADAS_SLI_TYPE_5= 0x00,            /* Define 5 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_10,          /* Define 10 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_15,          /* Define 15 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_20,          /* Define 20 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_25,          /* Define 25 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_30,          /* Define 30 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_35,          /* Define 35 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_40,          /* Define 40 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_50,          /* Define 50 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_60,          /* Define 60 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_70,          /* Define 70 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_80,          /* Define 80 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_90,          /* Define 90 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_100,         /* Define 100 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_110,         /* Define 110 km/h of the limit speed */
    HI_ADAS_SLI_TYPE_120          /* Define 120 km/h of the limit speed */
}HiAdasSliType;

typedef enum {
    HI_ADAS_SENSITIVITY_LOW,
    HI_ADAS_SENSITIVITY_MID,
    HI_ADAS_SENSITIVITY_HIGH,
    HI_ADAS_SENSITIVITY_BUTT
}HiAdasSensitivity;

typedef enum {
    HI_ADAS_OBSTACLE_CAR = 0x00,
    HI_ADAS_OBSTACLE_BUS,
    HI_ADAS_OBSTACLE_TRUCK,
    HI_ADAS_OBSTACLE_PERSON,
    HI_ADAS_OBSTACLE_BICYCLE,
    HI_ADAS_OBSTACLE_MOTOR,
    HI_ADAS_OBSTACLE_BUTT
}HiAdasObstacleType;

typedef enum {
    HI_ADAS_LDW_LEFT_WARNING,
    HI_ADAS_LDW_RIGHT_WARNING,
    HI_ADAS_LDW_BUTT
}HiAdasLdwWarnType;

typedef enum {
    HI_ADAS_ATTR_SLI_ENABLE = 0x00,
    HI_ADAS_ATTR_FCW_ENABLE = 0x100,
    HI_ADAS_ATTR_FCW_SENSITIVITY,
    HI_ADAS_ATTR_FCW_MIN_VELOCITY,
    HI_ADAS_ATTR_FCW_TTC_LIMIT,
    HI_ADAS_ATTR_LDW_ENABLE = 0x200,
    HI_ADAS_ATTR_LDW_SENSITIVITY,
    HI_ADAS_ATTR_LDW_MIN_VELOCITY,
    HI_ADAS_ATTR_PCW_ENABLE = 0x300,
    HI_ADAS_ATTR_PCW_TTC_LIMIT,
    HI_ADAS_ATTR_FCR_ENABLE = 0x400,
    HI_ADAS_ATTR_CALIBRATE = 0x500,
    HI_ADAS_ATTR_BUTT
}HiAdasAttrType;

typedef enum {
    HI_ADAS_WARN_LEVEL_NORMAL = 0x00,
    HI_ADAS_WARN_LEVEL_WARN,
    HI_ADAS_WARN_LEVEL_DANGER,
    HI_ADAS_WARN_LEVEL_EMERGENCY,
    HI_ADAS_WARN_BUTT
}HiAdasWarnLevel;

typedef struct {
    HI_S32 x;
    HI_S32 y;
    HI_S32 width;
    HI_S32 height;
}HiAdasBBox;

typedef struct {
    HiAdasImageDataType imageType;
    HI_U64 virAddr;
    HI_U64 phyAddr;
    HI_U32 stride;
    HI_U32 width;
    HI_U32 height;
    HI_U32 imgUid;
} HiAdasImage;

typedef struct {
    HI_U32 x;
    HI_U32 y;
}HiAdasPoint;

typedef struct {
    HiAdasBBox bbox;
    HI_U32 uid;
    HiAdasSliType speedType;
    HI_FLOAT confidence;
} HiAdasSliSign;

typedef struct {
    HiAdasPoint points[MAX_LANE_POINTS_NUM];
    HI_U32 pointsNum;
}HiAdasLane;

typedef struct {
    HiAdasSensitivity ldwSensitivity;
    HI_S32 ldwMinVelocity;
}HiAdasLdwAttr;

typedef struct {
    HiAdasLdwWarnType warnType;
    HiAdasLane lanes[MAX_LANES_PER_IMG];
    HI_U32 laneNum;
    HI_U8 leftLaneIdx;
    HI_U8 rightLaneIdx;
}HiAdasAlgoLdwResult;

typedef struct {
    HI_U32 uid;
    HiAdasBBox bbox;
    HiAdasObstacleType type;
    HI_FLOAT distance;
    HI_FLOAT ttc;
    HI_FLOAT confidence;
}HiAdasObstacle;

typedef struct {
    HiAdasWarnLevel warnType;
    HiAdasObstacle obstacle;
}HiAdasCollisonObstacle;

typedef struct {
    HiAdasCapabilityMask capMask;
    HiAdasImgDataTypeMask imgTypeMask;
    HI_U32 inputImgWidth;
    HI_U32 inputImgHeight;
    HI_U32 maxFps;
}HiAdasCapability;

typedef struct {
    HiAdasPoint vanishPoint;
}HiAdasCalibrateResult;

typedef struct {
    HI_FLOAT camHeight;
    HI_FLOAT camFocusLength;
    HI_FLOAT horizontalPixelLength;
    HI_FLOAT verticalPixelLength;
}HiAdasCamAttr;

typedef struct {
    HI_BOOL isCalibrated;
    HiAdasPoint vanishPoint;
}HiAdasCalibrateAttr;

typedef struct {
    HiAdasSensitivity fcwSensitivity;
    HI_S32 fcwMinVelocity;
}HiAdasFcwAttr;

/* time to collision , unit second*/
typedef struct {
    HI_FLOAT warnTtc;
    HI_FLOAT dangerTtc;
    HI_FLOAT emergencyTtc;
}HiAdasTtcLimitAttr;

typedef struct {
    union {
        HI_BOOL isSliEnable;
        HI_BOOL isFcwEnable;
        HiAdasSensitivity fcwSensitivity;
        HI_S32 fcwMinVelocity;
        HiAdasTtcLimitAttr fcwTtcLimit;
        HI_BOOL isLdwEnable;
        HiAdasSensitivity ldwSensitivity;
        HI_S32 ldwMinVelocity;
        HI_BOOL isPcwEnable;
        HiAdasTtcLimitAttr pcwTtcLimit;
        HI_BOOL isFcrEnable;
        HiAdasCalibrateAttr caliAttr;
    };
}HiAdasAttr;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
