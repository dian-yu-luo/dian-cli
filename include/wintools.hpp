#ifndef __wintools_H__
#define __wintools_H__
#include <iostream>
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
};

#endif // __wintools_H__