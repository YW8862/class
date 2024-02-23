#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//
////test7
//int main() {
//	
//	 for(int num = 1;num<=100;num++)
//		 if (0==num % 3)
//			 printf("%d ", num);
//}


//test8
//int main() {
//	int num1=0, num2=0, num3=0;
//	printf("请输入三个数:\n");
//	scanf("%d %d %d", &num1, &num2, &num3);
//	printf("从大到小顺序输出为:\n");
//	if (num1 >= num2){
//		if (num2 >= num3)
//			printf("%d %d %d\n", num1, num2, num3);
//		else if (num3 >= num1)
//			printf("%d %d %d\n", num3, num1, num2);
//		else 
//			printf("%d %d %d\n", num1, num3, num2);
//	}
//	else {
//		if(num1>=num3)
//			printf("%d %d %d\n", num2, num1, num3);
//		else if(num2>=num3)
//			printf("%d %d %d\n", num2, num3, num1);
//		else 
//			printf("%d %d %d\n", num3, num2, num1);
//	}
//	return 0;
//}





////test9
//int judge(int num) {
//	int flag = 0;
//	for (int i = 2; i < sqrt(num); i+=2) {
//		if (num % i == 0)
//		{
//			flag = 1;
//			break;
//		}
//	}
//	return flag;
//}
//int main() {
//	int num = 100;
//	for (; num <= 200; num++) {
//		if (!judge(num))
//			printf("%d\n", num);
//	}
//}




////test10
//
//int judge(int num) {
//	int flag = 0;
//	if (num % 4 == 0) {
//		if (flag % 100 != 0)
//			flag = 1;
//		else if (num%100==0&&num % 400 != 0)
//			flag = 0;
//		else
//			flag = 1;
//	}
//	return flag;
//}
//int main() {
//	int num = 1000;
//	for (; num <= 2000; num++) 
//		if (judge(num)) 
//			printf("%d ", num); 	
//	return 0;
//}





////test11
//int gcd(int num1, int num2) {
//	int temp = 0;
//	if (num1 < num2)
//	{
//		temp = num1;
//		num1 = num2;
//		num2 = temp;
//	}
//	while (num2!=0) {
//		temp = num1 % num2;
//		num1 = num2;
//		num2 = temp;
//	}
//	return num1;
//}
//
//int main() {
//	int num1 = 0, num2 = 0;
//	printf("请输入两个数:\n");
//	scanf("%d %d", &num1, &num2);
//	printf("%d\n", gcd(num1, num2));
//}




////test12
//int main() {
//	for (int i = 1; i <= 9; i++){
//		for (int j = 1; j <= i; j++)
//			printf("%dX%d=%2d   ", j, i, i * j);
//		printf("\n");
//	}
//}




////test13
//int main() {
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//		scanf("%d", arr + i);
//	int max = arr[0];
//	for (int i = 0; i < 10; i++)
//		if (arr[i] > max)
//			max = arr[i];
//	printf("%d\n", max);
//	return 0;
//}




////test14
//int main() {
//	float temp = 0.0,sum=0.0;
//	for (int i = 1; i <= 100; i++) {
//		if (i % 2)
//			temp = 1.0 / i;
//		else
//			temp = -1.0 / i;
//		sum += temp;
//	}
//	printf("%.2f", sum);
//}
