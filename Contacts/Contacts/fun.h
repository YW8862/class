#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>


#define MaxSize 1000;//����ͨѶ¼�������

//����ͨѶ¼��ϵ������
typedef struct 
{
	char name[20];//��ϵ������
	char gender[10];//��ϵ���Ա�
	unsigned int age;//��ϵ������
	unsigned long long int tel;//��ϵ�˵绰
	char address[120];
}contact;

