#include "mystring.h"

char* strstr(const char* str1, const char* str2)
{
	//��ȡstr1��str2�ĳ���
	size_t size1 = strlen(str1), size2 = strlen(str2);
	//���str2Ϊ�գ�ֱ�ӷ���
	if (size2 == 0)
	{
		return str1;
	}
	
	if (size1 < size2)
	{
		return NULL;
	}
	for (int i = 0; i < size1; i++)
	{
		//˵��δƥ�䵽ͷ�ַ�
		if (str1[i] != str2[0])
		{
			continue;
		}
		//ƥ�䵽ͷ�ַ�
		for (int j = 0; j < size2; j++)
		{
			//ƥ�䵽���һ���ַ�
			if (j == size2 - 1 && str1[i + j] == str2[j])
			{
				return str1 + i;
			}
			else if (str1[i + j] != str2[j])
			{
				break;
			}
		}
	}
	return NULL;
}

int main()
{
	char* ret1 = strstr("ASDFGHJKL", "DFG");
	char* ret2 = strstr("ASDFGHJKL", "HJKL");
	char* ret3 = strstr("ASDFGHJKL", "DFH");
	char* ret4 = strstr("ASDFGHJKL", "HJKLP");
	char* ret5 = strstr("ASDFGHJKL", "");

	printf("ret1:%p\n", ret1);
	printf("ret2:%p\n", ret2);
	printf("ret3:%p\n", ret3);
	printf("ret4:%p\n", ret4);
	printf("ret5:%p\n", ret5);

	printf("ret1 = %s\n", ret1);
	printf("ret2 = %s\n", ret2);
	printf("ret5 = %s\n", ret5);
	return 0;
}