#include "HAL.h"
#include "ButtonEvent/ButtonEvent.h"

#include "hi_keymng.h"
#include "hi_system.h"

#include "hi_hal_gps.h"
#include "hi_hal_key.h"
#include "hi_hal_screen.h"

#include "hi_appcomm.h"
#include "hi_appcomm_util.h"
#include "hi_appcomm_log.h"


/* Key Max number */
#define KEY_MAX_NUM         (6)

/** key check interval, unit ms */
#define KEY_CHECK_INTERVAL  (20)
/** key long click event period, check times */
#define KEY_LONGCLICK_CNT   (40)

typedef struct _KEY_INFO_S
{
    HI_HAL_KEY_IDX_E enKeyIdx;
    HI_HAL_KEY_STATE_E enKeyState;
    HI_BOOL bShortPressHappen;
    HI_BOOL bShortPress;
    HI_BOOL bLongPressHappen;
    HI_BOOL bLongPress;
    HI_BOOL bDoublePressHappen;
    HI_BOOL bDoublePress;
    HI_BOOL bMultiKeyFound;
    HI_U32 u32TimeTick;
    HI_U32 u32DoubleTimeTick;
} KEY_INFO_S;

static ButtonEvent EncoderPush(5000);

static bool EncoderEnable = true;
static volatile int32_t EncoderDiff = 0;
static bool EncoderDiffDisable = false;
static KEY_INFO_S KeyInfo[KEY_MAX_NUM];


static void Encoder_PushHandler(ButtonEvent* btn, int event)
{
    if(event == ButtonEvent::EVENT_PRESSED)
    {
        EncoderDiffDisable = true;
    }
    else if(event == ButtonEvent::EVENT_RELEASED)
    {
        EncoderDiffDisable = false;
    }
}

static HI_S32 Encoder_HoldCheck(HI_HAL_KEY_IDX_E enKeyIdx, KEY_INFO_S *pstKeyMngInfo)
{
    HI_U32 u32LongPressTime = 1000;/* unit:ms, if pressed 1s, key is on hold */
    HI_U32 u32ShortPressTime = 40;
    HI_U32 u32DoublePressTime = 40;

    /* Time tick count */
    pstKeyMngInfo->u32TimeTick ++;
    pstKeyMngInfo->u32DoubleTimeTick ++;
    
    if (HI_SUCCESS != HI_HAL_KEY_GetState(pstKeyMngInfo->enKeyIdx, &pstKeyMngInfo->enKeyState))
    {
        return HI_FAILURE;
    }

    if ((HI_HAL_KEY_STATE_DOWN == pstKeyMngInfo->enKeyState) && (enKeyIdx == pstKeyMngInfo->enKeyIdx))
    {
        if (HI_FALSE == pstKeyMngInfo->bShortPressHappen)
        {
            pstKeyMngInfo->bShortPressHappen = HI_TRUE;
            pstKeyMngInfo->u32TimeTick = 0;
        }
        else if (HI_TRUE == pstKeyMngInfo->bShortPressHappen)
        {
            if (pstKeyMngInfo->u32TimeTick > (u32LongPressTime / KEY_CHECK_INTERVAL)) 
            {
                pstKeyMngInfo->bShortPressHappen = HI_FALSE;
                if (HI_TRUE != pstKeyMngInfo->bLongPress)
                {
                    pstKeyMngInfo->bLongPress = HI_TRUE;

                    /* Hold Event */
                    if (HI_HAL_KEY_IDX_4 == enKeyIdx) /* Power Key */
                    {
                        MLOGI("Power Off.\n");
                        HI_HAL_GPS_Deinit();
                        HI_SYSTEM_Poweroff();
                    }
                }
            }
        }  
    }

    if ((HI_HAL_KEY_STATE_UP == pstKeyMngInfo->enKeyState) && (enKeyIdx == pstKeyMngInfo->enKeyIdx))
    {
        if (HI_TRUE == pstKeyMngInfo->bShortPressHappen)
        {
            pstKeyMngInfo->bShortPressHappen = HI_FALSE;
            if (HI_FALSE == pstKeyMngInfo->bDoublePressHappen)
            {
                pstKeyMngInfo->bDoublePressHappen = HI_TRUE;
                pstKeyMngInfo->u32DoubleTimeTick = 0;
            }
            else
            {
                if (pstKeyMngInfo->u32DoubleTimeTick < (u32DoublePressTime / KEY_CHECK_INTERVAL)) 
                {
                    pstKeyMngInfo->bDoublePressHappen = HI_FALSE;
                    if (HI_TRUE == pstKeyMngInfo->bLongPress)
                    {
                        pstKeyMngInfo->bLongPress = HI_FALSE;
                    }
                
                    pstKeyMngInfo->bDoublePress = HI_TRUE;

                    /* DOWN Event */
                    if (HI_HAL_KEY_IDX_1 == enKeyIdx) /* UP Key */
                    {
                        EncoderDiff -= 1;
                    }
                    else if (HI_HAL_KEY_IDX_2 == enKeyIdx) /* DOWN Key */
                    {
                        EncoderDiff += 1;
                    }
                }
            }
        }
        else if (HI_TRUE == pstKeyMngInfo->bDoublePressHappen)
        {
            if (pstKeyMngInfo->u32DoubleTimeTick > (u32ShortPressTime / KEY_CHECK_INTERVAL))
            {
                pstKeyMngInfo->bDoublePressHappen = HI_FALSE;
                
                if (HI_TRUE == pstKeyMngInfo->bLongPress)
                {
                    pstKeyMngInfo->bLongPress = HI_FALSE;
                    pstKeyMngInfo->bShortPress = HI_TRUE;
                }
                else
                {
                    pstKeyMngInfo->bShortPress = HI_TRUE;

                    /* DOWN Event */
                    if (HI_HAL_KEY_IDX_1 == enKeyIdx)
                    {
                        EncoderDiff -= 1;
                    }
                    else if (HI_HAL_KEY_IDX_2 == enKeyIdx)
                    {
                        EncoderDiff += 1;
                    }
                    else if (HI_HAL_KEY_IDX_4 == enKeyIdx) /* Power Key */
                    {
                        HI_HAL_SCREEN_STATE_E enDisplayState = HI_HAL_SCREEN_STATE_ON;
                        HI_HAL_SCREEN_GetDisplayState(HI_HAL_SCREEN_IDX_0, &enDisplayState);

                        if (HI_HAL_SCREEN_STATE_ON == enDisplayState)
                        {
                            HI_HAL_SCREEN_SetBackLightState(HI_HAL_SCREEN_IDX_0, HI_HAL_SCREEN_STATE_OFF);
                            HI_HAL_SCREEN_SetDisplayState(HI_HAL_SCREEN_IDX_0, HI_HAL_SCREEN_STATE_OFF);
                        }
                        else if (HI_HAL_SCREEN_STATE_OFF == enDisplayState) 
                        {
                            HI_HAL_SCREEN_SetDisplayState(HI_HAL_SCREEN_IDX_0, HI_HAL_SCREEN_STATE_ON);
                            HI_usleep(200 * 1000);
                            HI_HAL_SCREEN_SetBackLightState(HI_HAL_SCREEN_IDX_0, HI_HAL_SCREEN_STATE_ON);
                        }
                    }
                }
            }  
        }  
    }  

    if ((HI_HAL_KEY_STATE_UP == pstKeyMngInfo->enKeyState) && (enKeyIdx == pstKeyMngInfo->enKeyIdx))
    {
        if ((HI_TRUE == pstKeyMngInfo->bShortPress) || (HI_TRUE == pstKeyMngInfo->bDoublePress))
        {
            pstKeyMngInfo->bShortPress  = HI_FALSE;
            pstKeyMngInfo->bDoublePress = HI_FALSE;
            pstKeyMngInfo->bMultiKeyFound = HI_FALSE;

            /* UP Event */
            /* DO NOTHING */
        }
    }

    return HI_SUCCESS;
}

