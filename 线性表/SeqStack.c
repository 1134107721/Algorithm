#include "SeqStack.h"
#include <stdlib.h>

//初始化栈
void InitStack(SeqStack * s){
    s->top = -1;
    s->length = 0;
}

//压栈   将元素e压入栈中     返回值int为0代表失败，1为成功。
int Push(SeqStack * s, ElementType e){
    if(s->top == MAX_SIZE - 1)     //如果栈满了，那么插入失败，返回0
        return 0;
    s->top++;
    s->data[s->top] = e;
    s->length++;
    return 1;
}

//删除栈S中的栈顶元素，并用e来返回弹出的值     返回值int为0代表失败，1为成功。
int Pop(SeqStack * s, ElementType * e){
    if(s->top == -1)        //如果栈是空的，那么删除失败，返回0
        return 0;
    *e = s->data[s->top];
    s->top--;
    s->length--;
    return 1;
}
