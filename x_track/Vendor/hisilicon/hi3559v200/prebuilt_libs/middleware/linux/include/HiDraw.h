#ifndef __HI_DRAW_H__
#define __HI_DRAW_H__

#include "hi_type.h"

class HiDraw
{
public:
    struct DrawContent
    {
    public:
        DrawContent(){}
        DrawContent(HI_S32 minX, HI_S32 minY, HI_S32 maxX, HI_S32 maxY,
            HI_U32 color, HI_HANDLE handle, std::string text)
            : m_minX(minX), m_minY(minY), m_maxX(maxX), m_maxY(maxY), m_color(color), m_text(text){}
        HI_S32 m_minX;
        HI_S32 m_minY;
        HI_S32 m_maxX;
        HI_S32 m_maxY;
        HI_U32 m_color;
        HI_HANDLE m_Handle;
        std::string m_text;
        HI_HANDLE m_modHdl;
        HI_HANDLE m_chnHdl;
    };

    HiDraw();
    virtual ~HiDraw();

    HI_S32 StartDrawBox(HI_HANDLE osdHdl, DrawContent& drawContent);
    HI_S32 StartDrawText(HI_HANDLE osdHdl, DrawContent& drawContent);
    HI_S32 StopDraw(HI_HANDLE osdHdl);
private:

};

#endif //__HI_DRAW_H__