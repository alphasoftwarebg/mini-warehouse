																			 /*
-------- Tools.h --------------------------------------------------------------

		Copyright © 2018 ZZZ Ltd. - Bulgaria. All rights reserved.
-------------------------------------------------------------------------------
																			 */
#pragma once

#include <string>


std::string ToUtf8(const wchar_t * in);
double ToDouble(std::string const& numberString);
std::string ToString(double number);
