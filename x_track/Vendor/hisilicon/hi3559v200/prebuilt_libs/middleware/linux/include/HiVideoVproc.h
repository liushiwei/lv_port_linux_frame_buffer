#ifndef __HI_VIDEO_VPROC_H__
#define __HI_VIDEO_VORC_H__

#include "hi_type.h"

typedef struct {
    HI_U64 virAddr;
    HI_U64 phyAddr;
    HI_U32 stride;
    HI_U32 width;
    HI_U32 height;
    HI_U64 imgPts;
} HiImage;

class HiVideoVproc
{
public:

    HiVideoVproc();
    HiVideoVproc(HI_S32 width, HI_S32 height);
    virtual ~HiVideoVproc();

    HI_S32 GetFrame(HI_HANDLE grpHdl, HI_HANDLE portHdl,HiImage& image);
    HI_S32 ReleaseFrame(HI_HANDLE grpHdl, HI_HANDLE portHdl,HiImage& image);
    HI_S32 SendFrame(HI_HANDLE vpssHdl ,HiImage& image);

    HI_S32 StartPort(HI_HANDLE vpssHdl, HI_HANDLE portHdl);
    HI_S32 StopPort(HI_HANDLE vpssHdl, HI_HANDLE portHdl);
    HI_S32 StartDumpPort(HI_HANDLE vpssHdl, HI_HANDLE portHdl);

    HI_S32 ResizeImg(HiImage& inImage, HiImage& outImage);
private:
    HI_VOID* m_image;
    HI_U32 m_width;
    HI_U32 m_height;
};

#endif //__HI_VIDEO_ENCODER_H__