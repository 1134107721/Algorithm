//˳��ջDemo
#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED
#include "DataElement.h"
typedef struct{
    ElementType data[MAX_SIZE];
    int top;    //����ջ��ָ��
    int length; //ջ����
}SeqStack;
//��ʼ��ջ
void InitStack(SeqStack * s);

//ѹջ   ��Ԫ��eѹ��ջ��     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int Push(SeqStack * s, ElementType e);

//ɾ��ջS�е�ջ��Ԫ�أ�����e�����ص�����ֵ     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int Pop(SeqStack * s, ElementType * e);

#endif // SEQSTACK_H_INCLUDED
