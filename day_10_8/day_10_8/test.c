#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<assert.h>

void* my_memmove(void* dest, void* sour,size_t sz) 
{
	assert(dest && sour);
	void* res =dest;
	if (dest < sour)
		while (sz--)
			*((char*)dest)++ = *((char*)sour)++;
	else
		while (sz--)
			*((char*)dest + sz) = *((char*)sour + sz);
	return res;
}


int main()
{
	char arr[] = "abcdefghijklmnopq";
	char arr1[] = "abcdefghijklmnopq";
	char* res = my_memmove(arr+4, arr+1, 5);
	char* res1 = memmove(arr1+4, arr1+1, 5);
	printf("%s\n", arr);
	printf("%s\n", res);
	printf("%s\n", arr1);
	printf("%s\n", res1);
	return 0;
}