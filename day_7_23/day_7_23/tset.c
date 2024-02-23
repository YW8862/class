#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdint.h>


//void fun(int n) {
//
//	if (n) {
//		fun(n / 10);
//		printf("%d ", n % 10);
//	}
//	return;
//
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	fun(n);
//	return 0;
//}






//求n的阶乘。（不考虑溢出）
//int fun(int n) {
//	if (n <= 1)
//		return 1;
//	else
//		return n * fun(n - 1);
//}
//
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fun(n));
//	return 0;
//}





//test3
// 递归和非递归分别实现求第n个斐波那契数
//求第n个斐波那契数。（不考虑溢出）
//递归实现斐波那契数列
//int fib1(int n) {
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return fib1(n - 1) + fib1(n - 2);
//}
//
//
////非递归实现斐波那契数列
//int fib2(int n) {
//	int a = 1, b = 1;
//	int c = b;
//	if (n <= 2)
//		return 1;
//	for (int i = 3; i <=n; i++) {
//		c = a;
//		a = a + b;
//		b = c;
//	}
//	return a;
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fib1(n));
//	printf("%d\n", fib2(n));
//	return 0;
//}
//





//size_t strlen(char* s) {
//	if (*s == '\0')
//		return 0;
//	else
//		return 1 + strlen(s + 1);
//}
//
//int main() {
//	char ch[] = "abcdefg";
//	printf("%d", strlen(ch));
//}





//test4
//编写一个函数实现n的k次方，使用递归实现。
//int pow(int n, int k) {
//	if (k == 0)
//		return 1;
//	else
//		return n * pow(n, k - 1);
//}
//
//int main() {
//	int n = 0, k = 0;
//	scanf("%d%d", &n, &k);
//	printf("%d\n", pow(n, k));
//	return 0;
//}





//test5
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//输入：1729，输出：19
//int add(int n) {
//	if (n == 0)
//		return 0;
//	else
//		return 	n % 10 + add(n / 10);
//	
//}
//
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", add(n));
//	return 0;
//}





//test6
//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列，不是逆序打印。
//要求：不能使用C函数库中的字符串操作函数。
//比如 :
//char arr[] = "abcdef";
//逆序之后数组的内容变成：fedcba

//void reverse_string(char* string) {
//	if (*string == '\0')
//		return;
//	else{
//		reverse_string(string + 1);
//		printf("%c", *string);
//	}
//}
//
//int main() {
//	char str[] = "abcdefg";
//	reverse_string(str);
//	return 0;
//}





//test7
//递归和非递归分别实现strlen

//递归实现strlen
//int strlen1(const char* str) {
//	if (*str == '\0')
//		return 0;
//	else 
//		return 1 + strlen(str + 1);
//}
//
//
////非递归实现strlen
//int strlen2(const char* str) {
//	int count = 0,i=0;
//	while (*(str+i) != '\0'){
//		count++;
//		i++;
//	}
//	return count;
//}
//
//int main() {
//	char str[] = "abcdefgh";
//	printf("%d\n", strlen1(str));
//	printf("%d\n", strlen2(str));
//	return 0;
//}





//test8
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
////递归实现阶乘函数
//uint64_t jc1(int n) {
//	if (n <= 1)
//		return 1;
//	else
//		return n * jc1(n - 1);
//}
//
//
//
//
////非递归实现阶乘函数
//uint64_t jc2(int n) {
//	int res = 1;
//	for (int i = 1; i <= n; i++)
//		res *= i;
//	return res;
//}
//
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", jc1(n));
//	printf("%d\n", jc2(n));
//	return 0;
//
//}





////test9
////递归方式实现打印一个整数的每一位
//void print(int n) {
//	if (!n)
//		return;
//	else {
//		print(n / 10);
//		printf("%d ", n % 10);
//	}
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}