#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//�����׵Ĺ��
#define ROW 10
#define COL 10
#define mine_Num 10//�����׵ĸ���

//����ṹ��
typedef struct {
	int is_mine;//�������λ���Ƿ�����
	int mine_num;//������ΧһȦ�׵ĸ���
	int is_check;//��ʾ���λ���Ƿ��Ѿ���������
}Mine;

void menu();//��ӡ�˵�
void game();//ִ����Ϸ����
void Init_mine(int mine[ROW + 2][COL + 2]);//��ʼ������
void show_mine(Mine mine[ROW + 2][COL + 2]);//��ӡ����
int play(Mine mine[ROW + 2][COL + 2]);//��ҽ���ɨ��
int is_win(Mine mine[ROW + 2][COL + 2]);//�ж���Ϸ�Ƿ��ʤ