#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>
////test4
////ģ��ʵ�ֿ⺯��strcpy
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
//ģ��ʵ�ֿ⺯��strlen
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
//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣

//arr��һ������һά���顣
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
//	//��ӡ�ϰ벿��
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
//	//��ӡ�°벿��
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
//���0��100000֮������С�ˮ�ɻ������������

//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

//�ж�һ�������Ƿ�Ϊˮ�ɻ���
//int fun(int num) {
//	int n = num;
//	int sum = 0;
//	int c = 0;
//	//�жϸ���Ϊ��λ��
//	while (num) {
//		num /=10;
//		c++;
//	}
//	num = n;
//	//�ж�ˮ�ɻ���
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
//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�

//���磺2 + 22 + 222 + 2222 + 22222

//int fun(int n) {
//	return n * 5 + n * 40 + n * 300 + n * 2000 + n * 10000;
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fun(n));
//}



//test3
//��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

//˼·��ʹ������ָ�룬һ����ǰ������ż����һ���Ӻ���ǰ��������Ȼ�󽻻�����λ�ã�Ȼ������ظ�ǰ�����
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