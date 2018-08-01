/*
	Copyright (c) 2018 ZZZ Ltd. - Bulgaria

	Please read license at end of this file.
*/
#pragma once


#ifdef _WIN32
#include <windows.h>
#endif


namespace ZzzKernel
{

class ZZZConsole
{
public:
	static void Reset()
	{
		#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, 7);
		#else
		printf("\033[0m");
		#endif
	}
	static void Blue()
	{
		#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, 9);
		#else
		printf("\033[0;34m");
		#endif
	}
	static void Green()
	{
		#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, 10);
		#else
		printf("\033[0;32m");
		#endif
	}
	static void Yellow()
	{
		#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, 14);
		#else
		printf("\033[0;33m");
		#endif
	}
	static void Red()
	{
		#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, 12);
		#else
		printf("\033[0;31m");
		#endif
	}

private:
	#ifdef _WIN32
	static HANDLE hConsole;
	#endif
};

#ifdef _WIN32
HANDLE ZZZConsole::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

} // namespace ZzzKernel

/*
	License
*/