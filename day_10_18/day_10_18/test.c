#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

//int main()
//{
//	long long num = 0;//���ڽ�������
//	scanf("%lld", &num);
//	char res[20] = { 0 };//ʹ���ַ��������򴢴�ÿһλ��
//	int i = 0;
//	while (num)//��������д���
//	{
//		if (i % 4 == 3&&i!=0)
//			res[i++] = ',';
//		res[i++] = num % 10+48;
//		num /= 10;
//	}
//	while (i--)//�����ӡ����
//	{
//		printf("%c", res[i]);
//	}
//	//printf("%s", res);
//	return 0;
//}

int main()
{
	char str1[100] = "0";//���ڴ��������ַ���
	char str2[100] = "0";
	gets(str1);
	gets(str2);
	int del[255] = { 0 };//�����¼��ϣ����str2�е������ַ�
	int i = 0;
	while (str2[i])//��str2�е������ַ�������del��ϣ����
	{
		del[str2[i++]]=1;
	}
	int j = 0;
	while (str1[j])
	{
		if (!del[str1[j]])//�����ϣ����û�д洢���ַ�����ֱ�Ӵ�ӡ
			printf("%c", str1[j]);
		j++;
	}


	return 0;
}