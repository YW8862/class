#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
//int main() {
//    int num = 0;
//    scanf("%d", &num);
//    getchar();
//    char str[201];
//    for (int i = 0; i < num; i++) {
//        gets(str);
//        int flag = 1, flag_A = 0, flag_a = 0, flag_0 = 0;
//        //4.
//        int len = strlen(str);
//        if (len < 8) {
//            flag = 0;
//        }
//        //2.
//        if (flag && str[0] >= '0' && str[0] <= '9') {
//            flag = 0;
//        }
//        //1&3
//        int j = 0;
//        while (flag && str[j] != '\0') {
//            if (str[j] >= 'a' && str[j] <= 'z')
//                flag_A = 1;
//            else if (str[j] >= 'A' && str[j] <= 'Z')
//                flag_a = 1;
//            else if (str[j] >= '0' && str[j] <= '9')
//                flag_0 = 1;
//            else {
//                flag = 0;
//                break;
//            }
//
//            j++;
//        }
//        if (flag && flag_A + flag_a + flag_0 >= 2)
//            printf("YES\n");
//        else
//            printf("NO\n");
//
//    }
//    return 0;
//}


//int main()
//{
//	char ch[80] = "123abcdEFG*&";
//	int j;
//	puts(ch);
//	for (j = 0; ch[j] != '\0'; j++)
//		if (ch[j] >= 'A' && ch[j] <= 'Z')
//			ch[j] = ch[j] + 'e' - 'E';
//	puts(ch);
//	return 0;
//}


int main()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (ch % 2 != 0 && (ch >= 'a' && ch <= 'z'))
			ch = ch - 'a' + 'A';
		putchar(ch);
	}
	printf("\n");
	return 0;
}


