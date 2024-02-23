#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>
////test4
////模拟实现库函数strcpy
//char* strcpy1(char* des, const char* src) {
//	
//	assert(des);
//	assert(src);
//	char *ret= des;
//	while (*des++ = *src++) {
//		
//	}
//	return ret;
//}
//
//int main() {
//	char arr1[] = "hello world!";
//	char arr2[20];
//	printf("%s\n", strcpy1(arr2, arr1));
//}


//test5
//模拟实现库函数strlen
//size_t strlen1(const char* str) {
//	assert(str);
//	int len = 0;
//	while (*str++)
//		len++;
//	return len;
//}
//
//int main() {
//	char arr[] = "hdsoahdiuahsduahfiuhwi";
//	printf("%zd\n", strlen1(arr));
//}




//test9
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。

//arr是一个整形一维数组。
//void point_print(int* arr,int num) {
//	
//	
//	for (int i = 0; i < num; i++) {
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7 };
//	point_print(arr,7);
//	return 0;
//}




//char* fun(char* arr) {
//    int i = 0;
//    while (*(arr + i))
//        i++;
//    i--;
//    int j = 0;
//    char temp = '\0';
//    while (j < i) {
//        temp = *(arr + i);
//        *(arr + i) = *(arr + j);
//        *(arr + j) = temp;
//        i--;
//        j++;
//    }
//    return arr;
//}
//
//int main() {
//    char arr[10000];
//    gets(arr);
//    puts(fun(arr));
//    return 0;
//}


//void print() {
//	int n = 13;
//	//打印上半部分
//	for (int i = 0; i <= n / 2 + 1; i++) {
//		for (int j = 0; j < (n + 1 - 2 * i) / 2; j++)
//			printf(" ");
//		for (int j = 0; j < 2 * i - 1; j++)
//			printf("*");
//		for (int j = 0; j < (n + 1 - 2 * i) / 2; j++)
//			printf(" ");
//		printf("\n");
//	}
//
//	//打印下半部分
//
//	for (int i = 1; i <= n / 2; i++) {
//		for (int j = 1; j <= i; j++)
//			printf(" ");
//		for (int j = 0; j < (n - 2 * i); j++)
//			printf("*");
//		for (int j = 1; j <= i; j++)
//			printf(" ");
//		printf("\n");
//	}
//}
//
//int main() {
//	print();
//}




//test12
//求出0～100000之间的所有“水仙花数”并输出。

//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

//判断一个数字是否为水仙花数
//int fun(int num) {
//	int n = num;
//	int sum = 0;
//	int c = 0;
//	//判断该数为几位数
//	while (num) {
//		num /=10;
//		c++;
//	}
//	num = n;
//	//判断水仙花数
//	while (num) {
//		sum += (int)pow(num % 10, c);
//		num /= 10;
//	}
//	if (sum == n)
//		return 1;
//	return 0;
//}
//
//
//int main() {
//	for (int i = 0; i < 100000; i++) {
//		if (fun(i))
//			printf("%d ", i);
//	}
//}




//test13
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，

//例如：2 + 22 + 222 + 2222 + 22222

//int fun(int n) {
//	return n * 5 + n * 40 + n * 300 + n * 2000 + n * 10000;
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fun(n));
//}



//test3
//调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

//思路：使用两个指针，一个从前往后找偶数，一个从后往前找奇数，然后交换二者位置，然后继续重复前面操作
void fun(int *arr,int len) {
	int i = 0, j = len - 1;
	int temp;
	while (1) {
		while (i < j && arr[i] % 2 == 1)
			i++;
		while (i < j && arr[j] % 2 == 0)
			j--;
		if (i < j&&(arr[i] % 2 == 0) && (arr[j] % 2 == 1)) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
			break;

	}
}


int main() {
	int arr[] = { 1,2,65,22,54,11,324,45,76,87,356,76456,345,234 };
	int len = sizeof(arr) / sizeof(arr[0]);
	fun(arr,len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}