#include "LinkedStack.h"
#include <stdlib.h>

//��ʼ��ջ
void InitLinkedStack(LinkedStack * s){
    s->Top = NULL;
    s->length = 0;
}


int Push(LinkedStack * s, BiNode e){
    StackNode * node = (StackNode *)malloc(sizeof(StackNode));     //����һ����㣬�ڵ�������ѹ��Ԫ��e����Ϣ
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
