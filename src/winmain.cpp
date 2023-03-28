#include <wintools.hpp>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    system("chcp 65001 > nul");

    WinTools w;
    w.GetWindowTitles();
    int k = 0;
    for (auto &&i : w.window_titles_)
    {
        if (i.size() > 0)
        {
            std::cout << i << std::endl;
            k++;
        }
    }
    std::cout << "finally " << k << std::endl;

    return 0;
}
