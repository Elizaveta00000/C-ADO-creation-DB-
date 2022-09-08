
cls

@Del *.exe


call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"


:compile


Cl.exe /c /Zi /nologo /clr /W3 /WX- /O2 /Oi /Oy- /D WIN32 /D NDEBUG /D _CONSOLE /D _UNICODE /D UNICODE /Gm- /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope /Fo"RELEASE\\" /Fd"RELEASE\vc100.pdb" /Gd /TP /analyze- %~dp0CPP\lab1_5.cpp
Link.exe /OUT:lr1_5.exe /NOLOGO kernel32.lib legacy_stdio_definitions.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib CPP\oldnames.lib /PDB:"RELEASE\v100.pdb" /SUBSYSTEM:CONSOLE /MACHINE:X86 RELEASE\lab1_5.obj

del %~dp0RELEASE\*.pdb

del %~dp0RELEASE\*.obj

pause>nul