#include "game1_doughnut.h"

struct _g1_screenSize g1_screenSize = {1,20,3,15};
// ���� ���� global variable
// ȭ�� ũ�� ���� ����

const char g1_character[4] = "��\0";
const char g1_doughnut[4] = "��\0";

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
	int bDoughnut;	// ���� ���� ���� ����
	COORD cDoughnut; // ���� ���� ��ġ x y
	char chInput; // ����Ű <- -> �Է� ����
	int nCount = 0; // �ݺ��� ���� �ݺ� Ƚ�� ����
	int cCharacter = (g1_screenSize.min_x+g1_screenSize.max_x)/2; // ���� ĳ���� ��ġ x
	int nDoughnut = lv+2;	// ���� ���� ���� ����
	int nLife = 3;		// ���� ���� ��� ����
	
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
	// ĳ���� ó�� ��ġ�� �׸���

	while(TRUE) {
		setCursorPosition(7,g1_screenSize.min_y-2);
		printf("%d",nLife);
		setCursorPosition(21,g1_screenSize.min_y-2);
		printf("%d",nDoughnut);
		// ȭ�鿡 ��� ���� ���� ���

		if(bDoughnut) {	// ���� ����
			if(nCount%(50-lv*10) == 0) {	// ���� �ð��� ���� ������ ���� �̵� ����
				setCursorPosition(cDoughnut.X,cDoughnut.Y);
				printf("  ");	// ���� ��ġ ���� �����
				
				cDoughnut.Y++;	// ���� y ��ġ 1 ����

				setCursorPosition(cDoughnut.X,cDoughnut.Y);
				printf("%s",g1_doughnut);	// ���ο� ��ġ ���� �׸���
				
				if(cDoughnut.Y == g1_screenSize.max_y) {	// ������ �� �Ʒ�ĭ�� ����
					setCursorPosition(cDoughnut.X,cDoughnut.Y);
					printf("  ",g1_doughnut);	// �ٴ� ���� �� ���� �����

					bDoughnut = FALSE;	// ���� ���̻� ���� x
					if(cCharacter >= cDoughnut.X-1 && cCharacter <= cDoughnut.X+1) {	// ĳ���� ���� �ε���
						if(nDoughnut == 1)	return TRUE;	// �ش� ���� �̰ܼ� ����
						else				nDoughnut--;	// ���� ���� ���� -1
					}
					else {	// ���� �ٴ� �ε���
						if(nLife == 1)	return FALSE;	// �ش� ���� ���� ����
						else			nLife--;		// ���� ���� ��� -1
					}
				}
			}
		}
		else {	// ���� ���� x
			// ���� �����
			// rand() : 0-6**** �� �ϳ��� �� ��ȯ
			cDoughnut.X = rand()%(g1_screenSize.max_x-g1_screenSize.min_x+1)+g1_screenSize.min_x;	// 1-20
			cDoughnut.Y = g1_screenSize.min_y;
			bDoughnut = TRUE;
		}

		if(kbhit()) {	// Ű���� �Է��� ������ ��
			chInput = getch();
			// Ű���� �� �ƽ�Ű�ڵ� ����

			setCursorPosition(cCharacter,g1_screenSize.max_y);
			printf("  ");
			// ���� ��ġ ĳ���� �����

			switch(chInput) {
			case 75:	// LEFT	
				if(g1_screenSize.min_x <= cCharacter-1)	cCharacter--;
					// ĳ���Ͱ� �������� �̵����� ��,
					// �� ��ġ�� �� ��ġ���� ũ�ų� ������ �̵� / �ƴϸ� �̵� x
				break;
			case 77:	// RIGHT
				if(g1_screenSize.max_x >= cCharacter+2)	cCharacter++;
					// ĳ���Ͱ� ���������� �̵����� ��,
					// �� ��ġ�� �� ��ġ���� �۰ų� ������ �̵� / �ƴϸ� �̵� x
				break;
			}

			setCursorPosition(cCharacter,g1_screenSize.max_y);
			printf("%s",g1_character);
			// ���ο� ��ġ ĳ���� �׸���
		}

		Sleep(10);	// 0.01�� ���α׷� ����
		if(nCount == 119)	nCount = 0;
		else				nCount++;	// nCount ���� �÷ο� ����
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