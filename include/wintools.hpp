#ifndef __wintools_H__
#define __wintools_H__
#include <iostream>
#include <vector>
#include <windows.h>

class WinTools
{
public:
	WinTools();
	WinTools(const WinTools &) = default;
	WinTools(WinTools &&) = default;
	WinTools &operator=(const WinTools &);
	WinTools &operator=(WinTools &&);

	~WinTools();
	void testwin();

private:
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

public:
	std::vector<std::string> window_titles_;
	void GetWindowTitles();
};

#endif // __wintools_H__