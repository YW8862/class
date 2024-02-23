# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define ROW 5
//#define COL 6
//
//int search(int arr[][COL], int num) {
//	int row = ROW;
//	int col = COL;
//	for (int i = 0; i < row; i++) {
//		if (arr[i][0] > num || arr[i][col - 1] < num)
//			continue;
//		else {
//			int l = 0;
//			int r = col - 1;
//			int mid = 0;
//			while (l <= r) {
//				mid = (l + r) / 2;
//				if (arr[i][mid] > num)
//					r = mid - 1;
//				else if (arr[i][mid] < num)
//					l = mid + 1;
//				else
//					return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//int search2(int arr[][COL], int num) {
//	int row = 0;
//	int col = COL - 1;
//	while (row < ROW && col >= 0) {
//		if (arr[row][col] > num)
//			col--;
//		else if (arr[row][col] < num)
//			row++;
//		else
//			return 1;
//	}
//	return 0;
//}
//
//int main() {
//	int arr[5][6] = { {1,3,5,7,9,11},
//					{2,4,8,16,32,64},
//					{3,5,10,17,33,65},
//					{7,14,21,28,35,67},
//					{10,16,22,29,40,90}};
//	int num = 90;
//	printf("%d\n", search2(arr, num));
//	return 0;
//}

typedef struct {
	char name[20];
	int age;
}stu;

int cmp(const void* n1, const void* n2) {
	 
	return *(int*)n2 - *(int*)n1;
}


int cmp2(const void* n1, const void* n2) {

	return *(char*)n1 - *(char*)n2;

}
//将stu按照年龄从小到大排序
int cmp3(const void* n1, const void* n2) {

	return (*(stu*)n1).age-(*(stu*)n2).age;

}



int main() {

	//qsort将Int类型按照从大到小排序
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	qsort(arr1, 10, 4, cmp);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);


	//qsort将char类型排序
	char str[4][20] = { "jiangxi","hunan","guangxi","beijing"};
	qsort(str, 4, 20, cmp2);
	for (int i = 0; i < 4; i++) 
		printf("%s\n", str[i]);
	
	//
	stu str2[3] = { {"zhaosan",16},{"lisi",11},{"wangwu",14} };
	int sz = sizeof(str2[0]);
	qsort(str2, 3, sz, cmp2);
	for (int i = 0; i < 3; i++)
		printf("%s\t\t%d\n", str2[i].name,str2[i].age);


	return 0;
}

