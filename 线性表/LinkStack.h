#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
//��ջ
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
//��� ��Ϊ�������ָ���򡣺�����Ľ��һģһ��
typedef struct StackNode{
    ElementType data;
    struct StackNode * next;
}StackNode;
//���ջ��ָ������ݽṹ��������ջ��ָ���ջ��length
typedef struct LinkStack{
    StackNode * Top;
    int length;
}LinkStack;

//��ʼ��ջ
void InitLinkStack(LinkStack * s);

//ѹջ   ��Ԫ��eѹ��ջ��     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int LSPush(LinkStack * s, ElementType e);

//ɾ��ջS�е�ջ��Ԫ�أ�����e�����ص�����ֵ     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int LSPop(LinkStack * s, ElementType * e);

//������ӡջ��Ԫ��
void TraversalPrintStack(LinkStack * s);




#endif // LINKSTACK_H_INCLUDED
