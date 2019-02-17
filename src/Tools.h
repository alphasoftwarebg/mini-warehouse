																			 /*
-------- Tools.h --------------------------------------------------------------

	ZZZ Base Mini sample warehouse program

-------- © 2019 ZZZ Ltd. - Bulgaria -------------------------------------------
																			 */
#pragma once

#include <string>


std::string ToUtf8(const wchar_t * in);
double ToDouble(std::string const& numberString);
std::string ToString(double number);
int Open (const char* path, int flags, int mode);
