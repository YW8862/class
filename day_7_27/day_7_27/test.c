#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//int main() {
//	printf("%d", !0);
//	return 0;
//
//}



////����������
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


////������A�е����ݺ�����B�е����ݽ��н�����������һ����
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
// ����������ʱ������������������������
//����������
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
