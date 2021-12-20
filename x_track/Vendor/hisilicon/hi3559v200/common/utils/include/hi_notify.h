/**
 * @file    hi_notify.h
 * @brief   notify define.
 *
 * Copyright (c) 2019 Unionman Tech.Co.,Ltd
 *
 * @author    MinJie.YU
 * @date      2019/04/01
 * @version   1.0

 */
#ifndef __HI_NOTIFY_H__
#define __HI_NOTIFY_H__

#include "hi_list.h"
#include "hi_comm_ipcmsg.h"
#include "hi_appcomm.h"
#include <sys/time.h>
#include <sys/prctl.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/** \addtogroup     NOTIFY */
/** @{ */  /** <!-- [NOTIFY] */

#define HI_NOTIFY_SRVPORT (204)
#define HI_NOTIFY_SRVNAME "AppNOTIFY"

/** App NOTIFY BaseId : [28bit~31bit] unique */
#define HI_NOTIFY_BASEID (0x30000000L)

/** App NOTIFY ID Rule [ --base[4bit]--|--module[8bit]--|--msgid[20bit]--]
    * module : module enum value [HI_APP_MOD_E]
    * msgid : msg code in specified module, unique in module
    */
#define HI_NOTIFY_ID(module, msgid) \
    ((HI_S32)( (HI_NOTIFY_BASEID) | ((module) << 20 ) | (msgid) ))

/** App NOTIFY Buff size */
#define HI_NOTIFY_BUFF_NUM          (20)
#define HI_NOTIFY_MAX_BUFF          (2048)

/** msg id*/
#define NOTIFY_SYSTEM_INIT              HI_NOTIFY_ID(0, 0)
#define NOTIFY_SYSTEM_DEINIT            HI_NOTIFY_ID(0, 1)
#define NOTIFY_SYSTEM_SET_STATE         HI_NOTIFY_ID(0, 2)

/** this msg id is reserved*/
#define NOTIFY_ID_DISCONNECT        (0)
#define NOTIFY_ID_OPEN              (1)
#define NOTIFY_ID_CLOSE             (2)
#define NOTIFY_SEND_SYNC_TIMEOUT    (10000)

#define NOTIFY_INIT         (0)
#define NOTIFY_START        (1)
#define NOTIFY_PAUSE        (2)
#define NOTIFY_RESUME       (3)
#define NOTIFY_STOP         (4)
#define NOTIFY_DEINIT       (5)


typedef struct hiNOTIFY_PRIV_DATA_S
{
    HI_S32 as32PrivData[HI_IPCMSG_PRIVDATA_NUM];
} HI_NOTIFY_PRIV_DATA_S;

typedef struct hiNOTIFY_INFO_S
{
    pthread_t tPthreadId;
    HI_U64 u64Handle;
    HI_U64 u64PhyAddr;
} HI_NOTIFY_INFO_S;


typedef HI_S32 (*HI_NOTIFY_PROC_CALLBACK_FN_PTR)(HI_S32 s32MsgID, const HI_VOID* pvRequest, HI_U32 u32ReqLen, HI_NOTIFY_PRIV_DATA_S* pstPrivData,
                                                                    HI_VOID** ppvResponse, HI_U32* pu32RespLen, HI_VOID* pvUserData);

typedef struct tagNOTIFY_PROC_S
{
    HI_List_Head_S stList;
    HI_S32 s32MsgID;
    HI_NOTIFY_PROC_CALLBACK_FN_PTR pfnNotifyProc;
    HI_VOID* pvUserData;
} NOTIFY_PROC_S;

/**
 * @brief    register requst msg process function.
 * @param[in] s32MsgID:unique msg id.
 * @param[in] pfnMsgProc:msg process function.
 * @param[in] pvUserData:user data.
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_RegisterMsgProc(HI_S32 s32MsgID, HI_NOTIFY_PROC_CALLBACK_FN_PTR pfnMsgProc, HI_VOID* pvUserData);

/**
 * @brief    async send msg.
 * @param[in] s32MsgID:unique msg id.
 * @param[in] pvMsg:msg data.
 * @param[in] u32MsgLen:msg data lenght.
 * @param[in] pstPrivData:private data.
 * @return 0 success,non-zero error code.
 * @exception    the response will be in pfnRespProc.
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_SendASync(HI_S32 s32MsgID, const HI_VOID* pvMsg, HI_U32 u32MsgLen, HI_NOTIFY_PRIV_DATA_S* pstPrivData);

/**
 * @brief    sync send msg.
 * @param[in] s32MsgID:unique msg id.
 * @param[in] pvRequest:request data.
 * @param[in] u32ReqLen:request data lenght.
 * @param[in] pstPrivData:private data.
 * @param[out] pvResponse:response data.
 * @param[in] u32RespLen:response data lenght.
 * @return 0 success,non-zero error code.
 * @exception    None
 * @author    HiMobileCam Reference Develop Team
 * @date      2017/12/22
 */
HI_S32 HI_NOTIFY_SendSync(HI_S32 s32MsgID, const HI_VOID* pvRequest, HI_U32 u32ReqLen, HI_NOTIFY_PRIV_DATA_S* pstPrivData, HI_VOID* pvResponse, HI_U32 u32RespLen);

/** @}*/  /** <!-- ==== NOTIFY End ====*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_NOTIFY_H__ */
