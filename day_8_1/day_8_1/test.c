#define _CRT_SECURE_NO_WARNINGS 1
//#include<assert.h>
//#include<stdio.h>
//#include<string.h>
//int main() {
//	char arr1[] = "hello bit";
//	char arr2[4];
//	strcpy(arr2, arr1);
//	printf("%s", arr2);
//}

//
//int strlen1(const char* arr) {
//	assert(arr != NULL);
//	int count = 0;
//	while (*arr++)
//		count++;
//	return count;
//}
//
//int main() {
//	char arr[] = "acbdsfdsgvdsfg";
//	printf("%d\n", strlen1(arr));
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。

//int fun(int num) {
//	if (num == 1)
//		return 1;
//	else
//		return num + fun(num / 2);
//}
//
//int main() {
//	
//	printf("%d", fun(20));
//}


#include <stdio.h>
int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
   // for (i = 0; i <= 12; i++)
   // {
       // arr[i] = 0;
        //printf("hello bit\n");
   // }

    printf("%p\n", arr);
    printf("%p\n", arr + 12);
    printf("%p\n", &i);

    return 0;
}