#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
//��ջ
//�����ջ�����ǵݹ�������������ر�����
#include <stdio.h>
#include <stdlib.h>
#include "BinaryLinkedList.h"
//��� ע��data���Ƕ������Ľ��
typedef struct StackNode{
    BiNode data;
    struct StackNode * next;
}StackNode;
//���ջ��ָ������ݽṹ��������ջ��ָ���ջ��length
typedef struct LinkedStack{
    StackNode * Top;
    int length;
}LinkedStack;

//��ʼ��ջ
void InitLinkedStack(LinkedStack * s);

//ѹջ   ��Ԫ��eѹ��ջ��     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int Push(LinkedStack * s, BiNode e);

//ɾ��ջS�е�ջ��Ԫ�أ�����e�����ص�����ֵ     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int Pop(LinkedStack * s, BiNode * e);

//�ж�ջ�Ƿ�Ϊ��
void IsStackEmpty(LinkedStack * s);



#endif // LINKEDSTACK_H_INCLUDED
