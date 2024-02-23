#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}



#include <stdio.h>
#include<stdlib.h>
int main() {
    int n1 = 0, n2 = 0;
    scanf("%d %d", &n1, &n2);
    int* arr = (int*)malloc(sizeof(int) * n1);
    int num;
    for (int i = 0; i < n1; i++)
        scanf("%d", arr + i);
    int i = 0;
    while (scanf("%d", &num) != EOF) {

        while (arr[i] < num && i < n1 - 1) {
            printf("%d ", arr[i]);
            i++;
        }
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}