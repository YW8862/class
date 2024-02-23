#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

//int main()
//{
//	long long num = 0;//用于接收数字
//	scanf("%lld", &num);
//	char res[20] = { 0 };//使用字符数组逆序储存每一位数
//	int i = 0;
//	while (num)//对数组进行处理
//	{
//		if (i % 4 == 3&&i!=0)
//			res[i++] = ',';
//		res[i++] = num % 10+48;
//		num /= 10;
//	}
//	while (i--)//逆序打印数组
//	{
//		printf("%c", res[i]);
//	}
//	//printf("%s", res);
//	return 0;
//}

int main()
{
	char str1[100] = "0";//用于储存两个字符串
	char str2[100] = "0";
	gets(str1);
	gets(str2);
	int del[255] = { 0 };//储存记录哈希表储存str2中的所有字符
	int i = 0;
	while (str2[i])//将str2中的所有字符储存在del哈希表中
	{
		del[str2[i++]]=1;
	}
	int j = 0;
	while (str1[j])
	{
		if (!del[str1[j]])//如果哈希表中没有存储该字符，则直接打印
			printf("%c", str1[j]);
		j++;
	}


	return 0;
}