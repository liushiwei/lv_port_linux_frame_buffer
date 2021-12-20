#ifndef __HI_VIDEO_CAPTURE_H__
#define __HI_VIDEO_CAPTURE_H__

#include "hi_type.h"


class HiVideoCapture
{
public:

    HiVideoCapture();
    virtual ~HiVideoCapture();

    HI_S32 Open(HI_HANDLE vpssHdl, HI_HANDLE vcapPipe, HI_U32 width, HI_U32 height);
    HI_S32 Close(HI_VOID);

private:
    HI_S32 InitVB();
    HI_S32 OpenVI(HI_VOID);
    HI_S32 CloseVI(HI_VOID);
    HI_S32 OpenVPSS(HI_VOID);
    HI_S32 CloseVPSS(HI_VOID);

    HI_U32 mPreviewWidth;
    HI_U32 mPreviewHeight;




    HI_HANDLE mVpssHdl;
    HI_HANDLE mVCapDev;
    HI_HANDLE mVCapPipe;
    HI_HANDLE mPipeChn;
};

#endif //__HI_VIDEO_CAPTURE_H__