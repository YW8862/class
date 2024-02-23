#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


//
//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//ÓëÔËËã
//	}
//	return count;
//}
//int main() {
//	printf("%d", func(-1));
//	return 0;
//}




//LEEtcode238
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//    int* arr = (int*)malloc(sizeof(int) * numsSize);
//    int* L = (int*)malloc(sizeof(int) * numsSize);
//    int* R = (int*)malloc(sizeof(int) * numsSize);
//    L[0] = R[numsSize - 1] = 1;
//    int i = 1, j = numsSize - 2;
//    for (; j >= 0 && i < numsSize; i++, j--) {
//        L[i] = L[i - 1] * nums[i - 1];
//        R[j] = R[j + 1] * nums[j + 1];
//    }
//    for (i = 0; i < numsSize; i++) {
//        arr[i] = L[i] * R[i];
//    }
//    free(L);
//    free(R);
//    *returnSize = numsSize;
//    return arr;
//}


//int Add(int num1, int num2) {
//    // write code here
//    while (num2 != 0) {
//        int temp = num1 ^ num2;
//        num2 = (num1 & num2) << 1;
//        num1 = temp;
//    }
//    return num1;
//}


//leetcode448
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int* res = (int*)malloc(sizeof(int) * (numsSize + 1));
//    int* num = (int*)malloc(sizeof(int) * (numsSize + 1));
//    for (int i = 0; i <= numsSize; i++) {
//        num[nums[i]]++;
//    }
//    int j = 0;
//    for (int i = 1; i <= numsSize; i++) {
//        if (num[i] == 0)
//            res[j++] = i;
//    }
//    free(num);
//    *returnSize = j;
//    return res;
//}