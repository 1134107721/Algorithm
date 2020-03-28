#include "SeqStack.h"
#include <stdlib.h>

//��ʼ��ջ
void InitStack(SeqStack * s){
    s->top = -1;
    s->length = 0;
}

//ѹջ   ��Ԫ��eѹ��ջ��     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int Push(SeqStack * s, ElementType e){
    if(s->top == MAX_SIZE - 1)     //���ջ���ˣ���ô����ʧ�ܣ�����0
        return 0;
    s->top++;
    s->data[s->top] = e;
    s->length++;
    return 1;
}

//ɾ��ջS�е�ջ��Ԫ�أ�����e�����ص�����ֵ     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int Pop(SeqStack * s, ElementType * e){
    if(s->top == -1)        //���ջ�ǿյģ���ôɾ��ʧ�ܣ�����0
        return 0;
    *e = s->data[s->top];
    s->top--;
    s->length--;
    return 1;
}
