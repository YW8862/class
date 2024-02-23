#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW 3
#define COL 3

//打印菜单
void menu();

//进行游戏
void game();

//初始化棋盘
void InitBoard(char board[ROW][COL]);

//打印棋盘
void DisplayBoard(char board[ROW][COL]);

//玩家下棋
void playerMove(char board[ROW][COL]);

//电脑下棋
void computerMove(char board[ROW][COL]);

//判断输赢
char Is_win(char board[ROW][COL]);

