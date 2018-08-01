																			 /*
-------- Tools.cpp ------------------------------------------------------------

		Copyright � 2018 ZZZ Ltd. - Bulgaria. All rights reserved.
-------------------------------------------------------------------------------
																			 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifdef _WIN32
	#include <share.h>	// SH_DENYNO
	#include <io.h>
#else
	#include <unistd.h>
#endif
#include <sstream>
#include "Tools.h"


using namespace std;


string ToUtf8(const wchar_t * in)
{
    string out;
    unsigned int codepoint = 0;
    for(;  *in != 0;  ++in)
    {
        if (*in >= 0xd800 && *in <= 0xdbff)
            codepoint = ((*in - 0xd800) << 10) + 0x10000;
        else
        {
            if (*in >= 0xdc00 && *in <= 0xdfff)
                codepoint |= *in - 0xdc00;
            else
                codepoint = *in;

            if (codepoint <= 0x7f)
                out.append(1, static_cast<char>(codepoint));
            else if (codepoint <= 0x7ff)
            {
                out.append(1, static_cast<char>(0xc0 | ((codepoint >> 6) & 0x1f)));
                out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
            }
            else if (codepoint <= 0xffff)
            {
                out.append(1, static_cast<char>(0xe0 | ((codepoint >> 12) & 0x0f)));
                out.append(1, static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
                out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
            }
            else
            {
                out.append(1, static_cast<char>(0xf0 | ((codepoint >> 18) & 0x07)));
                out.append(1, static_cast<char>(0x80 | ((codepoint >> 12) & 0x3f)));
                out.append(1, static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
                out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
            }
            codepoint = 0;
        }
    }
    return out;
}


double ToDouble(string const& numberString)
{
	double number = 0;
	stringstream ss(numberString);
	ss >> number;

	return number;
}


string ToString(double number)
{
	stringstream ss;
	ss << number;

	return ss.str();
}
