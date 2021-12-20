#include "HAL.h"

#include <string.h>

#include "hi_eventhub.h"
#include "hi_storagemng.h"

#include "hi_appcomm.h"
#include "hi_appcomm_util.h"
#include "hi_appcomm_log.h"

static bool SdcardReady = false;


static HI_S32 SD_FormatPreProc(const HI_CHAR* pszMntPath)
{
    MLOGI("SD Format Pre Process\n");
    return HI_SUCCESS;
}

static HI_S32 SD_EventHandler(HI_EVENT_S* pstEvent, HI_VOID* pvArgv)
{
    switch (pstEvent->EventID)
    {
        case HI_EVENT_STORAGEMNG_DEV_UNPLUGED:
        case HI_EVENT_STORAGEMNG_DEV_CONNECTING:
        case HI_EVENT_STORAGEMNG_DEV_ERROR:
        case HI_EVENT_STORAGEMNG_FS_CHECKING:
        case HI_EVENT_STORAGEMNG_FS_CHECK_FAILED:
        case HI_EVENT_STORAGEMNG_FS_EXCEPTION:
            break;
        case HI_EVENT_STORAGEMNG_MOUNTED:
            {
                MLOGI("sdcard mounted!\n");
                HI_mkdir("/" LV_FS_POSIX_PATH "" CONFIG_TRACK_RECORD_FILE_DIR_NAME, 0777);
                SdcardReady = true;
                break;
            }
        case HI_EVENT_STORAGEMNG_MOUNT_FAILED:
            {
                MLOGE("sdcard mount failed!\n");
                SdcardReady = false;
                break;
            }
        default:
            break;
    }

    return HI_SUCCESS;
}

static HI_S32 SD_SubscribeEvents(HI_VOID)
{
    static HI_BOOL bSubscribeFinish = HI_FALSE;
    HI_U32 i = 0;
    HI_S32 s32Ret = HI_SUCCESS;
    HI_SUBSCRIBER_S stSubscriber = {"SDCARD", SD_EventHandler, NULL, HI_FALSE};
    HI_MW_PTR SubscriberHdl = NULL;
    HI_EVENT_ID aEvents[] =
    {
        HI_EVENT_STORAGEMNG_DEV_UNPLUGED,
        HI_EVENT_STORAGEMNG_DEV_CONNECTING,
        HI_EVENT_STORAGEMNG_DEV_ERROR,
        HI_EVENT_STORAGEMNG_FS_CHECKING,
        HI_EVENT_STORAGEMNG_FS_CHECK_FAILED,
        HI_EVENT_STORAGEMNG_FS_EXCEPTION,
        HI_EVENT_STORAGEMNG_MOUNTED,
        HI_EVENT_STORAGEMNG_MOUNT_FAILED
    };

    if (bSubscribeFinish)
    {
        MLOGD("Events has been subscribed\n");
        return HI_SUCCESS;
    }

    s32Ret = HI_EVTHUB_CreateSubscriber(&stSubscriber, &SubscriberHdl);
    if (s32Ret)
    {
        MLOGE("CreateSubscriber failed. %#x\n", s32Ret);
        return HI_FAILURE;
    }

    HI_U32 u32ArraySize = ARRAY_SIZE(aEvents);

    for (i = 0; i < u32ArraySize; i++)
    {
        s32Ret = HI_EVTHUB_Subscribe(SubscriberHdl, aEvents[i]);
        if (s32Ret)
        {
            MLOGE("Subscribe Event(%#x) failed. %#x\n", aEvents[i], s32Ret);
            continue;
        }
    }

    bSubscribeFinish = HI_TRUE;
    return HI_SUCCESS;
}

static HI_VOID SD_WaitReady(HI_VOID)
{
    HI_U32 s32Cnt = 0;

    for (;;) {
        if (SdcardReady) {
            break;
        }

        s32Cnt ++;

        /* Timeout 10s */
        if (s32Cnt >= 100) {
            break;
        }

        HI_usleep(100 * 1000);
    }

    if (s32Cnt >= 100) {
        MLOGW("Wait Time Out!\n");
    }
}

bool HAL::SD_Init()
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_STORAGEMNG_CALLBACK_S stCallback;
    HI_STORAGEMNG_CFG_S stStorageMngCfg;

    s32Ret = HI_STORAGEMNG_RegisterEvent();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "STORAGEMNG RegisterEvent");

    memset(&stStorageMngCfg, 0x0, sizeof(HI_STORAGEMNG_CFG_S));
    snprintf(stStorageMngCfg.szMntPath, HI_APPCOMM_MAX_PATH_LEN, "%s", "/app/sd");
    snprintf(stStorageMngCfg.szDevPath, HI_APPCOMM_MAX_PATH_LEN, "%s", "/dev/mmcblk0p1");

    stCallback.pfnFormatPreProc = SD_FormatPreProc;
    s32Ret = HI_STORAGEMNG_Create(&stStorageMngCfg, &stCallback);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "STORAGEMNG Create");

    s32Ret = SD_SubscribeEvents();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "SD SubscribeEvents");

    SD_WaitReady();

    return true;
}

bool HAL::SD_GetReady()
{
    return SdcardReady;
}

float HAL::SD_GetCardSizeMB()
{
    /* default 64G */
    return 64 * 1024;
}

void HAL::SD_SetEventCallback(SD_CallbackFunction_t callback)
{
    
}

void HAL::SD_Update()
{
    
}

