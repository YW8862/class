#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main()
//{
//	int m, n;
//	printf("Enter m,n;");
//	scanf("%d%d", &m, &n);
//	while (m != n) //1
//	{
//		while (m > n) m = m - n; //2
//		while (n > m) n = n - m; //3
//	}
//	printf("m=%d\n", m);
//	return 0;
//}


//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//		do
//		{
//			switch (c = getchar())
//			{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default:v0 += 1; v2 += 1;
//			}
//		} while (c != '\n');
//		printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//		return 0;
//}


int main() {
	int count = 0;
	int n = 100;
	for (int i = 0; i <= n - 1; i++)
		for (int j = n; j > i; j--)
			count++;
	printf("%d", count);
}






