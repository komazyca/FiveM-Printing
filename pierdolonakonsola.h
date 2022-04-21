#include "pch.h"
#include "windows.h"
#include <string>

// Aktualny Offset [ 0x321D0 ] Conhost-V2.dll ConHost::Print

namespace FiveM
{



void pierdolenie()
{
    using potrzebnechuje = void(*)(std::string const&, std::string const&);
    auto printjanapawla = (potrzebnechuje)((DWORD64)GetModuleHandleA("conhost-v2.dll") + 0x321D0);
    printjanapawla("chujozajebana", "komazyca#3584"); 
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
        FiveM::pierdolenie();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

