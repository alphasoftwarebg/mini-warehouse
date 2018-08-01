																			 /*
-------- main.cpp -------------------------------------------------------------

		Copyright © 2018 ZZZ Ltd. - Bulgaria. All rights reserved.
-------------------------------------------------------------------------------
																			 */
#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#endif
#include "Store.h"
#include "Tools.h"


using namespace std;


#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	vector<string> arguments;
	for(int i=1; i<argc; i++)
#ifdef _WIN32
		arguments.push_back(ToUtf8(reinterpret_cast<const wchar_t*>(argv[i])));
#else
		arguments.push_back(argv[i]);
#endif

	Store store;

	return store.CommandLine(arguments) ? 0:-1;
}