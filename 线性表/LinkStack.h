#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
//链栈
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
//结点 分为数据域和指针域。和链表的结点一模一样
typedef struct StackNode{
    ElementType data;
    struct StackNode * next;
}StackNode;
//存放栈顶指针的数据结构。里面有栈顶指针和栈的length
typedef struct LinkStack{
    StackNode * Top;
    int length;
}LinkStack;

//初始化栈
void InitLinkStack(LinkStack * s);

//压栈   将元素e压入栈中     返回值int为0代表失败，1为成功。
int LSPush(LinkStack * s, ElementType e);

//删除栈S中的栈顶元素，并用e来返回弹出的值     返回值int为0代表失败，1为成功。
int LSPop(LinkStack * s, ElementType * e);

//遍历打印栈内元素
void TraversalPrintStack(LinkStack * s);




#endif // LINKSTACK_H_INCLUDED
