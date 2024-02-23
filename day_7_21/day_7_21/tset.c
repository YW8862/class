#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<math.h>



//int getmax(int a, int b) {
//	return a > b ? a : b;
//}
//int main() {
//	//int a = 0, b = 0;
//	//scanf("%d%d", &a, &b);
//	//int max = getmax(a,b);
//	//printf("%d", max);
//
//
//
//	printf("%d", printf("%d", printf("%d", 43)));
//}

//int judge(int n) {
//	int flag = 1;
//	for (int i = 2; i <=sqrt(n); i++)
//		if (n % i == 0)
//			flag = 0;
//	return flag;
//}
//int main() {
//	int num = 0;
//	scanf("%d", &num);
//	printf("%d", judge(num));
//}

//bool search(int*arr,int l,int n) {
//	
//}





//int fun(int year) {
//	
//	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
//		return 0;
//	return 1;
//}
//
//
//int main() {
//	int year=0;
//	scanf("%d", &year);
//	printf("%d", fun(year));
//}


//test11
//需求:实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定

//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//void print(int n) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			printf("%-2dX%-2d=%-3d  ", j, i, i * j);
//		}
//		printf("\n");
//	}
//
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//
//}




//test12
//需求:实现一个函数来交换两个整数的内容。

//int swap(int* p1, int* p2) {
//	int temp = 0;
//	temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//int main() {
//	int m=0, n = 0;
//	scanf("%d%d", &m, &n);
//	printf("m=%d,n=%d\n", m, n);
//	swap(&m, &n);
//	printf("m=%d,n=%d\n", m, n);
//
//}




//test13
// 需求:实现函数判断year是不是润年。
// 


// 
//int fun(int year) {
//	
//	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
//		return 0;
//	return 1;
//}
//
//
//int main() {
//	int year=0;
//	scanf("%d", &year);
//	if (fun(year))
//		printf("%d是闰年\n", year);
//	else
//		printf("%d不是闰年\n", year);
//
//}


//test14
//需求:实现一个函数is_prime，判断一个数是不是素数。
//利用上面实现的is_prime函数，打印100到200之间的素数。

int is_prime(int n) {

	for (int i = 2; i < sqrt(n); i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;

}

int main() {
	for (int i = 100; i < 200; i++) {
		if (is_prime(i))
			printf("%d ",i);
	}
}

