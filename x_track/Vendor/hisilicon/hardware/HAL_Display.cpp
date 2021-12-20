#include "HAL.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <semaphore.h>

#include "hi_gv_resm.h"
#include "hi_gv_parser.h"
#include "hi_gv.h"
#include "hi_gv_scrollgrid.h"
#include "hi_gv_input.h"
#include "hi_gv_msg.h"
#include "hi_gv_mlayer.h"
#include "hi_gv_log.h"

#include "hi_comm_vo.h"
#include "hi_mapi_sys.h"
#include "hi_mapi_disp.h"
#include "hi_mapi_disp_define.h"
#include "hi_mapi_vcap.h"

#include "hi_appcomm_msg_client.h"
#include "hi_notify_client.h"

#include "hi_eventhub.h"
#include "hi_keymng.h"

#include "hi_appcomm.h"
#include "hi_appcomm_util.h"
#include "hi_appcomm_log.h"


/* LCD Width and Height */
#ifndef LCD_WIDTH
#define LCD_WIDTH    (320)
#endif

#ifndef LCD_HEIGHT
#define LCD_HEIGHT   (240)
#endif

HI_HANDLE g_LCDLayerHandle = INVALID_HANDLE;


void HAL::Display_Init()
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_BOOL bStandBy = HI_TRUE; 

    s32Ret = HI_MSG_CLIENT_Init();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "CLIENT Init");

    s32Ret = HI_NOTIFY_CLIENT_Init();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "NOTIFY Init");

    s32Ret = HI_EVTHUB_Init();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "Eventhub Init");

    HI_KEYMNG_RegisterEvent();

    s32Ret = HI_MAPI_Sys_Init();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "Sys Init");

    s32Ret = HI_MAPI_DISP_StopWindow(0, 0);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "Stop Window");

    /* MMC */
    HI_insmod(HI_APPFS_KOMOD_PATH"/mmc_core.ko", NULL);
    HI_insmod(HI_APPFS_KOMOD_PATH"/mmc_block.ko", NULL);
    HI_insmod(HI_APPFS_KOMOD_PATH"/hisi_mci.ko",NULL);

    s32Ret = HI_GV_Init();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "HIGV Init");

    s32Ret = HI_GV_SetSWVsyncPeriod(16666); /** us */
    s32Ret |= HI_GV_SetLostFrameThreshold(8000); /** us */
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "SetSWVsyncPeriod or SetLostFrameThreshold");

    s32Ret = HI_GV_Log_SetLevel(HI_NULL, HIGV_LOG_FATAL);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "HI_GV_Log_SetLevel");

    HIGO_LAYER_E LayerID = HIGO_LAYER_HD_0;

    MLOGD(YELLOW "Screen Width:[%d], Height: [%d]\n" NONE,s32ScreenWidth, s32ScreenHeight);

    HIGO_LAYER_INFO_S LayerInfo = {
        LCD_WIDTH, LCD_HEIGHT, /*Screen*/
        LCD_WIDTH, LCD_HEIGHT, /*Canvas,  same as the window width,height in XML*/
        LCD_WIDTH, LCD_HEIGHT, /*Display */
        (HIGO_LAYER_FLUSHTYPE_E)(HIGO_LAYER_FLUSH_OVER),
        HIGO_LAYER_DEFLICKER_AUTO, HIGO_PF_8888,  LayerID};

    /* create graphical layer */
    s32Ret = HI_GV_Layer_Create(&LayerInfo, &g_LCDLayerHandle);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "Create Layer");

    HI_MAPI_DISP_CSCATTREX_S stAttrEx;
    stAttrEx.stVoCSC.enCscMatrix = VO_CSC_MATRIX_IDENTITY;
    stAttrEx.stVoCSC.u32Contrast = 50;
    stAttrEx.stVoCSC.u32Hue = 50;
    stAttrEx.stVoCSC.u32Luma = 50;
    stAttrEx.stVoCSC.u32Satuature = 50;
    s32Ret = HI_MAPI_DISP_SetAttrEx(0, HI_MAPI_DISP_CMD_GRAPHIC_CSC, 
            (HI_VOID *)&stAttrEx, sizeof(HI_MAPI_DISP_CSCATTREX_S));
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "SetAttrEx");

    s32Ret = HI_GV_RenderCmdSync();
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "RenderCmdSync");

    return ;
}


