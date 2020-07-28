#include "launcher.h"
#include "game1_doughnut.h"

void runProgram() {
	int nMenu;
	int bFlag = TRUE;

	showTitle();

	while(bFlag) {
		nMenu = selectMainMenu();
		
		switch(nMenu) {
		case 1:
			g1_runGame();
			break;
		
		case 2:
			printf("menu2\n");
			system("pause");
			break;
		
		case 3:
			printf("menu3\n");
			system("pause");
			break;

		case 4:
			bFlag = FALSE;
			break;
		}
	}
	printf("program exited...\n");
	getchar();
	getchar();
}

void showTitle() {
	printf("==============================\n");
	printf("        My Game Program       \n");
	printf("==============================\n");
	getchar();
}

int selectMainMenu() {
	int nMenu;
	system("cls"); // clean screen
	printf("1. Doughnut Game / 2. menu2 / 3. menu3 / 4. exit\n");
	scanf("%d",&nMenu);
	return nMenu;
}