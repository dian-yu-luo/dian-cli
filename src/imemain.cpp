/*
g++ ime.cpp -o ime.exe -limm32 -mwindows
*/

#include <Windows.h> // Windows API 核心函数和数据类型。
#include <WinUser.h>
#include <oleacc.h> // MSAA（Microsoft Active Accessibility）API。
#include <iostream>
#include <tchar.h> // TCHAR 类型及相关函数。
// Global variable.
HWINEVENTHOOK g_hook;

VOID CALLBACK WinEventsProc(HWINEVENTHOOK hWinEventHook, DWORD dwEvent, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime)
{

    if (dwEvent == EVENT_OBJECT_FOCUS)
    {
        TCHAR szClassName[256] = {0};
        GetClassName(hwnd, szClassName, 256);
        if (_tcscmp(szClassName, _T("Windows.UI.Core.CoreWindow")) == 0)
        {
            constexpr LPARAM IMC_GETOPENSTATUS = 5;
            constexpr LPARAM IMC_SETOPENSTATUS = 6;
            auto ime = ImmGetDefaultIMEWnd(hwnd);
            LPARAM stat;
            stat = SendMessage(ime, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0);
            std::printf("init ime state: %d\n", stat);
            SendMessage(ime, WM_IME_CONTROL, IMC_SETOPENSTATUS, 0);
            stat = SendMessage(ime, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0);

            std::printf("current ime state: %d\n\n", stat);
        }
    }
}
void InitializeMSAA()
{
    g_hook = SetWinEventHook(EVENT_MIN, EVENT_MAX, NULL, WinEventsProc, 0, 0, WINEVENT_OUTOFCONTEXT);
}

// Unhooks the event and shuts down COM.
//
void ShutdownMSAA()
{
    UnhookWinEvent(g_hook);
}

// Callback function that handles events.

int main(int argc, char const *argv[])
{
    printf("start\n");
    InitializeMSAA();
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) != 0)
        ;
    ShutdownMSAA();
    return 0;
}
