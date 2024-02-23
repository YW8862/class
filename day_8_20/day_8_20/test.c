/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param numbers int整型一维数组
 * @param numbersLen int numbers数组长度
 * @param target int整型
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 //使用拉链法解决冲突
typedef struct HashMapNode {
    int data;
    struct HashMapNode* next;
}HashMapNode, * HashMapHead;
//这个函数用于给散列表添加元素
void addHashMapNode(HashMapHead* head, int index) {
    HashMapHead a = (HashMapHead)malloc(sizeof(HashMapNode));
    a->data = index;
    a->next = NULL;
    if (*head == NULL) {
        *head = a;
    }
    else {
        HashMapHead temp = *head;
        HashMapHead b;
        while (temp != NULL) {
            b = temp;
            temp = temp->next;
        }
        a->next = b->next;
        b->next = a;
    }
}
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    // write code here
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize += 2;

    //创建一个散列表，大小：50000（主要是想尽量减少冲突的同时，又少用些内存）
    int hashMapLen = 50000;
    HashMapHead hash[hashMapLen];
    //初始化散列表(这一步是挺浪费时间的，但是我真不知道怎么在c语言里初始化一个指针数组为null)
    for (int j = 0; j < hashMapLen; j++) {
        hash[j] = NULL;
    }

    //work
    for (int i = 0; i < numbersLen; i++) {
        //注意，求余在计算机语言中是可以出现负数的，因此要进行绝对值处理
        int index = abs((numbers[i]) % hashMapLen);
        //下面逻辑思路与官方思路相同
        if (hash[index] != NULL) {
            HashMapHead temp = hash[index];
            while (temp != NULL) {
                if (numbers[temp->data] + numbers[i] == target) {
                    result[0] = temp->data + 1;
                    result[1] = i + 1;
                    return result;
                }
                temp = temp->next;
            }
            int newIndex = abs((target - numbers[i]) % hashMapLen);
            addHashMapNode(&hash[newIndex], i);
        }
        else {
            int newIndex = abs((target - numbers[i]) % hashMapLen);
            addHashMapNode(&hash[newIndex], i);
        }
    }
    return result;
}