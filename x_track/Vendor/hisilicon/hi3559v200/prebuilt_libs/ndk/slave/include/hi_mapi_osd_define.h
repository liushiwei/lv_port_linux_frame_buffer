/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 *
 * @file    hi_mapi_osd_define.h
 * @brief   osd module
 * @author  HiMobileCam NDK develop team
 * @date  2019-7-19
 */
#ifndef __HI_OSD_DEFINE_H__
#define __HI_OSD_DEFINE_H__

#include "hi_comm_region.h"
#include "hi_mapi_comm_define.h"
#include "hi_mapi_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/* error code for osd */
#define HI_MAPI_OSD_EHANDLE_ILLEGAL \
    HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_INVALID_CHNID)
#define HI_MAPI_OSD_EILLEGAL_PARAM \
    HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_ILLEGAL_PARAM)
#define HI_MAPI_OSD_ENULL_PTR   HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_NULL_PTR)
#define HI_MAPI_OSD_ENOT_PERM   HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_NOT_PERM)
#define HI_MAPI_OSD_ENOMEM      HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_NOMEM)
#define HI_MAPI_OSD_ENOT_INITED HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_SYS_NOTREADY)
#define HI_MAPI_OSD_ENOFONT HI_MAPI_DEF_ERR(HI_MAPI_MOD_OSD, MAPI_EN_ERR_LEVEL_ERROR, MAPI_EN_ERR_NO_FONT)



/** Maximum OSD Count */
#define HI_MAPI_OSD_MAX_CNT  (16)

/** Maximum Display Count for Each OSD */
#define HI_MAPI_OSD_MAX_DISP_CNT (4)

/** String OSD Maximum Length */
#define HI_MAPI_OSD_MAX_STR_LEN  (64)

/** osd len 19, such as `2017-01-01 00:00:00` */
#define HI_MAPI_OSD_TIME_MAX_LEN    (19)


/** struct define */
/** OSD Type Enum */
typedef enum hiMAPI_OSD_TYPE_E {
    HI_MAPI_OSD_TYPE_TIME = 0,
    HI_MAPI_OSD_TYPE_STRING,
    HI_MAPI_OSD_TYPE_BITMAP,
    HI_MAPI_OSD_TYPE_CIRCLE,
    HI_MAPI_OSD_TYPE_BUTT
} HI_MAPI_OSD_TYPE_E;

/** OSD Time Format Enum */
typedef enum hiMAPI_OSD_TIMEFMT_E {
    HI_MAPI_OSD_TIMEFMT_YMD24H = 0, /**< eg. 2017-03-10 23:00:59 */
    HI_MAPI_OSD_TIMEFMT_BUTT
} HI_MAPI_OSD_TIMEFMT_E;

/** OSD Binded Module enum */
typedef enum hiMAPI_OSD_BIND_MOD_E {
    HI_MAPI_OSD_BINDMOD_VCAP = 0,
    HI_MAPI_OSD_BINDMOD_VPROC,
    HI_MAPI_OSD_BINDMOD_STITCH,
    HI_MAPI_OSD_BINDMOD_VENC,
    HI_MAPI_OSD_BINDMOD_DISP,
    HI_MAPI_OSD_BINDMOD_BUTT
} HI_MAPI_OSD_BIND_MOD_E;

typedef enum hiMAPI_OSD_COORDINATE_E {
    HI_MAPI_OSD_COORDINATE_RATIO_COOR = 0,   /* Ratio coordinate. */
    HI_MAPI_OSD_COORDINATE_ABS_COOR          /* Absolute coordinate. */
} HI_MAPI_OSD_COORDINATE_E;

/** OSD Display Attribute */
typedef struct hiMAPI_OSD_DISP_ATTR_S {
    HI_BOOL bShow;
    HI_MAPI_OSD_BIND_MOD_E enBindedMod; /**< OSD Binded Module: Static  */
    HI_HANDLE ModHdl; /**< Binded Module  Handle: Static eg.VcapPipeHdl VpssHdl  StitchHdl     DispHdl */
    HI_HANDLE ChnHdl; /**< Binded Channel Handle: Static eg.PipeChnHdl  VPortHdl StitchPortHdl WndHdl  VencHdl */
    HI_U32  u32FgAlpha;
    HI_U32  u32BgAlpha;
    HI_MAPI_OSD_COORDINATE_E enCoordinate;   /**< Coordinate mode of the osd start Position. */
    POINT_S stStartPos; /**< OSD Start Position */
    ATTACH_DEST_E enAttachDest; /**< only for venc */
    HI_U32 u32Batch;
} HI_MAPI_OSD_DISP_ATTR_S;

/** osd pixel format enum */
typedef enum hiMAPI_OSD_PIXEL_FMT_E {
    HI_MAPI_OSD_PIXEL_FMT_RGB1555 = 0,
    HI_MAPI_OSD_PIXEL_FMT_BUTT
} HI_MAPI_OSD_PIXEL_FMT_E;

typedef struct hiMAPI_OSD_TIME_CONTENT_S {
    HI_MAPI_OSD_TIMEFMT_E enTimeFmt;
    SIZE_S  stFontSize;
    HI_U32  u32BgColor;
}HI_MAPI_OSD_TIME_CONTENT_S;

typedef struct hiMAPI_OSD_STR_CONTENT_S {
    HI_CHAR szStr[HI_MAPI_OSD_MAX_STR_LEN];
    SIZE_S  stFontSize;
    HI_U32  u32BgColor;
}HI_MAPI_OSD_STR_CONTENT_S;

typedef struct hiMAPI_OSD_CIRCLE_CONTENT_S {
    HI_U32             u32Width;
    HI_U32             u32Height;
}HI_MAPI_OSD_CIRCLE_CONTENT_S;


typedef struct hiMAPI_OSD_CONTENT_S {
    HI_MAPI_OSD_TYPE_E enType;
    HI_U32  u32Color;
    union {
        HI_MAPI_OSD_TIME_CONTENT_S stTimeContent;
        HI_MAPI_OSD_STR_CONTENT_S stStrContent;
        HI_MAPI_OSD_CIRCLE_CONTENT_S stCircleContent;
        BITMAP_S stBitmapContent;
    };
} HI_MAPI_OSD_CONTENT_S;

/* OSD Parameter */
typedef struct hiMAPI_OSD_ATTR_S {
    HI_U32 u32DispNum; /* Binded Display Number for this OSD */
    HI_MAPI_OSD_DISP_ATTR_S astDispAttr[HI_MAPI_OSD_MAX_DISP_CNT];
    HI_MAPI_OSD_CONTENT_S stContent;
} HI_MAPI_OSD_ATTR_S;

typedef HI_S32 (*HI_MAPI_OSD_GETFONTMOD_CALLBACK_FN_PTR)(HI_U8 *pazStr, HI_U8* pBuf, HI_S32 s32BufLen);

/* OSD Fonts Lib */
typedef struct hiMAPI_OSD_FONTS_S {
    /* OSD Lib Font Size, in pixel */
    HI_U32 u32FontWidth;
    HI_U32 u32FontHeight;
    HI_MAPI_OSD_GETFONTMOD_CALLBACK_FN_PTR pfnGetFontMod;
} HI_MAPI_OSD_FONTS_S;

typedef struct hiMAPI_POSITION_DATA_S
{
    HI_BOOL valid;
    HI_FLOAT latitude;
    HI_FLOAT longitude;
} HI_MAPI_POSITION_DATA_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_OSD_DEFINE_H__ */
