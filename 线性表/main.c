#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "SequenceList.h"
#include "LinkList.h"
#include "SeqQueue.h"
#include "SeqString.h"
#include "SeqStack.h"
//#include "LinkList.c"

/*
     �ӵ���code block ����sources��headers�������ļ��� ������ʲô����Ҫ�У�
     ����ͻ����multiple definition�����⣡��������������������������������������������������������������
     ������������������������������������������������������������������������������������������������������
     ������������������������������������������������������������������������������������������������������
     ������������������������������������������������������������������������������������������������������������
     ������������������������������������������������������������������������������������������������������������
     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     ������������������������������������������������������������������������������������������������������
 */
ElementType dataArray[] = {
    {1,"van"},
    {2,"billy"},
    {3,"banana"},
    {4,"����"}
};

void TestSequenceList();
void TestLinkList();
void TestSeqStack();
void TestSeqQueue();
void TestSeqString();

int main()
{
    //TestSequenceList();
    //TestLinkList();
    //TestSeqQueue();
    //TestSeqString();
    TestSeqStack();
    return 0;
}

void TestSeqString(){

    //��һ����SeqString.c�е�16�в�����ͻ��ԭ����������Ϊ����HString���͵�str�����ڴ�ռ䣬�����
    //��СҲ��HString������ô�󡣶�SeqString.c�е�16����Ϊstr�е�chԪ�� ���������ڴ�ռ�
    HString * str1 = (HString *)malloc(sizeof(HString));
    HString * str2 = (HString *)malloc(sizeof(HString));

    AssignHeapString(str1, "abcdefg");
    PrintHeapString(str1);

    StrCpyHeapString(str2,str1);
    printf("\n���ƺ��str2��\n");
    PrintHeapString(str2);


    free(str1);
    free(str2);
}

void TestSequenceList()
{
    SeqList seqList;
    ElementType * delElement;  //���ﶨ��ָ����û��ġ���ΪDeleteElement�ķ���ֵҲ��ָ�룬��ָ�����ָ��
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintList(&seqList);
    delElement = DeleteElement(&seqList,2);
    printf("ɾ����\n");
    PrintList(&seqList);
    printf("��ɾ����Ԫ�أ�\n");
    printf("%d\t%s\n",delElement->id,delElement->name);
    free(delElement);//�ǵ�free
}

void TestLinkList()
{
    LinkList linkList;
    linkList.length = 0;       //�ǳ����׺��ԡ���ʼ������Ϊ0
    InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintLinkList(&linkList);
    ElementType element;
    element.id = 123;
    element.name = (char*)malloc(10);
    strcpy(element.name, "ľ��");
    InsertLinkList(&linkList, 2 , element);
    printf("�����\n");
    PrintLinkList(&linkList);
    printf("ɾ��������Ԫ�غ�\n");
    ElementType beenDeleted = DeleteLinkList(&linkList, 3);
    PrintLinkList(&linkList);
    printf("��ɾ����Ԫ����\n");
    printf("%d\t%s\n",beenDeleted.id,beenDeleted.name);
}
void TestSeqStack(){
    SeqStack  s;
    InitStack(&s);
    for(int i = 0; i < 4; i++){
        printf("%d",Push(&s, dataArray[i]));
        printf("��ǰ��ջ��%d\t%s\n",dataArray[i].id, dataArray[i].name);
    }
    ElementType * e = (ElementType *)malloc(sizeof(ElementType));    //e������ŵ���ջ��Ԫ�ء�����һ���ռ�
    Pop(&s, e);
    printf("��ǰ��ջԪ�أ�%d\t%s\n",e->id,e->name);
    Pop(&s, e);
    printf("��ǰ��ջԪ�أ�%d\t%s\n",e->id,e->name);
    for(int i = 0; i < s.length; i++){
        printf("ջ���滹ʣ�£�%d\t%s\n",s.data[i].id, s.data[i].name);
    }

}


void TestSeqQueue(){
    SeqQueqe seq;
    InitSeqQueue(&seq);
    OfferSeqQueue(&seq, dataArray[0]);
    OfferSeqQueue(&seq, dataArray[1]);
    OfferSeqQueue(&seq, dataArray[2]);
    OfferSeqQueue(&seq, dataArray[3]);
    for(int i = seq.front; i < seq.rear; i++){
        printf("%d\t%s\n", seq.data[i].id, seq.data[i].name);
    }
    ElementType * ele =  (ElementType *)malloc(sizeof(ElementType));
    PollSeqQueue(&seq, ele);
    printf("��ǰ���ӵ�Ԫ���ǣ�\n");
    printf("%d\t%s\n", ele->id, ele->name);
    printf("���Ӳ���֮��Ķ���Ԫ���ǣ�\n");
    for(int i = seq.front; i < seq.rear; i++){
        printf("%d\t%s\n", seq.data[i].id, seq.data[i].name);
    }
}










