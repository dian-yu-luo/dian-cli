#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <fstream>
#include <spdlog/spdlog.h>

TEST_CASE("print")
{
    printf("hello\n");
}

#ifdef NOT_COMPILE
#include <Windows.h>
TEST_CASE("pos")
{
#include <windows.h>

    while (true)
    {
        POINT p;
        if (GetAsyncKeyState(VK_SPACE))
        {                                                  // 检查空格键是否被按下
            p.x = 700;                                     // 设置鼠标点击的横坐标
            p.y = 700;                                     // 设置鼠标点击的纵坐标
            SetCursorPos(p.x, p.y);                        // 将鼠标移动到指定位置
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); // 模拟鼠标左键按下事件
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);   // 模拟鼠标左键释放事件
            Sleep(10);                                     // 等待10毫秒
        }
    }
}

#include <filesystem>
TEST_CASE("get current path")
{
    std::filesystem::path path = std::filesystem::current_path();
    std::cout << "Executable path: " << path << '\n';
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        std::cout << entry.path() << std::endl; // 输出文件名
    }
}

TEST_CASE("this")
{
    printf("hello\n");
    for (int i = 0; i < 100; ++i)
    {
        std::cout << i << std::endl;
    }
}

TEST_CASE("hello endz")
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    printf("我的大兄弟啊\n");
    // Expect two strings not to be equal.

    for (size_t i = 0; i < 100; i++)
    {
        i++;
    }
    printf("hello\n");
}

TEST_CASE("hellozz end")
{
    spdlog::info("我的大兄弟啊");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}
#endif