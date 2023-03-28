#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// 定义日志文件名
const char *LOG_FILE = "log.txt";

// 后台进程函数
void daemon()
{
    // 打开日志文件
    ofstream log(LOG_FILE, ios::app);

    // 检查文件是否打开成功
    if (!log.is_open())
    {
        cerr << "Failed to open log file." << endl;
        return;
    }

    // 后台循环
    while (true)
    {
        // 获取当前窗口句柄
        HWND hwnd = GetForegroundWindow();

        // 获取窗口标题
        char title[256];
        GetWindowText(hwnd, title, sizeof(title));

        // 记录日志
        log << "Active window: " << title << endl;

        // 等待一段时间
        Sleep(1000);
    }
}

int main()
{
    // 创建后台进程
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)daemon, NULL, 0, NULL);

    // 检查进程是否创建成功
    if (hThread == NULL)
    {
        cerr << "Failed to create daemon thread." << endl;
        return -1;
    }

    // 等待进程退出
    WaitForSingleObject(hThread, INFINITE);

    // 关闭进程句柄
    CloseHandle(hThread);

    return 0;
}
