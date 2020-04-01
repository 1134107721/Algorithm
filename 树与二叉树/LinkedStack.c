#include "LinkedStack.h"
#include <stdlib.h>

//初始化栈
void InitLinkedStack(LinkedStack * s){
    s->Top = NULL;
    s->length = 0;
}


int Push(LinkedStack * s, BiNode e){
    StackNode * node = (StackNode *)malloc(sizeof(StackNode));     //创建一个结点，节点里存放新压入元素e的信息
    node->data = e;
    node->next = s->Top;
    s->Top = node;
    s->length++;
    return 1;
}


int Pop(LinkedStack * s, BiNode* e){
    *e = s->Top->data;
    StackNode * node = s->Top;
    s->Top = s->Top->next;
    free(node);
    node = NULL;
    s->length--;
    return 1;
}


void IsStackEmpty(LinkedStack * s){

}
