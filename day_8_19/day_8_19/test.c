#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//int main()
//{
//	int i = 1;
//	sizeof(i++);
//	printf("%d\n", i);
//	return 0;
//}

//newcoder HJ56
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int count = 0;
//    for (int i = 1; i <= n; i += 1) {
//        int sum = 0;
//        for (int j = 1; j < i; j++) {
//            if (i % j == 0)
//                sum += j;
//        }
//        if (sum == i)
//            count++;
//    }
//    printf("%d", count);
//
//    return 0;
//}
// 
//int main()
//{
//	int n = 1001;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ans ^= i % 3;
//	}
//	printf("%d", ans);
//	return 0;
//}


//HJ31单词倒叙
//#include <stdio.h>
//#include<string.h>
//int main() {
//    char arr[10001];
//    gets(arr);
//    int i = 0, j = 0, k = 0;
//    j = strlen(arr);
//    while (j > -1) {
//        i = j;
//        while (i > 0 && ((arr[i - 1] >= 'a' && arr[i - 1] <= 'z') || (arr[i - 1] >= 'A' && arr[i - 1] <= 'Z')))
//            i--;
//        k = i - 1;
//        while (i < j) {
//            printf("%c", arr[i]);
//            i++;
//        }
//        printf(" ");
//        j = k;
//    }
//    return 0;
//}

//HJ37 统计每个月兔子的总数
//#include <stdio.h>
//
//int main() {
//    int a = 1, b = 1;
//    int n = 0;
//    scanf("%d", &n);
//    int temp = 0;
//    for (int i = 3; i <= n; i++) {
//        temp = a;
//        a = a + b;
//        b = temp;
//    }
//    printf("%d", a);
//    return 0;
//}

//ZJ16 数列的和
int main() {
    double n, m;
    while (scanf("%lf %lf", &n, &m) != EOF) {
        double sum = 0;
        for (int i = 0; i < m; i++) {
            sum += n;
            n = sqrt(n);

        }
        printf("%.2lf\n", sum);
    }
    return 0;
}