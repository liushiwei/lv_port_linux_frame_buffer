#include "lvgl/lvgl.h"

#include "HAL.h"

#include "hi_hal_screen.h"
#include "hi_appcomm.h"
#include "hi_appcomm_util.h"
#include "hi_appcomm_log.h"

extern "C" {
    extern HI_HAL_SCREEN_OBJ_S stHALSCREENObj;
}


/**
  * @brief  �������Ƚ��䣬��lv_anim����
  * @param  obj:����
  * @param  brightness:����ֵ
  * @retval None
  */
static void Backlight_AnimCallback(void * obj, int32_t brightness)
{
    HAL::Backlight_SetValue(brightness);
}

/**
  * @brief  �����ʼ��
  * @param  ��
  * @retval ��
  */
void HAL::Backlight_Init()
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_U32 u32Luma = 60;

    s32Ret = HI_HAL_SCREEN_Register(HI_HAL_SCREEN_IDX_0, &stHALSCREENObj);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "SCREEN Register");

    s32Ret = HI_HAL_SCREEN_Init(HI_HAL_SCREEN_IDX_0);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN((HI_SUCCESS == s32Ret), "SCREEN Init");

    s32Ret = HI_HAL_SCREEN_SetLuma(HI_HAL_SCREEN_IDX_0, u32Luma);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN(HI_SUCCESS == s32Ret, "SetLuma");
}

/**
  * @brief  �������ã�����Ч��
  * @param  target:Ŀ������(0~1000 -> 0~100%)
  * @retval ��
  */
void HAL::Backlight_SetGradual(uint16_t target, uint16_t time)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)Backlight_AnimCallback);
    lv_anim_set_values(&a, Backlight_GetValue(), target);
    lv_anim_set_time(&a, time);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);

    lv_anim_start(&a);
}

/**
  * @brief  ��ȡ��������
  * @param  ��
  * @retval ��ǰ����(0~1000 -> 0~100%)
  */
uint16_t HAL::Backlight_GetValue()
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_U32 u32Luma = 60;

    s32Ret = HI_HAL_SCREEN_GetLuma(HI_HAL_SCREEN_IDX_0, &u32Luma);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN(HI_SUCCESS == s32Ret, "GetLuma");

    return (u32Luma * 100);
}

/**
  * @brief  ���ñ�������
  * @param  val: ����(0~1000 -> 0~100%)
  * @retval ��
  */
void HAL::Backlight_SetValue(int16_t val)
{
    HI_S32 s32Ret = HI_SUCCESS;
    HI_U32 u32Luma = 60;

    __LimitValue(val, 0, 1000);

    u32Luma = val / 100;
    s32Ret = HI_HAL_SCREEN_SetLuma(HI_HAL_SCREEN_IDX_0, u32Luma);
    HI_APPCOMM_CHECK_EXPR_WITHOUT_RETURN(HI_SUCCESS == s32Ret, "SetLuma");
}

/**
  * @brief  ����ǿ�Ƶ���
  * @param  en: ����ʹ��
  * @retval ��
  */
void HAL::Backlight_ForceLit(bool en)
{
}
