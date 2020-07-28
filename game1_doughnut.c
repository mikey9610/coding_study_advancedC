#include "game1_doughnut.h"

struct _g1_screenSize g1_screenSize = {1,20,3,15};
// 전역 변수 global variable
// 화면 크기 정보 저장

const char g1_character[4] = "CH\0";
const char g1_doughnut[4] = "DD\0";
const char g1_stone[4] = "ST\0";

void g1_runGame() {
	int lv = 1;
	setCursorVisible(FALSE);
	while(lv<=3 && g1_runRound(lv)) lv++;
	setCursorVisible(TRUE);
}

int g1_runRound(int lv) {
	int bDoughnut;	// 현재 도넛 존재 여부
	COORD cDoughnut; // 현재 도넛 위치 x y
	char chInput; // 방향키 <- -> 입력 저장

	g1_renderScreen();

	while(TRUE) {
		if(bDoughnut) {	// 도넛 존재
			// 내리기

		}
		else {	// 도넛 존재 x
			// 도넛 만든다
			cDoughnut.X = rand()%(g1_screenSize.max_x-g1_screenSize.min_x+1)+g1_screenSize.min_x;	// 1-20
			// rand() : 0-6**** 중 하나의 값 반환
			cDoughnut.Y = g1_screenSize.min_y;
			bDoughnut = TRUE;
		}

		chInput = getch();
		// 키보드 값 아스키코드 저장
		switch(chInput) {
		case 75:	// LEFT

			break;
		case 77:	// RIGHT

			break;
		}
	}






	int nLife = 3;
	int nDoughnut = lv+2;
	int nCount = 0;
	int bDoughnut = FALSE;
	COORD cDoughnut;
	int current = (g1_screenInfo.max_x-g1_screenInfo.min_x)/2;
	char chInput;
/*
	// loading
	system("cls");
	for(int i=0; i<3; i++) {
		setCursorPosition(3,4);
		printf("==DOUGHNUT GAME==");
		setCursorPosition(3,6);
		printf("  Level %d Start",lv);
		setCursorPosition(3,8);
		printf("        %d",3-i);
		Sleep(1000);
	}
	system("cls");
*/
	g1_renderScreen();

	// game
	while(TRUE) {
		setCursorPosition(7,g1_screenInfo.min_y-2);
		printf("%d",nLife);
		setCursorPosition(21,g1_screenInfo.min_y-2);
		printf("%d",nDoughnut);
		if(bDoughnut == TRUE) {
			if(nCount%(50-lv*10) == 0) {
				setCursorPosition(cDoughnut.X,cDoughnut.Y);
				printf("  ");
				
				cDoughnut.Y++;

				setCursorPosition(cDoughnut.X,cDoughnut.Y);
				printf("%s",g1_doughnut);

				if(cDoughnut.Y==g1_screenInfo.max_y) {
					setCursorPosition(cDoughnut.X,cDoughnut.Y);
					printf("  ",g1_doughnut);
					bDoughnut = FALSE;
					if(current>=cDoughnut.X-1 && current<=cDoughnut.X+1) {
						if(nDoughnut == 0)	return TRUE;
						else				nDoughnut--;
					}
					else {
						if(nLife == 1)	return FALSE;
						else			nLife--;
					}
				}
			}
		}
		else {
			bDoughnut = TRUE;
			cDoughnut.X = rand()%(g1_screenInfo.max_x-g1_screenInfo.min_x);
			cDoughnut.Y = g1_screenInfo.min_y;
		}

		// input
		if(kbhit())	{
			chInput = getch();
			setCursorPosition(current,g1_screenInfo.max_y);
			printf("  ");

			switch(chInput) {
			case LEFT:
				if(g1_screenInfo.min_x <= current - 1)	current--;
				break;
			case RIGHT:
				if(g1_screenInfo.max_x > current + 1)	current++;
				break;
			}

			setCursorPosition(current,g1_screenInfo.max_y);
			printf("%s",g1_character);
		}
		
		Sleep(10);
		if(nCount == 119)	nCount = 0;
		else				nCount++;
	}
}

void g1_renderScreen() {
	system("cls");
	setCursorPosition(0,g1_screenSize.min_y-3);
	printf("DOUGHNUT GAME");
	setCursorPosition(0,g1_screenSize.min_y-2);
	printf("Life :");
	setCursorPosition(10,g1_screenSize.min_y-2);
	printf("Doughnut :");
	for(int i=g1_screenSize.min_x-1; i<=g1_screenSize.max_x+1; i++)	{
		setCursorPosition(i,g1_screenSize.min_y-1);
		printf("*");
		setCursorPosition(i,g1_screenSize.max_y+1);
		printf("*");
	}
	for(int i=g1_screenSize.min_y; i<g1_screenSize.max_y+1; i++) {
		setCursorPosition(g1_screenSize.min_x-1,i);
		printf("*");
		setCursorPosition(g1_screenSize.max_x+1,i);
		printf("*");
	}
	setCursorPosition((g1_screenSize.max_x-g1_screenSize.min_x)/2,g1_screenSize.max_y);
	//printf("%s",g1_character);
}