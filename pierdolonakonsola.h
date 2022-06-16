#include "pch.h"
#include "windows.h"
#include <string>

// Aktualny Offset [ 0x21760 ] Conhost-V2.dll ConHost::Print

namespace FiveM
{


void printujemy(std::string rsnm, std::string msg)
{
    using chujoza = void(*)(std::string, std::string);
    const uintptr_t bazachuja = (uintptr_t)GetModuleHandleA("conhost-v2.dll");
    auto sendprintt = (chujoza)(bazachuja + 0x21760);
    sendprintt(rsnm, msg + "\n");
}
  
    
}




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        FiveM::printujemy("Suka","TESTWORK");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

