#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include <stdio.h>


int main()
{
    int LINE_MAXIMUM = 0;
    scanf("%d", &LINE_MAXIMUM);
    int i = 0, j = 0;
    int** array = (int**)malloc(sizeof(int*) * LINE_MAXIMUM);
    for (int i = 0; i < LINE_MAXIMUM; i++) {
        array[i] = (int*)malloc(sizeof(int) * LINE_MAXIMUM);
    }
    int k = 0;


    for (i = 0; i < LINE_MAXIMUM; i++)
    {
        for (j = 0; j <= i; j++)    
        {
            if (j == 0 || j == i)  
                array[i][j] = 1;
            else                   
                array[i][j] = array[i - 1][j - 1]+ array[i - 1][j];
        }
    }

 
    for (i = 0; i < LINE_MAXIMUM; i++)
    {

        for (k = 1; k < LINE_MAXIMUM - i; k++)
            printf("  ");
        for (j = 0; j <= i; j++)
            printf("%3d ", array[i][j]);
        printf("\n");
    }
    return 0;
}
