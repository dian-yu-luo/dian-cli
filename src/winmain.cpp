#include <wintools.hpp>
#include <iostream>
#include <vector>
#include <string>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
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

int main()
{
    std::vector<std::string> window_titles;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&window_titles));

    for (const auto &title : window_titles)
    {
        std::cout << title << std::endl;
    }
    WinTools w;
    w.testwin();
    return 0;
}
