#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//void a() {
//	static int a = 0;
//	a++;
//	printf("%d\n", a);
//}
//
//int main() {
//	a();
//	a();
//	a();
//	a();
//	a();
//
//}



//leetcode485
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int l = 0, r = 0;
    int max = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            count++;
            if(i==numsSize-1)
                max = max > count ? max : count;

        }
            
        else if (nums[i] == 0 ) {
            max = max > count ? max : count;
            count = 0;
        }
    }
    return max;
}

int main() {
    int arr[] = { 1,1,0,1,1,1 };
    printf("%d", findMaxConsecutiveOnes(arr, 6));

    return 0;
}