#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//��ӡ�˵�
void menu() {
	printf("*******************************\n");
	printf("******   1.  play   ***********\n");
	printf("******   0.  exit   ***********\n");
	printf("*******************************\n");
}


//��ʼ������
void InitBoard(char board[ROW][COL]) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			board[i][j] = ' ';
}


//��ӡ����
void DisplayBoard(char board[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (j < COL - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}

		
		if (i < ROW - 1)
			for (int j = 0; j < COL; j++) {
				if (j < COL - 1)
					printf("---|");
				else
					printf("---\n");

			}
	}
}

//�������
void playerMove(char board[ROW][COL]) {
	printf("Your turn\n");

	int x = 0, y = 0;
	loop:
		printf("Input your coordinate:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <=COL && y  >= 1 && y  <= ROW && board[x - 1][y - 1] == ' ')
			board[x - 1][y - 1] = '*';
		else {
			printf("ERROR!Rselect please!\n");
			goto loop;
		}	
}

//��������
void computerMove(char board[ROW][COL]) {
	printf("Computer's turn:\n");
	Sleep(800);
	int x =0, y = 0;
	while (1) {
		x = rand() % COL;
		y = rand() % ROW;
		if (x < COL && y < ROW && board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}		
}

//�ж���Ӯ
char Is_win(char board[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0;j<COL ; j++) {
			if (j < COL - 2 && board[i][j] == board[i][j+1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')//��ʾͬһ�����߳ɹ�
				return board[i][j];
			if (i < ROW - 2 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] != ' ')//��ʾͬһ�����߳ɹ�
				return board[i][j];
			if(j < COL - 2&& i < ROW - 2&& board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ')//��ʾ���¶Խ������߳ɹ�
				return board[i][j];
			if (j > 1 && i < ROW - 2 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] != ' ')//��ʾ���¶Խ������߳ɹ�
				return board[i][j];
		}	
	}
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (board[i][j] == ' ')
				return 'C';
	return 'Q';

}

void game() {

	char board[ROW][COL];
	InitBoard(board);
	//���������������
	srand((unsigned)time(NULL));
	char ret = ' ';
	DisplayBoard(board);
	while (1) {
		//�������
		playerMove(board);
		//��ӡ�������������
		DisplayBoard(board);
		//������Ӯ�ж�
		ret = Is_win(board);
		//�������Ƿ��ʤ����Ϊ������������壬�����ܵ��Ի�ʤ���ʲ���Ҫ���ǵ��Ի�ʤ�����
		//��Ϸ�Ƿ����
		if (ret == '*') {
			printf("You Win!\n");
			break;
		}
		else if (ret == '#') {
			printf("Computer WIn!\n");
			break;
		}
		else if (ret == 'Q') {
			printf("Draw!\n");
			break;
		}
		else
			printf("Continue!\n");
		//IS_win();
		//��������
		computerMove(board);
		//��ӡ��������������
		//������Ӯ�ж�

		DisplayBoard(board);
		ret = Is_win(board);
		//�������Ƿ��ʤ����Ϊ�����ǵ������壬��������һ�ʤ���ʲ���Ҫ������һ�ʤ�����
	//��Ϸ�Ƿ����
		if (ret == '#') {
			printf("Computer WIn!\n");
			break;
		}
		else if (ret == 'Q') {
			printf("Draw!\n");
			break;
		}
		else
			printf("Continue!\n");
	}
	printf("You will return back to menu in 3s\n");
	Sleep(3000);
	system("cls");
}