#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
//int jc(int n) {
//	if (n == 0)
//		return 1;
//	else
//		return n * jc(n - 1);
//}
//int main() {
//
//	int n = 0, res = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		res += jc(i);
//	}
//	printf("%d\n", res);
//	
//}

//int main() {
//
//	int n = 0, res = 1,resl=0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		res *= i;
//		resl += res;
//	}
//	printf("%d", resl);
//	return 0;
//}


//int main() {
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int r = sizeof(arr) / sizeof(int)-1,l=0;
//	int flag = 0, n = 0,mid = 0;
//	scanf("%d", &n);
//	while (l <=r) {
//		 mid= (l + r) / 2;
//		if (n < arr[mid])
//			r = mid - 1;
//		else if (n > arr[mid])
//			l = mid + 1;
//		if (n == arr[mid]) {
//			flag = 1;
//			break;
//		}
//		
//	}
//	if (flag)
//			printf("�±�Ϊ%d", mid + 1);
//		else
//			printf("NOT FOUND");
//	return 0;
//}

//int main() {
//	char arr1[] = { "welcome to bit!!!!!" };
//	char arr2[] = { "*******************" };
//	int i = 0, j = sizeof(arr1) / sizeof(arr1[0])-2;
//	while (i <= j) {
//		arr2[i] = arr1[i];
//		arr2[j] = arr1[j];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		i++;
//		j--;
//		
//	}
//}


//HOMEWORK
//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//int main() {
//	int count = 0;
//	for (int i = 1; i <= 100; i++) {
//		if (i / 10 == 9 )
//			count++;
//		if (i % 10 == 9)
//			count++;
//	}
//	printf("��1��100����%d��9", count);
//}

//
////����ϿεĲ�������Ϸ
////��ӡ�˵�
//void menu() {
//	printf("*************************\n");
//	printf("*******  1.play  ********\n");
//	printf("*******  0.exit  ********\n");
//	printf("*************************\n");
//}
//
//
////��Ϸʵ��
//void game(){
//	int ans=rand() % 100 + 1;
//	int num = 0;
//	printf("��ʼ������\n");
//	while (1) {
//		scanf("%d", &num);
//		if (num < ans)
//			printf("̫С�ˣ��´�һ��Ŷ��\n");
//		else if(num>ans)
//			printf("̫���ˣ���Сһ��Ŷ��\n");
//		else{
//			printf("�¶�������ϲ�㣡\n");
//			break;
//		}
//	}
//	
//}
//
//
//int main() {
//	int input = 0;
//	srand(time(NULL));
//	do{
//		menu();
//		printf("�����ѡ��:>");
//		scanf("%d", &input);
//		switch (input) {
//			case 1:
//				game();
//				printf("��Ϸ������3��󷵻����˵�\n");
//				Sleep(3000);
//				system("CLS");
//				break;
//			case 0:
//				printf("�˳���Ϸ���´��ټ�\n");
//				break;
//			default:
//				printf("ѡ�񲻺Ϸ����������ز˵�ҳ��\n");
//				Sleep(1000);
//				system("cls");
//		}
//	} while (input);
//}
//



//��д������һ���������������в��Ҿ����ĳ����
//Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����

int main() {
	int num = 0;
	printf("Input the number you want:\n");
	scanf("%d", &num);
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int r = sizeof(arr) / sizeof(arr[0])-1;
	int l = 0,mid=0;
	int flag = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] < num)
			l = mid + 1;
		else if (arr[mid] > num)
			r = mid - 1;
		else {
			flag = 1;
			break;
		}
	}
	if (flag)
		printf("Found with subscript %d!\n", mid);
	else
		printf("Not Found!\n");
}