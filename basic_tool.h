#include <stdio.h>
#include <stdlib.h>

// TRUE FALSE
#define TRUE	1
#define FALSE	0



/*

// KEY
#define	LEFT	75
#define RIGHT	77
#define UP		72
#define	DOWN	80
#define ENTER	13

// COLOR CONSTANTS
#define C_BLACK		0
#define C_BLUE		1
#define C_GREEN		2
#define C_CYAN		3
#define C_RED		4
#define C_MAGENTA	5
#define C_YELLOW	6
#define C_WHITE		7
#define C_BRIGHT	8
#define C_BRIGHT_BLACK		8
#define C_BRIGHT_BLUE		9
#define C_BRIGHT_GREEN		10
#define C_BRIGHT_CYAN		11
#define C_BRIGHT_RED		12
#define C_BRIGHT_MAGENTA	13
#define C_BRIGHT_YELLOW		14
#define C_BRIGHT_WHITE		15

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

int selectByKey(int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y, char* cursor, char* (*recover)(int)) {
	int row_size = (tab_x==0)?1:(1+max_x-min_x)/tab_x;
	int current_x = min_x;
	int current_y = min_y;
	int result = 0;
	int i;

	while(TRUE) {
		setCursorPosition(current_x,current_y);
		printf("%s",cursor);
		char input = getch();
		setCursorPosition(current_x,current_y);
		printf("%s",recover(result));
		switch(input) {
		case LEFT:
			if(current_x-tab_x >= min_x) {
				current_x -= tab_x;
				result--;
			}
			break;
		case RIGHT:
			if(current_x+tab_x <= max_x) {
				current_x += tab_x;
				result++;
			}
			break;
		case UP:
			if(current_y-tab_y >= min_y) {
				current_y -= tab_y;
				result -= row_size;
			}
			break;
		case DOWN:
			if(current_y+tab_y <= max_y) {
				current_y += tab_y;
				result += row_size;
			}
			break;
		case ENTER:
			return result;
		}
	}
}*/