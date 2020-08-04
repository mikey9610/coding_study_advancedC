#include "game1_doughnut.h"

struct _g1_screenSize g1_screenSize = {1,20,3,15};
// 전역 변수 global variable
// 화면 크기 정보 저장

const char g1_character[4] = "★\0";
const char g1_doughnut[4] = "◎\0";

void g1_runGame() {
	int lv = 1;
	setCursorVisible(FALSE);
	while(lv<=3 && g1_runRound(lv)) lv++;
	if(lv==4) {
		system("cls");
		printf("Doughnut Game Success!!!\n");
		system("pause");
	}
	else {
		system("cls");
		printf("Doughnut Game Failed...\n");
		system("pause");
	}
	setCursorVisible(TRUE);
}

int g1_runRound(int lv) {
	int bDoughnut;	// 현재 도넛 존재 여부
	COORD cDoughnut; // 현재 도넛 위치 x y
	char chInput; // 방향키 <- -> 입력 저장
	int nCount = 0; // 반복문 현재 반복 횟수 저장
	int cCharacter = (g1_screenSize.min_x+g1_screenSize.max_x)/2; // 현재 캐릭터 위치 x
	int nDoughnut = lv+2;	// 현재 남은 도넛 개수
	int nLife = 3;		// 현재 남은 목숨 개수
	
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

	g1_renderScreen();

	setCursorPosition(cCharacter,g1_screenSize.max_y);
	printf("%s",g1_character);
	// 캐릭터 처음 위치에 그리기

	while(TRUE) {
		setCursorPosition(7,g1_screenSize.min_y-2);
		printf("%d",nLife);
		setCursorPosition(21,g1_screenSize.min_y-2);
		printf("%d",nDoughnut);
		// 화면에 목숨 도넛 개수 출력

		if(bDoughnut) {	// 도넛 존재
			if(nCount%(50-lv*10) == 0) {	// 일정 시간이 지날 때마다 도넛 이동 수행
				setCursorPosition(cDoughnut.X,cDoughnut.Y);
				printf("  ");	// 현재 위치 도넛 지우기
				
				cDoughnut.Y++;	// 도넛 y 위치 1 증가

				setCursorPosition(cDoughnut.X,cDoughnut.Y);
				printf("%s",g1_doughnut);	// 새로운 위치 도넛 그리기
				
				if(cDoughnut.Y == g1_screenSize.max_y) {	// 도넛이 맨 아래칸에 도착
					setCursorPosition(cDoughnut.X,cDoughnut.Y);
					printf("  ",g1_doughnut);	// 바닥 도착 시 도넛 지우기

					bDoughnut = FALSE;	// 도넛 더이상 존재 x
					if(cCharacter >= cDoughnut.X-1 && cCharacter <= cDoughnut.X+1) {	// 캐릭터 도넛 부딪힘
						if(nDoughnut == 1)	return TRUE;	// 해당 라운드 이겨서 종료
						else				nDoughnut--;	// 현재 남은 도넛 -1
					}
					else {	// 도넛 바닥 부딪힘
						if(nLife == 1)	return FALSE;	// 해당 라운드 져서 종료
						else			nLife--;		// 현재 남은 목숨 -1
					}
				}
			}
		}
		else {	// 도넛 존재 x
			// 도넛 만든다
			// rand() : 0-6**** 중 하나의 값 반환
			cDoughnut.X = rand()%(g1_screenSize.max_x-g1_screenSize.min_x+1)+g1_screenSize.min_x;	// 1-20
			cDoughnut.Y = g1_screenSize.min_y;
			bDoughnut = TRUE;
		}

		if(kbhit()) {	// 키보드 입력이 들어왔을 때
			chInput = getch();
			// 키보드 값 아스키코드 저장

			setCursorPosition(cCharacter,g1_screenSize.max_y);
			printf("  ");
			// 현재 위치 캐릭터 지우기

			switch(chInput) {
			case 75:	// LEFT	
				if(g1_screenSize.min_x <= cCharacter-1)	cCharacter--;
					// 캐릭터가 왼쪽으로 이동했을 때,
					// 그 위치가 끝 위치보다 크거나 같으면 이동 / 아니면 이동 x
				break;
			case 77:	// RIGHT
				if(g1_screenSize.max_x >= cCharacter+2)	cCharacter++;
					// 캐릭터가 오른쪽으로 이동했을 때,
					// 그 위치가 끝 위치보다 작거나 같으면 이동 / 아니면 이동 x
				break;
			}

			setCursorPosition(cCharacter,g1_screenSize.max_y);
			printf("%s",g1_character);
			// 새로운 위치 캐릭터 그리기
		}

		Sleep(10);	// 0.01초 프로그램 정지
		if(nCount == 119)	nCount = 0;
		else				nCount++;	// nCount 오버 플로우 방지
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
}