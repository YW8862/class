#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


//模拟实现strlen
//int my_strlen(const char*str) {
//	int len = 0;
//	while (*(str++))
//		len++;
//	return len;
// }
//
//int main() {
//	char arr[] = "bsfcjskbakvfjukds";
//	printf("%d\n", my_strlen(arr));
//	printf("%d\n", strlen(arr));
//}



//模拟实现strcpy
//
//char* my_strcpy(char* dest, const char* sour) {
//	char* res = dest;
//	while (*(dest++) = *(sour++))
//		;
//	return res;
//}
//
//
//int main() {
//	char arr[] = "abcdefg\n";
//	char arr2[20] = { 0 };
//	//char arr3[20] = { 0 };
//	char* str = my_strcpy(arr2, arr);
//	printf(str);
//	printf(arr2);
//	//printf("%p\n", arr2);
//	//printf("%p\n", str);
//}


//模拟实现strcmp
//int my_strcmp(const char* str1, const char* str2) {
//	while (*str1 == *str2) {
//		if (*str1) {
//			str1++;
//			str2++;
//		}
//		else
//			return 0;
//	}
//	return *str1 - *str2;
//}
//
//int main() {
//	char str1[] = "abcdef";
//	char str2[] = "abcdef";
//	char str3[] = "abcdefg";
//	printf("%d\n", my_strcmp(str1, str2));
//	printf("%d\n", my_strcmp(str1, str3));
//	return 0;
//}




////模拟实现strcat
//char* my_strcat(char* dest, char* sour) {
//	char* res = dest;
//	while (*dest)//找到字符串1的末尾
//		dest++;
//	while (*(dest++) = *(sour++))
//		;
//	return res;
//}
//
//
//int main() {
//	char str1[30] = "abcdef";
//	char str2[] = "ghi";
//	char* dest = my_strcat(str1, str2);
//	printf("%s\n",dest);
//	printf("%s\n",str1);
//
//	return 0;
//}


////模拟实现strstr
//char* my_strstr(const char* str1, const char* str2) {
//	assert(str1&&str2);
//	char* p1 = str1;
//	char* p3 = str2;
//	while (1) {
//		if (*p1 == '\0')
//			return NULL;
//		while (*p1!=*str2) {
//			p1++;
//		}
//		char*p2 = p1;
//		p3 = str2;
//		while (*p2 == *p3) {
//				p2++;
//				p3++;
//				if (*p3 == '\0')
//					return p1;
//		}
//		p1++;
//	}
//}
//
//int main() {
//	char str1[] = "hello world";
//	char str2[] = "world";
//	printf("%0xp\n", my_strstr(str1, str2));
//	printf("%0xp\n", strstr(str1, str2));
//}



////模拟实现memcpy
//void* my_memcpy(void* dest, void* sour,size_t sz) {
//	void* res = dest;
//	while (sz--)
//		*((char*)dest)++ = *((char*)sour)++;
//	return res;
//}
//
//int main() {
//	char str1[] = "abcdefgh";
//	char str2[] = "edf";
//
//	printf("%s\n", my_memcpy(str1, str2, 3));
//	printf("%s\n", memcpy(str1, str2, 3));
//}

int main() {
	float x = 0.3;
	if (x == 0.3)
		printf("yes\n");
}
