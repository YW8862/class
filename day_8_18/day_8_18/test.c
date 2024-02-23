#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


//int main()
//{
//	char c = 'A';
//	if ('0' <= c <= '9') printf("YES");
//	else printf("NO");
//	return 0;
//}



//newcoder JH11


//法一：
//int main() {
//    int num = 0;
//    scanf("%d", &num);
//    int k = 0;
//    int arr[20] = { 0 };
//    do {
//        arr[k++] = num % 10;
//        num /= 10;
//    } while (num);
//    for (int i = 0; i < k; i++) {
//        printf("%d", arr[i]);
//    }
//    return 0;
//}

//法二：
//int main() {
//    char arr[20] = { 0 };
//    scanf("%s", arr);
//    int k = strlen(arr);
//    for (int i = k - 1; i >= 0; i--) {
//        printf("%c", arr[i]);
//    }
//    return 0;
//}

