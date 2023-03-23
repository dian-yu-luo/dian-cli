#ifndef __wintools_H__
#define __wintools_H__
#include <iostream>
#include <windows.h>

class wintools
{
public:
	wintools();
	wintools(const wintools &) = default;
	wintools(wintools &&) = default;
	wintools &operator=(const wintools &);
	wintools &operator=(wintools &&);

	~wintools();
	void testwin();
};

#endif // __wintools_H__