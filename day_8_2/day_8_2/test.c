#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//int main()
//{
//    char a = -1;
//    signed char b = -1;
//    unsigned char c = -1;
//    printf("a=%d,b=%d,c=%d", a, b, c);
//    return 0;
//}
//
//int main() {
//
//	/*int i = -20;
//	unsigned  int  j = 10;
//	printf("%d\n", i + j);*/
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//}
int main()
{
    char a[1000];
    int i;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));
    return 0;
}
//i=0
//a[0]=-1
//10000000000000000000000000000001
//a[0]= 00000001
//i=1;
// a[0] 
// 
//