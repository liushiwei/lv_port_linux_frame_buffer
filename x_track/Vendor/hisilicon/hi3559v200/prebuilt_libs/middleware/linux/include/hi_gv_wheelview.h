/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description: hi_gv_wheelview.h
 * Author: NULL
 * Create: 2009-2-9
 */

#ifndef __HI_GV_WHEELVIEW_H__
#define __HI_GV_WHEELVIEW_H__
#include "hi_gv_conf.h"
#include "hi_gv.h"

#ifdef HIGV_USE_WIDGET_WHEELVIEW
/* add include here */
#include "hi_gv_resm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ************************** Structure Definition *************************** */
/* * addtogroup      Wheelview     */
/* * ��Wheelview widget�� ; CNcomment:  ��wheelview�ؼ��� */
typedef struct tagHigvWheelViewStyle {
    HI_U32 rowNum; /* The count of display item ; CNcomment: ��Ļ����ʾ������ */
    HIGV_HANDLE dataModel; /* Data Model Handle ; CNcomment:  ����ģ�;�� */
    HIGV_HANDLE upCoverSkin; /* Up Cover Skin ; CNcomment: �ϸ���Ƥ����� */
    HIGV_HANDLE downCoverSkin; /* Down Cover Skin; CNcomment: �¸���Ƥ����� */
    HI_BOOL isCircleScroll; /*Circle tag ; CNcomment: ѭ��������־ */
    HI_FLOAT scrollParam; /* Scroll Param ; CNcomment: ����������ϵ�� */
    HI_FLOAT flingParam; /* Fling Param ; CNcomment: ��ɨ������ϵ�� */
    HI_U32 leftMargin; /* Left margin ; CNcomment:  ��߾� */
    HI_U32 rightMargin; /* Right margin ; CNcomment:  �ұ߾� */
    HI_U32 topMargin; /* Up margin ; CNcomment:  �ϱ߾� */
    HI_U32 btmMargin; /* Bottom margin ; CNcomment:  �±߾� */
} HigvWheelViewStyle;

/* *  -- Structure Definition end */
/* ****************************** API declaration **************************** */
/* * addtogroup      Wheelview     */
/* *  ��wheelview widget��  CNcomment:  ��wheelview�ؼ��� */
/**
* brief Create wheelview.CNcomment:WheelView�ؼ���ʼ��
* param[in] pCreatInfo    The Layout infomation of wheelview. CNcomment:�ؼ���񲼾�����ָ��
* param[out] phWheelView   the pointer of wheelview handle. CNcomment:WheelView�ؼ����ָ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_INVA
* retval ::HI_ERR_COMM_NORES
*/
HI_S32 HI_GV_WheelView_Create(const HIGV_WCREATE_S *pCreatInfo, HIGV_HANDLE *phWheelView);

/**
* brief Set selected item of  wheelview. CNcomment: ���� WheelView��ǰ��Ŀ
* param[in] hWheelview WheelView handle. CNcomment: �ؼ����
* param[in] Item  Item index.CNcomment: ��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_WheelView_GetSelItem
*/
HI_S32 HI_GV_WheelView_SetSelItem(HIGV_HANDLE hWheelview, HI_U32 Item);

/**
* brief Get the item of WheelView.CNcomment: ��ȡWheelView��ǰ��Ŀ
* param[in] hWheelview  WheelView handle.CNcomment: �ؼ����
* param[out] pItem Item index.CNcomment: ��Ŀ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
* see ::HI_GV_WheelView_SetSelItem
*/
HI_S32 HI_GV_WheelView_GetSelItem(HIGV_HANDLE hWheelview, HI_U32 *pItem);

/**
* brief Get the total item number of WheelView.CNcomment: ��ȡWheelView��ǰ����������
* param[in]  hWheelview  WheelView handle. CNcomment:  �ؼ����
* param[out] pItemNum Toal item number.CNcomment: ����Ŀ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_GetItemNum(HIGV_HANDLE hWheelview, HI_U32 *pItemNum);

/**
* brief Set up image resource.CNcomment:�������ڵ�Ƥ����Դ
* param[in] hWheelview Image handle.CNcomment:�ؼ����
* param[in] hRes The resource ID of image.CNcomment:ͼƬ��Դ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetUpImage(HIGV_HANDLE hWheelview, HI_RESID hRes);

/**
* brief Set up image resource.CNcomment:�������ڵ�Ƥ����Դ
* param[in] hWheelview Image handle.CNcomment:�ؼ����
* param[in] hRes The resource ID of image.CNcomment:ͼƬ��Դ���
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetDownImage(HIGV_HANDLE hWheelview, HI_RESID hRes);

/**
* brief Enable wheelview touch.CNcomment:��������������
* param[in] hWheelview Image handle.CNcomment:�ؼ����
* param[in] bEnable  Enable flag.CNcomment: ʹ�ܱ�־��HI_TRUE��ʾʹ�ܣ�HI_FALSE��ʾȥʹ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_Enable(HIGV_HANDLE hWheelview, HI_BOOL bEnable);

/**
* brief Is touch enable.CNcomment:��ȡ�Ƿ�������״̬
* param[in] hWheelview Image handle.CNcomment:�ؼ����
* retval ::HI_TRUE  Touch is Enable.CNcomment: ��������
* retval ::HI_FALSE Touch is Disable.CNcomment: ��������
*/
HI_BOOL HI_GV_WheelView_IsEnable(HIGV_HANDLE hWheelview);

/**
* rief Set scroll param.CNcomment:���û���������ϵ��(Ĭ��Ϊ1.0�����ڵ���1.0)
* param[in] hWheelview wheelview handle.    CNcomment:�ؼ����
* param[in] ScrollParam scroll index.    CNcomment:����������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetScrollParam(HIGV_HANDLE hWheelview, HI_FLOAT ScrollParam);

/**
* brief Set fling param.CNcomment:������ɨ������ϵ��(Ĭ��Ϊ1.0�����ڵ���1.0)
* param[in] hWheelview wheelview handle.    CNcomment:�ؼ����
* param[in] FlingParam fling index.    CNcomment:��ɨ������ϵ��
* retval ::HI_SUCCESS
* retval ::HI_ERR_COMM_LOST
* retval ::HI_ERR_COMM_INVAL
*/
HI_S32 HI_GV_WheelView_SetFlingParam(HIGV_HANDLE hWheelview, HI_FLOAT FlingParam);

/*  API declaration end ==== */
#ifdef __cplusplus
}
#endif
#endif
#endif /* __HI_GV_WHEELVIEW_H__ */
