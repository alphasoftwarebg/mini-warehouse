SET CDEBUG=-Ox -DNDEBUG
SET CFLAGS=-c -DCRTAPI1=_cdecl -DCRTAPI2=_cdecl -nologo -GS -D_X86_=1  -DWIN32 -D_WIN32 -W3 -D_WINNT -D_WIN32_WINNT=0x0500 -DNTDDI_VERSION=0x05000000 -D_WIN32_IE=0x0500 -DWINVER=0x0500 /EHsc /D "_UNICODE" /D "UNICODE" /D "_FILE_OFFSET_BITS=64" /D "ZZZ_BASE_MINI_DLL" /I ".\include"
SET CVARSDLL=-D_MT -D_DLL -MD

md obj
md bin

cl %CDEBUG% %CFLAGS% %CVARSDLL% /Fo".\obj\main.obj" src\main.cpp
cl %CDEBUG% %CFLAGS% %CVARSDLL% /Fo".\obj\Store.obj" src\Store.cpp
cl %CDEBUG% %CFLAGS% %CVARSDLL% /Fo".\obj\Tools.obj" src\Tools.cpp

link /RELEASE  /INCREMENTAL:NO /NOLOGO -subsystem:console,5.0 /MACHINE:X86 -out:bin\ZZZBaseMiniSamplesStore_Windows_32bit.exe /MANIFEST /MANIFESTFILE:"obj\ZZZBaseMiniSamplesStore_Windows_32bit.exe.intermediate.manifest" obj\main.obj obj\Store.obj obj\Tools.obj kernel32.lib  ws2_32.lib mswsock.lib advapi32.lib lib\ZZZBaseMini_Windows_32bit.lib

mt /outputresource:"bin\ZZZBaseMiniSamplesStore_Windows_32bit.exe;#1" /manifest "obj\ZZZBaseMiniSamplesStore_Windows_32bit.exe.intermediate.manifest"

copy /Y lib\ZZZBaseMini_Windows_32bit.dll bin
