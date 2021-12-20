#ifndef __HI_VIDEO_ENCODER_H__
#define __HI_VIDEO_ENCODER_H__
#include "HiMediaSystem.h"

class HiVideoEncoder
{
public:

    HiVideoEncoder();
    virtual ~HiVideoEncoder();

    HI_S32 Open(HI_HANDLE vencHdl, HI_U32 width, HI_U32 height, const HI_CHAR* saveFile);
    HI_S32 Close(HI_HANDLE vencHdl);
    HI_S32 Start(HI_HANDLE vencHdl);
    HI_S32 Stop(HI_HANDLE vencHdl);
    HI_S32 BindVProc(HI_HANDLE vpssHdl, HI_HANDLE vPortHdl, HI_HANDLE vencHdl);
    HI_S32 UnBindVProc(HI_HANDLE vpssHdl, HI_HANDLE vPortHdl, HI_HANDLE vencHdl);

private:
    HI_U32 mWidth;
    HI_U32 mHeight;

    HI_HANDLE mVencHdl;
    HI_HANDLE mVpssHdl;
    HI_BOOL mIsStop;
    HI_S32 mSaveFp;

};

#endif //__HI_VIDEO_ENCODER_H__