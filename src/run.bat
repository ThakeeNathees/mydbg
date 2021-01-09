@echo off

:: msvc x86_64
if "%MSVC_INITIALIZED%" neq "" goto :L_COMPILATION_START

:: Find vswhere
if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" (
	set VSWHERE_PATH="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
) else ( if exist "%ProgramFiles%\Microsoft Visual Studio\Installer\vswhere.exe" (
	set VSWHERE_PATH="%ProgramFiles%\Microsoft Visual Studio\Installer\vswhere.exe"
) else (
	echo Error: can't find vswhere.exe required
	exit /B 1
))

:: Get the VC installation path
%VSWHERE_PATH% -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -latest -property installationPath > temp.txt
set /p VSWHERE_PATH= < temp.txt
del temp.txt
if not exist "%VSWHERE_PATH%" (
	echo Error: can't find VisualStudio installation directory
	exit /B 1
)
echo [make.bat] VS path found : %VSWHERE_PATH%

:: Initialize VC for X86_64
call "%VSWHERE_PATH%\VC\Auxiliary\Build\vcvars64.bat"

echo [make.bat] Initialized msvc x86_64
set MSVC_INITIALIZED=true

:L_COMPILATION_START

cl /I. /EHsc main.cpp
del main.obj

echo **********************************************************************
echo.
main
echo.
del main.exe

pause