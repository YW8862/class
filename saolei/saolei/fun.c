#include "saolei.h"
//��ӡ�˵�
void menu() {
	printf("**************************************************\n");
	printf("*                    1.play                      *\n");
	printf("*                    0.exit                      *\n");
	printf("**************************************************\n");
	printf("select->:");
}
//ִ����Ϸ�߼�
void game() {
	Mine mine[ROW+2][COL+2] = { {0},{0},{0} };
	srand((unsigned)time(NULL));
	Init_mine(mine);
	show_mine(mine);
	int flag = 0;
	do {
		flag=play(mine);
		if (flag) {
			show_mine(mine);
			if (is_win(mine)) {
				printf("YOU WIN!\nReturn to menu in 3 seconds\n");
				Sleep(3000);
				return;
			}
			printf("Continue!\n");		
		}
		else 
			printf("YOU LOST!\nReturn to menu in 3 seconds\n");
	} while (flag);
	Sleep(3000);
}

//��ʼ�����������׷�������
void Init_mine(Mine mine[ROW+2][COL+2]) {
	int count = 0;
	while (count < mine_Num) {
		int x = rand() % ROW+1;
		int y = rand() % COL+1;
		if (mine[x][y].is_mine == 0) {
			mine[x][y].is_mine = 1;
			count++;
		}
	}
	//����Χ�׵������洢����
	for(int i=1;i<ROW+1;i++)
		for (int j = 1; j < COL+1; j++) {
			mine[i][j].mine_num = (mine[i-1][j-1].is_mine + mine[i-1][j].is_mine +
				mine[i-1][j+1].is_mine + mine[i][j-1].is_mine + mine[i][j+1].is_mine +
				mine[i+1][j-1].is_mine + mine[i+1][j].is_mine + mine[i+1][j+1].is_mine);
		}
}

void show_mine(Mine mine[ROW + 2][COL + 2]) {
	
	//����ɨ��λ����Χ�׵�������¼�����������ӡ��*��
	char board[ROW][COL] = {0};
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (mine[i + 1][j + 1].is_check == 0)
				board[i][j] = '*';
			else
				board[i][j] = mine[i + 1][j + 1].mine_num + 48;
		}
	}
	//��ӡ����
	printf("     ");
	for (int i = 1; i <= COL; i++)
		printf("\033[1;31m%-4d\033[0m", i);
	printf("\n\n");
	for (int i = 0; i < ROW; i++) {
		printf("\033[1;31m%-4d\033[0m", i + 1);
		for (int j = 0; j < COL; j++) {
			if (j < COL - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		printf("    ");
		if (i < ROW - 1)
			for (int j = 0; j < COL; j++) {
				if (j < COL - 1)
					printf("---|");
				else
					printf("---\n");
			}
	}
	printf("\n");
}
//��ҽ���ɨ��
int play(Mine mine[ROW+2][COL+2]) {
	
	int flag = 1;//���ñ�־��1Ϊ���벻�Ϸ���0Ϊ1����Ϸ�
	while (flag) {
		int x = 0, y = 0;
		printf("Select the location you want to troubleshoot please:-> ");
		scanf("%d%d", &x, &y);
		getchar();
		if (x > 0 && x <= COL && y > 0 && y <= ROW) {
			if (mine[x][y].is_mine == 1)
				return 0;
			else
				if (mine[x][y].is_check == 0) {
					mine[x][y].is_check = 1;
					flag = 0;
				}
				else
					printf("Error,Reselect please!\n");
		}
		else
			printf("Error,Reselect please!\n");
	}
	return 1;
}
//�ж�����Ƿ��ʤ
int is_win(Mine mine[ROW + 2][COL + 2]) {
	for (int i = 1; i < ROW + 1; i++)
		for (int j = 1; j < COL + 1; j++)
			if (mine[i][j].is_mine==0&&mine[i][j].is_check == 0)
				return 0;
	return 1;
}