static HI_VOID *Encoder_Thread(HI_VOID* pData)
{
    HI_U32 u32TypeIdx = 0;

    HI_usleep(1000 * 1000);

    for (;;)
    {
        if (!EncoderEnable || EncoderDiffDisable)
        {
            HI_usleep(KEY_CHECK_INTERVAL * 1000);
            continue;
        }

        Encoder_HoldCheck(HI_HAL_KEY_IDX_1, &KeyInfo[HI_HAL_KEY_IDX_1]);
        Encoder_HoldCheck(HI_HAL_KEY_IDX_2, &KeyInfo[HI_HAL_KEY_IDX_2]);
        Encoder_HoldCheck(HI_HAL_KEY_IDX_4, &KeyInfo[HI_HAL_KEY_IDX_4]);

        HI_usleep(KEY_CHECK_INTERVAL * 1000);
    }

    return NULL;
}

void HAL::Encoder_Init()
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_U32 u32Idx = 0;
    pthread_t ThreadId;

    (void)HI_HAL_KEY_Init();

    /* KeyInfo Init */
    memset(&KeyInfo, 0, sizeof(KeyInfo));

    for (u32Idx = 0;  u32Idx < KEY_MAX_NUM;  ++u32Idx)
    {
        KeyInfo[u32Idx].enKeyState = HI_HAL_KEY_STATE_UP;
        KeyInfo[u32Idx].enKeyIdx = (HI_HAL_KEY_IDX_E)u32Idx;
        KeyInfo[u32Idx].bMultiKeyFound = HI_FALSE;
    }

    s32Ret = pthread_create(&ThreadId, NULL, Encoder_Thread, NULL);
    if (s32Ret != HI_SUCCESS)
    {
        MLOGE("Create KeyCheck Thread Fail!\n");
    }

    EncoderPush.EventAttach(Encoder_PushHandler);
}

void HAL::Encoder_Update()
{
    EncoderPush.EventMonitor(Encoder_GetIsPush());
}

int32_t HAL::Encoder_GetDiff()
{
    int32_t diff = EncoderDiff;
    EncoderDiff = 0;
    return diff;
}

bool HAL::Encoder_GetIsPush()
{
    HI_HAL_KEY_IDX_E enKeyIdx = HI_HAL_KEY_IDX_0; /* Enter */
    HI_HAL_KEY_STATE_E enKeyState = HI_HAL_KEY_STATE_UP;

    if(!EncoderEnable)
    {
        return false;
    }

    (void)HI_HAL_KEY_GetState(enKeyIdx, &enKeyState);

    return (HI_HAL_KEY_STATE_DOWN == enKeyState);
}

void HAL::Encoder_SetEnable(bool en)
{
    EncoderEnable = en;
}

