#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>


char* leftRotateString(char* str, int k) {
    int len = strlen(str);
    if (len == 0) {
        return;
    }

    k = k % len; // 处理k大于字符串长度的情况  
    if (k == 0) {
        return; // 不需要旋转  
    }

    // 旋转字符串  
    char temp;
    for (int i = 0; i < len - k; i++) {
        temp = str[i];
        str[i] = str[i + k];
        str[i + k] = temp;
    }
    return str;
}



int main() {
	char arr[30];
	scanf("%s", arr);
	int len = sizeof(arr);
	int n = 0;
	scanf("%d", &n);
	char* str = leftRotateString(arr, n);
	printf("%s", str);
}