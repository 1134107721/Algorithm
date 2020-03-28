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
     坑爹的code block 除了sources和headers这两个文件夹 其他的什么都不要有！
     否则就会出现multiple definition的问题！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 */
ElementType dataArray[] = {
    {1,"van"},
    {2,"billy"},
    {3,"banana"},
    {4,"亚索"}
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

    //这一步和SeqString.c中第16行并不冲突。原因是这里是为整个HString类型的str申请内存空间，申请的
    //大小也是HString类型这么大。而SeqString.c中第16行是为str中的ch元素 单独申请内存空间
    HString * str1 = (HString *)malloc(sizeof(HString));
    HString * str2 = (HString *)malloc(sizeof(HString));

    AssignHeapString(str1, "abcdefg");
    PrintHeapString(str1);

    StrCpyHeapString(str2,str1);
    printf("\n复制后的str2：\n");
    PrintHeapString(str2);


    free(str1);
    free(str2);
}

void TestSequenceList()
{
    SeqList seqList;
    ElementType * delElement;  //这里定义指针是没错的。因为DeleteElement的返回值也是指针，用指针接收指针
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintList(&seqList);
    delElement = DeleteElement(&seqList,2);
    printf("删除后\n");
    PrintList(&seqList);
    printf("被删除的元素：\n");
    printf("%d\t%s\n",delElement->id,delElement->name);
    free(delElement);//记得free
}

void TestLinkList()
{
    LinkList linkList;
    linkList.length = 0;       //非常容易忽略。初始化长度为0
    InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintLinkList(&linkList);
    ElementType element;
    element.id = 123;
    element.name = (char*)malloc(10);
    strcpy(element.name, "木吉");
    InsertLinkList(&linkList, 2 , element);
    printf("插入后\n");
    PrintLinkList(&linkList);
    printf("删除第三个元素后\n");
    ElementType beenDeleted = DeleteLinkList(&linkList, 3);
    PrintLinkList(&linkList);
    printf("被删除的元素是\n");
    printf("%d\t%s\n",beenDeleted.id,beenDeleted.name);
}
void TestSeqStack(){
    SeqStack  s;
    InitStack(&s);
    for(int i = 0; i < 4; i++){
        printf("%d",Push(&s, dataArray[i]));
        printf("当前入栈：%d\t%s\n",dataArray[i].id, dataArray[i].name);
    }
    ElementType * e = (ElementType *)malloc(sizeof(ElementType));    //e用来存放弹出栈的元素。开辟一个空间
    Pop(&s, e);
    printf("当前出栈元素：%d\t%s\n",e->id,e->name);
    Pop(&s, e);
    printf("当前出栈元素：%d\t%s\n",e->id,e->name);
    for(int i = 0; i < s.length; i++){
        printf("栈里面还剩下：%d\t%s\n",s.data[i].id, s.data[i].name);
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
    printf("当前出队的元素是：\n");
    printf("%d\t%s\n", ele->id, ele->name);
    printf("出队操作之后的队列元素是：\n");
    for(int i = seq.front; i < seq.rear; i++){
        printf("%d\t%s\n", seq.data[i].id, seq.data[i].name);
    }
}










