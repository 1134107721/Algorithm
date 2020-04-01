#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
//链栈
//这个链栈用来非递归遍历二叉树而特别制造
#include <stdio.h>
#include <stdlib.h>
#include "BinaryLinkedList.h"
//结点 注意data就是二叉树的结点
typedef struct StackNode{
    BiNode data;
    struct StackNode * next;
}StackNode;
//存放栈顶指针的数据结构。里面有栈顶指针和栈的length
typedef struct LinkedStack{
    StackNode * Top;
    int length;
}LinkedStack;

//初始化栈
void InitLinkedStack(LinkedStack * s);

//压栈   将元素e压入栈中     返回值int为0代表失败，1为成功。
int Push(LinkedStack * s, BiNode e);

//删除栈S中的栈顶元素，并用e来返回弹出的值     返回值int为0代表失败，1为成功。
int Pop(LinkedStack * s, BiNode * e);

//判断栈是否为空
void IsStackEmpty(LinkedStack * s);



#endif // LINKEDSTACK_H_INCLUDED
