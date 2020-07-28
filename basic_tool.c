#include "basic_tool.h"

void setCursorPosition(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setCursorVisible(WINBOOL visible) {
    CONSOLE_CURSOR_INFO info;
    info.bVisible = visible;
	info.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}

void setCursorColor(int foreground, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),background<<4|foreground);
}