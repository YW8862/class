#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW 3
#define COL 3

//��ӡ�˵�
void menu();

//������Ϸ
void game();

//��ʼ������
void InitBoard(char board[ROW][COL]);

//��ӡ����
void DisplayBoard(char board[ROW][COL]);

//�������
void playerMove(char board[ROW][COL]);

//��������
void computerMove(char board[ROW][COL]);

//�ж���Ӯ
char Is_win(char board[ROW][COL]);

