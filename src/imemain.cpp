
#include <Shlwapi.h>
#include <WinUser.h>
#include <Windows.h> // Windows API 核心函数和数据类型。
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <oleacc.h> // MSAA（Microsoft Active Accessibility）API。
#include <psapi.h>
#include <set>
#include <string>
#include <tchar.h> // TCHAR 类型及相关函数。
// Global variable.
HWINEVENTHOOK g_hook;
std::string filename = "config_ime.json";
std::set<std::string> softwareset;

VOID CALLBACK WinEventsProc(HWINEVENTHOOK hWinEventHook, DWORD dwEvent, HWND hwnd, LONG idObject, LONG idChild,
                            DWORD dwEventThread, DWORD dwmsEventTime)
{

    if (dwEvent == EVENT_OBJECT_FOCUS)
    {
        TCHAR FileName[256] = {0};
        DWORD processId;
        HANDLE hProcess;
        GetClassName(hwnd, FileName, 256);
        GetWindowThreadProcessId(hwnd, &processId);
        hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
        if (hProcess != NULL)
        {
            char buffer[MAX_PATH];
            if (GetModuleFileNameExA(hProcess, NULL, FileName, MAX_PATH))
            {
                LPSTR BaseName = PathFindFileNameA(FileName);
                std::string strBaseName(BaseName);
                if (softwareset.find(strBaseName) != softwareset.end())
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
                    // 存在
                }
                else
                {
                }
                // 进程的可执行文件名保存在buffer中
            }
            CloseHandle(hProcess);
        }

        // if (_tcscmp(szClassName, _T("Windows.UI.Core.CoreWindow")) == 0)
        // {
        // }
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
    std::ifstream file(filename);
    nlohmann::json root;

    if (file.fail())
    {
        // 如果配置文件不存在退出
        std::cout << filename << " doesn't exist, creating new JSON file" << std::endl;
        root["software"] = nlohmann::json::array();
        std::ofstream outfile(filename);
        outfile << root.dump(4) << std::endl;
        outfile.close();
        return 0;
    }
    else
    {
        file >> root;
        file.close();
        std::cout << root << std::endl;
        auto softwareArray = root["software"];
        for (auto &software : softwareArray)
        {
            std::string name = software.get<std::string>();
            softwareset.insert(name);
            std::cout << name << "\n";
        }
    }

    printf("start\n");
    InitializeMSAA();
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) != 0)
        ;
    ShutdownMSAA();
    return 0;
}
