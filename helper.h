#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>

inline void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

inline int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD                      result;
    if (!GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &csbi
    ))
        return -1;
    return result.X;
}

inline int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD                      result;
    if (!GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &csbi
    ))
        return -1;
    return result.Y;
}