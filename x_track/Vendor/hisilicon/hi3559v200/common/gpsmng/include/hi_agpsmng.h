
#ifndef __HI_AGPSMNG_H__
#define __HI_AGPSMNG_H__

#include "hi_appcomm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


HI_S32 HI_AGPSMNG_Init(HI_VOID);


HI_S32 HI_AGPSMNG_CheckUpdate(HI_VOID);


HI_BOOL HI_AGPSMNG_GetUpdateState(HI_VOID);


HI_S32 HI_AGPSMNG_Update(HI_CHAR * cSerial, HI_CHAR * userNo);


HI_S32 HI_AGPSMNG_DeInit(HI_VOID);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
