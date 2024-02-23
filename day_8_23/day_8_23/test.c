#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//int x = 5, y = 7;
//void swap()
//{
//	int z;
//	z = x;
//	x = y;
//	y = z;
//}
//int main()
//{
//	int x = 3, y = 8;
//	swap();
//	printf("%d,%d\n",x, y);
//	return 0;
//}
#define INT_PTR int*
typedef int* int_ptr;
INT_PTR a, b;
int_ptr c, d;

int main() {
	INT_PTR a, b;
	int_ptr c, d;
	double x[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
	char c2[] = { '\x10', '\xa', '\8' };
	char c1[] = { '1','2','3','4','5' };
	int y[5 + 3] = { 0, 1, 3, 5, 7, 9 };


	return 0;
}