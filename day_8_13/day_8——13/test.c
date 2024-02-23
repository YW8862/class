#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//	int nums[] = { 1,23,56,22,87,213,872,243,987,323,9887,23,987,27,89.245 };
//    int n = sizeof(nums) / sizeof(nums[0]);
//    int temp = 0;
//    for (int i = 0; i < n - 1; ++i)  //比较n-1轮
//    {
//        for (int j = 0; j < n - 1 - i; ++j)  //每轮比较n-1-i次,
//        {
//            if (nums[j] < nums[j + 1])
//            {
//                temp =nums[j];
//                nums[j] = nums[j + 1];
//                nums[j + 1] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        printf("%d ", nums[i]);
//    }
//}

//int cmp(const void* a, const void* b) {
//    return *(int*)a - *(int*)b;
//}
//int majorityElement(int* nums, int numsSize) {
//    qsort(nums, numsSize, sizeof(int), cmp);
//    return nums[numsSize / 2];
//}


//leetcode169
//投票法求多数元素
//int majorityElement(int* nums, int numsSize) {
//    int candidate = nums[0];
//    int count = 1;
//
//    for (int i = 1; i < numsSize; i++) {
//        if (nums[i] == candidate) {
//            count++;
//        }
//        else {
//            count--;
//            if (count < 0) {
//                candidate = nums[i];
//                count = 1;
//            }
//        }
//    }
//    return candidate;
//}
//
////leetcode169
//int cmp(const void* a, const void* b) {
//    return *(int*)a - *(int*)b;
//}
//int majorityElement(int* nums, int numsSize) {
//    qsort(nums, numsSize, sizeof(int), cmp);
//    return nums[numsSize / 2];
//}

//#include<stdio.h>
//int main()
//{
//	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, * p[4], i;
//	for (i = 0; i < 4; i++)
//		p[i] = &a[i * 3];
//	printf("%d\n",p[3][2]);
//	return 0;
//}

int main() {
	int x;
	printf("%d", (x = 4 * 5, x * 5), x + 5);
}







