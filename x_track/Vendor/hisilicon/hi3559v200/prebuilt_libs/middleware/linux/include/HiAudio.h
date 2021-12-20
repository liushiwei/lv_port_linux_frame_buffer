#ifndef __HI_AUDIO_H__
#define __HI_AUDIO_H__



class HiAudio
{
public:

    HiAudio();
    virtual ~HiAudio();

    HI_S32 Open(HI_HANDLE aoDev, HI_HANDLE aoChn);
    HI_S32 Close(HI_HANDLE aoDev, HI_HANDLE aoChn);
private:
};

#endif //__HI_AUDIO_H__