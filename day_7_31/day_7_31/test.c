#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//����һ������ n ���������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��


//int NumberOf1(int n) {
//    // write code here
//    int count = 0;
//    for (int i = 0; i < 32; i++) {
//        if ((n >> i) & 1)
//            count++;
//    }
//    return count;
//}


//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

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



//�����������������������������Ƹ�ʽ�ж��ٸ�λ��ͬ
///**
//* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//*
//*
//* @param n int����
//* @return int����
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