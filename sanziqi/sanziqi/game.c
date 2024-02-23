#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//打印菜单
void menu() {
	printf("*******************************\n");
	printf("******   1.  play   ***********\n");
	printf("******   0.  exit   ***********\n");
	printf("*******************************\n");
}


//初始化棋盘
void InitBoard(char board[ROW][COL]) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			board[i][j] = ' ';
}


//打印棋盘
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

//玩家下棋
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

//电脑下棋
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

//判断输赢
char Is_win(char board[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0;j<COL ; j++) {
			if (j < COL - 2 && board[i][j] == board[i][j+1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')//表示同一行连线成功
				return board[i][j];
			if (i < ROW - 2 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] != ' ')//表示同一列连线成功
				return board[i][j];
			if(j < COL - 2&& i < ROW - 2&& board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] != ' ')//表示右下对角线连线成功
				return board[i][j];
			if (j > 1 && i < ROW - 2 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] != ' ')//表示坐下对角线连线成功
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
	//设置随机数发生器
	srand((unsigned)time(NULL));
	char ret = ' ';
	DisplayBoard(board);
	while (1) {
		//玩家下棋
		playerMove(board);
		//打印玩家下棋后的棋盘
		DisplayBoard(board);
		//进行输赢判断
		ret = Is_win(board);
		//检查玩家是否获胜（因为该轮是玩家下棋，不可能电脑获胜，故不需要考虑电脑获胜情况）
		//游戏是否继续
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
		//电脑下棋
		computerMove(board);
		//打印电脑下棋后的棋盘
		//进行输赢判断

		DisplayBoard(board);
		ret = Is_win(board);
		//检查电脑是否获胜（因为该轮是电脑下棋，不可能玩家获胜，故不需要考虑玩家获胜情况）
	//游戏是否继续
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