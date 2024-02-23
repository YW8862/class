#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>


#define MaxSize 1000;//定义通讯录最大容量

//定义通讯录联系人类型
typedef struct 
{
	char name[20];//联系人姓名
	char gender[10];//联系人性别
	unsigned int age;//联系人年龄
	unsigned long long int tel;//联系人电话
	char address[120];
}contact;

