#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//int main() {
//	float a = 3.14;
//	if (a == 3.14)
//		printf("YES\n");
//	else
//		printf("No\n");
//}
//#define max 255
//#include <stdio.h>
//typedef union
//{
//	int a;
//	struct
//	{
//		short b;
//		short c;
//	};
//}X;
//int main()
//{
//	X x;
//	x.a = 0x20150810;
//	printf("%x,%x\n", x.b, x.c);
//}


//#define MAX 255
//int main()
//{
//	unsigned char A[MAX], i;
//	for (i = 0; i <= MAX; i++)
//		A[i] = i;
//	return 0;
//}

#include<stdio.h>
int main()
{
	unsigned char i = 7;
	int j = 0;
	for (; i > 0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
	return 0;
}