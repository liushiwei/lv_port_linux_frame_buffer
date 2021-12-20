#include "HAL.h"

#include <string.h>

#include "hi_usb.h"
#include "hi_storagemng.h"

#include "hi_appcomm.h"
#include "hi_appcomm_log.h"

/* USB Storage */
#define USB_MMC_DEV_PATH        "/dev/mmcblk0p1"
#define USB_SYS_FILE_PATH       "/sys/devices/platform/soc/100e0000.hidwc3_0/gadget/lun0/file"
#define USB_STATE_PROC_PATH     "/proc/dwc3/100e0000.hidwc3_0/csts"


static HI_S32 USB_EventHandler(const HI_USB_EVENT_INFO_S *pstEventInfo)
{
    HI_S32 s32Ret = HI_SUCCESS;

    switch (pstEventInfo->s32EventId)
    {
        case HI_EVENT_USB_OUT:
        {
            MLOGI("USB OUT!\n");
            HI_USB_SetMode(HI_USB_MODE_CHARGE);
            break;
        }
        case HI_EVENT_USB_INSERT:
        {
            MLOGI("USB INSERT!\n");
            HI_CHAR *pazMode = (HI_CHAR *)"RW";
            HI_CHAR *pazPwd = (HI_CHAR *)"None";
            HI_USB_User_Login(pazMode, pazPwd);
            break;
        }
        case HI_EVENT_USB_UVC_READY:
            MLOGI("USB UVC READY!\n");
            break;
        case HI_EVENT_USB_STORAGE_READY:
            MLOGI("USB STORAGE READY!\n");
            break;
        case HI_EVENT_USB_HOSTUVC_READY:
            MLOGI("USB HOST UVC READY!\n");
            break;
        case HI_EVENT_USB_ACC_READY:
            MLOGI("USB ACC READY!\n");
            break;
        default:
            MLOGW("Invalid Event[%08x]\n", pstEventInfo->s32EventId);
            return HI_FAILURE;
    }

    return HI_SUCCESS;
}

static HI_S32 USB_GetStorageState(HI_VOID* pvPrivData)
{
    if (NULL == pvPrivData)
    {
        return HI_FAILURE;
    }

    HI_S32 s32Ret = HI_SUCCESS;
    HI_BOOL* pbStorageReady = (HI_BOOL*)pvPrivData;
    *pbStorageReady = HI_FALSE;

    HI_STORAGE_STATE_E enState = HI_STORAGE_STATE_IDEL;

    s32Ret = HI_STORAGEMNG_GetState("/app/sd", &enState);
    HI_APPCOMM_CHECK_RETURN(s32Ret, HI_FAILURE);
    MLOGI(YELLOW "Storage state(%d)\n" NONE, enState);

    if (HI_STORAGE_STATE_MOUNTED == enState)
    {
        *pbStorageReady = HI_TRUE;
    }

    return HI_SUCCESS;
}

/* USB Accessory Mode */
static HI_S32 USB_AccInit(HI_VOID)
{
    return HI_SUCCESS;
}

static HI_S32 USB_AccFlush(HI_VOID)
{
    return HI_SUCCESS;
}

static HI_S32 USB_AccWrite(HI_VOID* pvPrivData, HI_U32 u32len)
{
    return HI_SUCCESS;
}

static HI_S32 USB_AccRead(HI_VOID* pvPrivData, HI_U32 u32len)
{
    return HI_SUCCESS;
}


void HAL::USB_Init(void)
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_USB_CFG_S stCfg;

    HI_insmod(HI_APPFS_KOMOD_PATH"/dwc3.ko", NULL);

    memset(&stCfg, 0x0, sizeof(HI_USB_CFG_S));
    snprintf(stCfg.stStorageCfg.szProcFile, HI_APPCOMM_MAX_PATH_LEN, "%s", USB_STATE_PROC_PATH); 
    snprintf(stCfg.stStorageCfg.szSysFile, HI_APPCOMM_MAX_PATH_LEN, "%s", USB_SYS_FILE_PATH); 
    snprintf(stCfg.stStorageCfg.szDevPath, HI_APPCOMM_MAX_PATH_LEN, "%s", USB_MMC_DEV_PATH); 
    stCfg.pfnEventProc = USB_EventHandler;
    stCfg.pfnGetStorageState = USB_GetStorageState;
    stCfg.acc.pfnAccInit  = (ACC_INIT_FN_PTR)USB_AccInit;
    stCfg.acc.pfnAccFresh = (ACC_FRESH_FN_PTR)USB_AccFlush;
    stCfg.acc.pfnAccWrite = (ACC_WRITE_FN_PTR)USB_AccWrite;
    stCfg.acc.pfnAccRead  = (ACC_READ_FN_PTR)USB_AccRead;
    s32Ret = HI_USB_Init(&stCfg);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "USB Init");

    s32Ret = HI_USB_SetMode(HI_USB_MODE_CHARGE);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "Set USB Charge");

    return ;
}

