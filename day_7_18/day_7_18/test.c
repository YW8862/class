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
//			printf("下标为%d", mid + 1);
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
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//int main() {
//	int count = 0;
//	for (int i = 1; i <= 100; i++) {
//		if (i / 10 == 9 )
//			count++;
//		if (i % 10 == 9)
//			count++;
//	}
//	printf("从1到100间有%d个9", count);
//}

//
////完成上课的猜数字游戏
////打印菜单
//void menu() {
//	printf("*************************\n");
//	printf("*******  1.play  ********\n");
//	printf("*******  0.exit  ********\n");
//	printf("*************************\n");
//}
//
//
////游戏实现
//void game(){
//	int ans=rand() % 100 + 1;
//	int num = 0;
//	printf("开始猜数字\n");
//	while (1) {
//		scanf("%d", &num);
//		if (num < ans)
//			printf("太小了，猜大一点哦！\n");
//		else if(num>ans)
//			printf("太大了，猜小一点哦！\n");
//		else{
//			printf("猜对啦，恭喜你！\n");
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
//		printf("请进行选择:>");
//		scanf("%d", &input);
//		switch (input) {
//			case 1:
//				game();
//				printf("游戏结束，3秒后返回主菜单\n");
//				Sleep(3000);
//				system("CLS");
//				break;
//			case 0:
//				printf("退出游戏，下次再见\n");
//				break;
//			default:
//				printf("选择不合法，即将返回菜单页面\n");
//				Sleep(1000);
//				system("cls");
//		}
//	} while (input);
//}
//



//编写代码在一个整形有序数组中查找具体的某个数
//要求：找到了就打印数字所在的下标，找不到则输出：找不到。

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