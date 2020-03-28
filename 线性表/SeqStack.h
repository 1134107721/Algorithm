//顺序栈Demo
#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED
#include "DataElement.h"
typedef struct{
    ElementType data[MAX_SIZE];
    int top;    //用于栈顶指针
    int length; //栈长度
}SeqStack;
//初始化栈
void InitStack(SeqStack * s);

//压栈   将元素e压入栈中     返回值int为0代表失败，1为成功。
int Push(SeqStack * s, ElementType e);

//删除栈S中的栈顶元素，并用e来返回弹出的值     返回值int为0代表失败，1为成功。
int Pop(SeqStack * s, ElementType * e);

#endif // SEQSTACK_H_INCLUDED
