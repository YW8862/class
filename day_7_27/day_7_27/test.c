#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//int main() {
//	printf("%d", !0);
//	return 0;
//
//}



////交换两个数
//void swap(int* a, int* b) {
//	*a = (*a) ^ (*b);
//	*b = (*a) ^ (*b);
//	*a = (*a) ^ (*b);
//}
//
//
//
//int main() {
//	int a = 5;
//	int b = 6;
//	swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//}


////将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//
//int main() {
//	int a[] = { 1,2,3,4,5,6 };
//	int b[] = { 2,3,4,5,6,7 };
//	int len = sizeof(a) / sizeof(a[0]);
//	int temp = 0;
//	for (int i = 0; i < len; i++) {
//		temp = a[i];
//		a[i] = b[i];
//		b[i] = temp;
//	}
//	for (int i = 0; i < len; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	for (int i = 0; i < len; i++)
//		printf("%d ", b[i]);
//}



//test3
// 不允许创建临时变量，交换两个整数的内容
//交换两个数
void swap(int* a, int* b) {
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);
}



int main() {
	int a = 5;
	int b = 6;
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);
}
