#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//定义雷的规格
#define ROW 10
#define COL 10
#define mine_Num 10//定义雷的个数

//定义结构体
typedef struct {
	int is_mine;//代表这个位置是否是雷
	int mine_num;//代表周围一圈雷的个数
	int is_check;//表示这个位置是否已经被检查过了
}Mine;

void menu();//打印菜单
void game();//执行游戏代码
void Init_mine(int mine[ROW + 2][COL + 2]);//初始化雷区
void show_mine(Mine mine[ROW + 2][COL + 2]);//打印雷区
int play(Mine mine[ROW + 2][COL + 2]);//玩家进行扫雷
int is_win(Mine mine[ROW + 2][COL + 2]);//判断游戏是否获胜