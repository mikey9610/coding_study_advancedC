#ifndef GAME1
#define GAME1

#include "basic_tool.h"

struct _g1_screenSize {
	int min_x;
	int max_x;
	int min_y;
	int max_y;
};

// 게임 실행
void g1_runGame();

// 각 라운드 진행
int g1_runRound(int);

// 배경 화면 출력
void g1_renderScreen();

#endif