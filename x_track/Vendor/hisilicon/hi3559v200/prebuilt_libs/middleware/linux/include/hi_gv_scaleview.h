/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2029. All rights reserved.
 * Description: scaleView控件的对外接口
 * Author: NULL
 * Create: 2019-8-9
 */

#ifndef HI_GV_SCALE_VIEW_H
#define HI_GV_SCALE_VIEW_H
#include "hi_gv_conf.h"
#include "hi_gv.h"

#ifdef HIGV_USE_WIDGET_SCALEVIEW
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif


/*************************** Structure Definition ****************************/
/** \addtogroup      ScaleView     */
/** @{ */ /** <!-- ScaleView widget】 */ /** <!--CNcomment:  【ScaleView控件】 */
typedef struct HIGV_SCALEVIEW_STYLE_S {
    HIGV_HANDLE dataModel; /* Data Model Handle ; CNcomment:  数据模型句柄 */
    HI_U32 rowNum; /* The count of display item ; CNcomment: 屏幕上显示的行数 */
    HI_U32 leftMargin; /* Left margin ; CNcomment:  左边距 */
    HI_U32 rightMargin; /* Right margin ; CNcomment:  右边距 */
    HI_U32 topMargin; /* Up margin ; CNcomment:  上边距 */
    HI_U32 bottomMargin; /* Bottom margin ; CNcomment:  下边距 */
    HI_U32 imgDecIndex; /* imgDecIndex ; CNcomment:  图片索引号 */
    HI_U32 lineHeight;                 /* *< 水平网格线高度 */
    HI_U32 lineWidth;                 /* *< 水平网格线宽度 */
    HI_U32 lineDistance;                 /* *< 水平网格线到条目内容的距离 */
    HI_U32 hlineColor; /* hlineColor ; CNcomment:  网格线的颜色 */
    HI_U32 type;	    /* type ; CNcomment:  条目内容的类型 */
    HIGV_HANDLE scaleFont;	 /* scaleFont ; CNcomment:  字体句柄  */
    HIGV_HANDLE normalFontFirst;	 /* normalFontFirst ; CNcomment:  字体句柄  */
    HIGV_HANDLE nomalFont;	 /* nomalFont ; CNcomment:  字体句柄  */
    HIGV_HANDLE normalFontSecond; /* normalFontSecond ; CNcomment:  字体句柄 */
    // HIGV_HANDLE fontGrain; /* g_fontGrain ; CNcomment:  字体变化粒度 */
    HI_COLOR tapTxtColor; /* tapTxtColor ; CNcomment: 点击后获得焦点的字体颜色 */
    HI_S32 sizeGrain; /* *<图片大小变化粒度 */
} HIGV_SCALEVIEW_STYLE;

/** @} */  /*! <!-- Structure Definition end */
/* * addtogroup      ScaleView        */
/* * 【ScaleView widget】 ; 【ScaleView控件】 */
/**
* brief Initiatlize the scrollgird. CNcomment:ScaleView 控件初始化
* attention : Set the head of ScaleView and row num.
* CNcomment:设置控件的表头(行属性)和行数
* param[in] hScaleView   ScaleView handle. CNcomment:ScaleView控件句柄
* param[in] pStyle ScaleView handle.CNcomment:控件风格布局属性
* param[in] pColAttr ScaleView handle.CNcomment:列属性数组
* param[in] CellColNum ScaleView handle.CNcomment:列属性数组包含元素个数
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
    HI_S32 HI_GV_SCALEVIEW_Create(const HIGV_WCREATE_S *creatInfo, HIGV_HANDLE *handleScaleView);
/**
\brief Set selected item of  ScaleView. CNcomment: 设置 ScaleView焦点条目
\attention \n
CNcomment:
\param[in] hScaleView ScaleView handle. CNcomment: 控件句柄
\param[in] Item  Item index.CNcomment: 条目编号

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_GetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_SetSelItem(HIGV_HANDLE handleScaleView, HI_U32 item);
/**
\brief Get the item of ScaleView.CNcomment: 获取ScaleView焦点条目
\attention \n
N/A.CNcomment:无
\param[in] hScaleView  ScaleView handle.CNcomment: 控件句柄
\param[out] pItem Item index.CNcomment: 条目编号

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_SetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_GetSelItem(HIGV_HANDLE handleScaleView, HI_U32 *selItem);
/**
\brief Get the total item number of ScaleView.CNcomment: 获取ScaleView数据源总条数
\attention \n
N/A.CNcomment:无
\param[in]  hScaleView  ScaleView handle. CNcomment:  控件句柄
\param[out] pItemNum Toal item number.CNcomment: 总条目数

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
N/A.CNcomment:无
*/

HI_S32 HI_GV_SCALEVIEW_GetItemNum(HIGV_HANDLE handleScaleView, HI_U32 *itemNum);
/**
brief Get the item of ScaleView.CNcomment: 获取ScaleView手势tap焦点条目
\attention \n
N/A.CNcomment:无
\param[in] hScaleView  ScaleView handle.CNcomment: 控件句柄
\param[out] pItem Item index.CNcomment: 条目编号

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_SetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_GetTapItem(HIGV_HANDLE handleScaleView, HI_U32 *tapItem);
/**
brief Get the item of ScaleView.CNcomment: 获取ScaleView滑动条目变化的焦点条目编号
\attention \n
N/A.CNcomment:无
\param[in] hScaleView  ScaleView handle.CNcomment: 控件句柄
\param[out] pItem Item index.CNcomment: 条目编号

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_SetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_GetFoucItem(HIGV_HANDLE handleScaleView, HI_U32 *itemNum);
/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
}
#endif
#endif
#endif /* HI_GV_SCALEVIEW_H */
