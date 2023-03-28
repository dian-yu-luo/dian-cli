#include "wintools.hpp"

WinTools::WinTools()
{
}

WinTools::~WinTools()
{
}

void WinTools::testwin()
{
    printf("hello test iwn\n");
}

BOOL CALLBACK WinTools::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    std::vector<std::string> *window_titles = reinterpret_cast<std::vector<std::string> *>(lParam);
    if (IsWindowVisible(hwnd))
    {
        HWND parent = GetWindow(hwnd, GW_OWNER);
        if (parent == NULL)
        {
            char title[1024];
            GetWindowText(hwnd, title, sizeof(title));
            window_titles->push_back(std::string(title));
        }
    }
    return TRUE;
}

void WinTools::GetWindowTitles()
{
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&window_titles_));
}