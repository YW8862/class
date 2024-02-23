/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param numbers int����һά����
 * @param numbersLen int numbers���鳤��
 * @param target int����
 * @return int����һά����
 * @return int* returnSize ������������
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 //ʹ�������������ͻ
typedef struct HashMapNode {
    int data;
    struct HashMapNode* next;
}HashMapNode, * HashMapHead;
//����������ڸ�ɢ�б����Ԫ��
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

    //����һ��ɢ�б���С��50000����Ҫ���뾡�����ٳ�ͻ��ͬʱ��������Щ�ڴ棩
    int hashMapLen = 50000;
    HashMapHead hash[hashMapLen];
    //��ʼ��ɢ�б�(��һ����ͦ�˷�ʱ��ģ��������治֪����ô��c�������ʼ��һ��ָ������Ϊnull)
    for (int j = 0; j < hashMapLen; j++) {
        hash[j] = NULL;
    }

    //work
    for (int i = 0; i < numbersLen; i++) {
        //ע�⣬�����ڼ�����������ǿ��Գ��ָ����ģ����Ҫ���о���ֵ����
        int index = abs((numbers[i]) % hashMapLen);
        //�����߼�˼·��ٷ�˼·��ͬ
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