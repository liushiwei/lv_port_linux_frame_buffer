#ifndef __HI_MEDIASYSTEM_H__
#define __HI_MEDIASYSTEM_H__

#include "hi_common.h"
#include "hi_comm_sys.h"
#include "hi_type.h"

#define CONVERT_64BIT_ADDR(Type,Addr) (Type*)(HI_UL)(Addr)

namespace HiADAS
{

class HiMediaSystem
{
public:
    static HI_S32 Init(HI_U32 vcapPipe, HI_U32 videoWidth, HI_U32 videoHeight);

    static HI_S32 Deinit(void);

    static HI_S32 MallocMem(HI_U64 *phyAddr, HI_VOID **virAddr, HI_U32 size, const HI_CHAR* pszMemName);

    static HI_S32 MallocMemCached(HI_U64 *phyAddr, HI_VOID **virAddr, HI_U32 size, const HI_CHAR* pszMemName);

    static HI_S32 FreeMem(HI_U64 phyAddr, HI_U64 virAddr);

    static HI_S32 FlushCache(HI_U64 phyAddr, HI_VOID *virAddr, HI_U32 size);

    static HI_U32 NowTime(HI_VOID);

private:
    static HI_S32 InitVB(HI_U32 vcapPipe, HI_U32 videoWidth, HI_U32 videoHeight);
};

}
#endif //__HI_MEDIASYSTEM_H__
