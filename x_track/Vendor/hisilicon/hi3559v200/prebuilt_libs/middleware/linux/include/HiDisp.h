#ifndef __HI_DISP_H__
#define __HI_DISP_H__



class HiDisp
{
public:

    HiDisp();
    virtual ~HiDisp();

    HI_S32 Open(HI_HANDLE dispHdl, HI_S32 width, HI_S32 height);
    HI_S32 Close();
    HI_S32 BindVProc(HI_HANDLE vpssHdl, HI_HANDLE vportHdl);
private:
    HI_HANDLE m_vpssHdl;
    HI_HANDLE m_vportHdl;
    HI_HANDLE m_dispHdl;
    HI_HANDLE m_wndHdl;
};

#endif //__HI_AUDIO_H__