#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
//int main() {
//	printf("hello world!");
//	return 0;
//}

//int fun(int x)
//{
//	return (x == 1) ? 1 : (x + fun(x - 1));
//}
//
//int main() {
//	printf("%d", fun(10));
//	return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int a, b;
//    int arr[75] = { 0 };
//    char str[1000] = {0};
//    scanf("%s", str);
//    char* p = str;
//    while (*p) {
//        arr[*p++ - 48]++;
//    }
//    for (int i = 0; i < 75; i++) {
//        while (arr[i]--)
//            printf("%c", i + 48);
//    }
//    return 0;
//}
//int main() {
//	char a[10] = 'a';
//	printf("%c", a[0]);
//}

//int pivotIndex(int* nums, int numsSize) {
//    int sum1 = 0, sum2 = 0;
//    for (int i = 1; i < numsSize; i++) {
//        sum2 += nums[i];
//    }
//    if (sum1 == sum2)
//        return 0;
//    for (int i = 1; i < numsSize; i++) {
//        sum1 += nums[i - 1];
//        sum2 -= nums[i];
//        if (sum1 == sum2)
//            return i;
//    }
//    return -1;
//}


// 
void  swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void  quick_sort_recursive(int* arr, int start,int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left) {
        quick_sort_recursive(arr, start, left - 1);
    }
    quick_sort_recursive(arr, left + 1, end);
}

int main() {
    int arr[] = { 1,4534,21,65,3,723,6,83,3,51,3,7,9,3 };
    quick_sort_recursive(arr, 0, 13);
    for (int i = 0; i < 14; i++) {
        printf("%d ", arr[i]);
    }

}













