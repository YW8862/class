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






//��n�Ľ׳ˡ��������������
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
// �ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//���n��쳲����������������������
//�ݹ�ʵ��쳲���������
//int fib1(int n) {
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return fib1(n - 1) + fib1(n - 2);
//}
//
//
////�ǵݹ�ʵ��쳲���������
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
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
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
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//���룺1729�������19
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
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������У����������ӡ��
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//���� :
//char arr[] = "abcdef";
//����֮����������ݱ�ɣ�fedcba

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
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen

//�ݹ�ʵ��strlen
//int strlen1(const char* str) {
//	if (*str == '\0')
//		return 0;
//	else 
//		return 1 + strlen(str + 1);
//}
//
//
////�ǵݹ�ʵ��strlen
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
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
////�ݹ�ʵ�ֽ׳˺���
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
////�ǵݹ�ʵ�ֽ׳˺���
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
////�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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