#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。



//test6
//思路：ABCDE五人每人说了一句真话，和一句假话，那么 陈述1||陈述2 为真 并且 非陈述1||非陈述2 为真，
//只需要将各种排名组合进行判断，即可解题
//int fun(int a, int b, int c, int d, int e) {
//	if((b==2)+(a==3)==1
//		&&(b==2)+(e==4)==1
//		&&(c==1)+(d==2)==1
//		&&(c==5)+(d==3)==1
//		&&(e==4)+(a==1)==1)
//		return 1;
//	return 0;
//}
//
//
//int main() {
//
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//
//	//获取所有排名组合
//	for( a=1;a<=5;a++)
//		for ( b = 1; b <= 5; b++) {
//			if (b == a)
//				continue;
//			for ( c = 1; c <= 5; c++) {
//				if (a == c || a == b)
//					continue;
//				for ( d = 1; d <= 5; d++) {
//					if (a == d || b == d || c == d)
//						continue;
//					for ( e = 1; e <= 5; e++) {
//						if (a == e || b == e || c == e || d == e)
//							continue;
//						if(fun(a,b,c,d,e))
//							goto print;
//					}
//				}
//			}
//		}
//print:
//	printf("A为第%d名，B为第%d名，C为第%d名，D为第%d名，E为第%d名\n",a,b,c,d,e);
//}




//test7
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//
//int fun(int a, int b, int c, int d) {
//	if ((a == 1 && c == 1 && d == 1 && d != 1) || (a != 1 && c != 1 && d == 1 && d != 1) || (a != 1 && c == 1 && d != 1) || (a != 1 && c == 1 && d == 1 ))
//		return 1;
//	return 0;
//}
//
//int main() {
//	int a[5] = { 0 };
//	for (int i = 0; i < 5; i++) {
//		int a[5] = { 0 };
//		a[i] = 1;
//		if (fun(a[1], a[2], a[3], a[4]))
//			printf("凶手为%c", 64 + i);
//	}
//}


//打印杨辉三角
int main() {
	//动态申请二维数组
	int n = 0;
	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	//数组初始化
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {

		}


}