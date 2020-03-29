#include "LinkStack.h"
#include <stdlib.h>

//初始化栈
void InitLinkStack(LinkStack * s){
    s->Top = NULL;
    s->length = 0;
}

//压栈   将元素e压入栈中     返回值int为0代表失败，1为成功。
int LSPush(LinkStack * s, ElementType e){
    StackNode * node = (StackNode *)malloc(sizeof(StackNode));     //创建一个结点，节点里存放新压入元素e的信息
    node->data = e;
    node->next = s->Top;
    s->Top = node;
    s->length++;
    return 1;
}

//删除栈S中的栈顶元素，并用e来返回弹出的值     返回值int为0代表失败，1为成功。
int LSPop(LinkStack * s, ElementType * e){
    *e = s->Top->data;
    StackNode * node = s->Top;
    s->Top = s->Top->next;
    free(node);
    s->length--;
    return 1;
}

//遍历打印栈内元素
void TraversalPrintStack(LinkStack * s){
    LinkStack * temp = s;
    while(temp->length != 0){
        printf("当前栈内元素：%d\t%s\n",temp->Top->data.id, temp->Top->data.name);
        temp->Top = temp->Top->next;
        temp->length--;
    }
}
