/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2029. All rights reserved.
 * Description: scaleView�ؼ��Ķ���ӿ�
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
/** @{ */ /** <!-- ScaleView widget�� */ /** <!--CNcomment:  ��ScaleView�ؼ��� */
typedef struct HIGV_SCALEVIEW_STYLE_S {
    HIGV_HANDLE dataModel; /* Data Model Handle ; CNcomment:  ����ģ�;�� */
    HI_U32 rowNum; /* The count of display item ; CNcomment: ��Ļ����ʾ������ */
    HI_U32 leftMargin; /* Left margin ; CNcomment:  ��߾� */
    HI_U32 rightMargin; /* Right margin ; CNcomment:  �ұ߾� */
    HI_U32 topMargin; /* Up margin ; CNcomment:  �ϱ߾� */
    HI_U32 bottomMargin; /* Bottom margin ; CNcomment:  �±߾� */
    HI_U32 imgDecIndex; /* imgDecIndex ; CNcomment:  ͼƬ������ */
    HI_U32 lineHeight;                 /* *< ˮƽ�����߸߶� */
    HI_U32 lineWidth;                 /* *< ˮƽ�����߿�� */
    HI_U32 lineDistance;                 /* *< ˮƽ�����ߵ���Ŀ���ݵľ��� */
    HI_U32 hlineColor; /* hlineColor ; CNcomment:  �����ߵ���ɫ */
    HI_U32 type;	    /* type ; CNcomment:  ��Ŀ���ݵ����� */
    HIGV_HANDLE scaleFont;	 /* scaleFont ; CNcomment:  ������  */
    HIGV_HANDLE normalFontFirst;	 /* normalFontFirst ; CNcomment:  ������  */
    HIGV_HANDLE nomalFont;	 /* nomalFont ; CNcomment:  ������  */
    HIGV_HANDLE normalFontSecond; /* normalFontSecond ; CNcomment:  ������ */
    // HIGV_HANDLE fontGrain; /* g_fontGrain ; CNcomment:  ����仯���� */
    HI_COLOR tapTxtColor; /* tapTxtColor ; CNcomment: ������ý����������ɫ */
    HI_S32 sizeGrain; /* *<ͼƬ��С�仯���� */
} HIGV_SCALEVIEW_STYLE;

/** @} */  /*! <!-- Structure Definition end */
/* * addtogroup      ScaleView        */
/* * ��ScaleView widget�� ; ��ScaleView�ؼ��� */
/**
* brief Initiatlize the scrollgird. CNcomment:ScaleView �ؼ���ʼ��
* attention : Set the head of ScaleView and row num.
* CNcomment:���ÿؼ��ı�ͷ(������)������
* param[in] hScaleView   ScaleView handle. CNcomment:ScaleView�ؼ����
* param[in] pStyle ScaleView handle.CNcomment:�ؼ���񲼾�����
* param[in] pColAttr ScaleView handle.CNcomment:����������
* param[in] CellColNum ScaleView handle.CNcomment:�������������Ԫ�ظ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* retval ::HI_ERR_COMM_NORES
*/
    HI_S32 HI_GV_SCALEVIEW_Create(const HIGV_WCREATE_S *creatInfo, HIGV_HANDLE *handleScaleView);
/**
\brief Set selected item of  ScaleView. CNcomment: ���� ScaleView������Ŀ
\attention \n
CNcomment:
\param[in] hScaleView ScaleView handle. CNcomment: �ؼ����
\param[in] Item  Item index.CNcomment: ��Ŀ���

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_GetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_SetSelItem(HIGV_HANDLE handleScaleView, HI_U32 item);
/**
\brief Get the item of ScaleView.CNcomment: ��ȡScaleView������Ŀ
\attention \n
N/A.CNcomment:��
\param[in] hScaleView  ScaleView handle.CNcomment: �ؼ����
\param[out] pItem Item index.CNcomment: ��Ŀ���

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_SetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_GetSelItem(HIGV_HANDLE handleScaleView, HI_U32 *selItem);
/**
\brief Get the total item number of ScaleView.CNcomment: ��ȡScaleView����Դ������
\attention \n
N/A.CNcomment:��
\param[in]  hScaleView  ScaleView handle. CNcomment:  �ؼ����
\param[out] pItemNum Toal item number.CNcomment: ����Ŀ��

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
N/A.CNcomment:��
*/

HI_S32 HI_GV_SCALEVIEW_GetItemNum(HIGV_HANDLE handleScaleView, HI_U32 *itemNum);
/**
brief Get the item of ScaleView.CNcomment: ��ȡScaleView����tap������Ŀ
\attention \n
N/A.CNcomment:��
\param[in] hScaleView  ScaleView handle.CNcomment: �ؼ����
\param[out] pItem Item index.CNcomment: ��Ŀ���

\retval ::HI_SUCCESS
\retval ::HI_ERR_COMM_LOST
\retval ::HI_ERR_COMM_INVAL

\see \n
::HI_GV_ScaleView_SetSelItem
*/
    HI_S32 HI_GV_SCALEVIEW_GetTapItem(HIGV_HANDLE handleScaleView, HI_U32 *tapItem);
/**
brief Get the item of ScaleView.CNcomment: ��ȡScaleView������Ŀ�仯�Ľ�����Ŀ���
\attention \n
N/A.CNcomment:��
\param[in] hScaleView  ScaleView handle.CNcomment: �ؼ����
\param[out] pItem Item index.CNcomment: ��Ŀ���

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
