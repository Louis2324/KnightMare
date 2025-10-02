@echo off
setlocal enabledelayedexpansion

:: Config
set CXX=g++
set CXXFLAGS=-std=c++17 -Wall -Wextra -g
set TARGET=KnightMare.exe

:: Gather all source files manually 
set SRC=src\main.cpp src\ChessGame.cpp src\Move.cpp src\PieceMoves.cpp

:: Handle "clean" argument
if "%1"=="clean" (
    if exist %TARGET% (
        del %TARGET%
        echo Cleaned build artifacts.
    ) else (
        echo No build artifacts to clean.
    )
    goto :eof
)

:: Compile
echo Building %TARGET%...
%CXX% %CXXFLAGS% %SRC% -o %TARGET%

:: Check for success
if %errorlevel% neq 0 (
    echo Build failed.
    goto :eof
)

echo Build successful. Running %TARGET%...
echo -------------------------------
%TARGET%
