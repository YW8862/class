#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
    char arr[101];
    gets(arr);
    int i = 0, j = 0, k = 0;
    j = strlen(arr);
    while (j>-1) {
        i = j;
        while (i >0&& arr[i-1] != ' ')
            i--;
        k = i-1;
        while (i < j) {
            printf("%c", arr[i]);
            i++;
        }
        printf(" ");
        j = k;
    }
    return 0;
}