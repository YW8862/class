#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//
////test9
////����һ���������飬��ɶ�����Ĳ���
////ʵ�ֺ���init() ��ʼ������Ϊȫ0
////ʵ��print()  ��ӡ�����ÿ��Ԫ��
////ʵ��reverse()  �����������Ԫ�ص����á�
////Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
//
////��ʼ������
//void Init(int arr[],int length ) {
//	for (int i = 0; i < length; i++)
//		arr[i] = 0;
//}
//
////ʵ��print()  ��ӡ�����ÿ��Ԫ��
//void print(int arr[], int length) {
//	for (int i = 0; i < length; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//
////ʵ��reverse()  �����������Ԫ�ص����á�
//void reverse(int arr[], int length) {
//	int l = 0, r = length - 1,temp=0;
//	while (l <= r) {
//		temp = arr[l];
//		arr[l] = arr[r];
//		arr[r] = temp;
//		l++;
//		r--;
//	}
//}
//
//int main() {
//	int arr[10];
//	Init(arr, 10);
//	print(arr, 10);
//
//	int arr2[] = { 1,2,3,4,5,6,7,8,9 };
//	print(arr2, 9);
//	reverse(arr2, 9);
//	print(arr2, 9);
//
//}




//test10
//ʵ��һ�������������ð������

void sort(int arr[], int len) {
	int temp = 0;
	while (len) {
		for (int i = 1; i < len; i++) {
			if (arr[i-1] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
			}
		}
		len--;
	}
}

//ʵ��print()  ��ӡ�����ÿ��Ԫ��
void print(int arr[], int length) {
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//
int main() {
	int arr[] = { 1,3,5,7,9,2,4,6,8,7 };
	sort(arr, 10);
	print(arr, 10);
}

