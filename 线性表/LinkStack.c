#include "LinkStack.h"
#include <stdlib.h>

//��ʼ��ջ
void InitLinkStack(LinkStack * s){
    s->Top = NULL;
    s->length = 0;
}

//ѹջ   ��Ԫ��eѹ��ջ��     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int LSPush(LinkStack * s, ElementType e){
    StackNode * node = (StackNode *)malloc(sizeof(StackNode));     //����һ����㣬�ڵ�������ѹ��Ԫ��e����Ϣ
    node->data = e;
    node->next = s->Top;
    s->Top = node;
    s->length++;
    return 1;
}

//ɾ��ջS�е�ջ��Ԫ�أ�����e�����ص�����ֵ     ����ֵintΪ0����ʧ�ܣ�1Ϊ�ɹ���
int LSPop(LinkStack * s, ElementType * e){
    *e = s->Top->data;
    StackNode * node = s->Top;
    s->Top = s->Top->next;
    free(node);
    s->length--;
    return 1;
}

//������ӡջ��Ԫ��
void TraversalPrintStack(LinkStack * s){
    LinkStack * temp = s;
    while(temp->length != 0){
        printf("��ǰջ��Ԫ�أ�%d\t%s\n",temp->Top->data.id, temp->Top->data.name);
        temp->Top = temp->Top->next;
        temp->length--;
    }
}
