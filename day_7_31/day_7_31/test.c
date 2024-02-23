#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。


//int NumberOf1(int n) {
//    // write code here
//    int count = 0;
//    for (int i = 0; i < 32; i++) {
//        if ((n >> i) & 1)
//            count++;
//    }
//    return count;
//}


//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

//void odd_print(int num) {
//	printf("Odd Print: ");
//	for (int i = 0; i < 32; i += 2) {
//		printf("%d ", (num >> i)&1);
//		
//	}
//	printf("\n");
//}
//
//void even_print(int num) {
//	printf("Een Print: ");
//	for (int i = 1; i < 32; i += 2) {
//		printf("%d ", (num >> i) & 1);
//		
//	}
//	printf("\n");
//}
//
//
//int main() {
//	int num = 0;
//	scanf("%d", &num);
//	odd_print(num);
//	even_print(num);
//}



//输入两个整数，求两个整数二进制格式有多少个位不同
///**
//* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//*
//*
//* @param n int整型
//* @return int整型
//* /
//int NumberOf1(int n) {
//    // write code here
//    int count = 0;
//    for (int i = 0; i < 32; i++) {
//        if ((n >> i) & 1)
//            count++;
//    }
//    return count;
//}



#include <stdio.h>
#include<math.h>
int  Lily_Number(int num) {
    int sum = 0;
    int yushu = 0, shang = 0;
    int i = 1;
     do{

        yushu = num % (int)pow(10, i);
        shang = num / (int)pow(10, i);
        sum += yushu * shang;
        i++;
    }while (shang);
    if (sum == num)
        return 1;
    return 0;
}

int main() {
    for (int i = 1; i < 9999; i++) {
        int j = Lily_Number(i);
        if (j)
            printf("%d ", i);
    }
}