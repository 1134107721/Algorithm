//链表Demo
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/* 定义链表的结点 包含数据域和指针域*/
typedef struct Node
{
    ElementType data;       //数据域
    struct Node * next;     //指针域(没有错 前面的struct Node是类型 就比如int * next一个道理)
}Node;
//头结点
typedef struct LinkList
{
    Node * next;   //头指针 如果链表有头结点，next就指向头结点。如果没有就指向第一个结点
    int length;     //链表的长度，初始值为0；

}LinkList;
//初始化链表
void InitLinkList(LinkList * linkList,ElementType * dataArray, int length);

//在制定的位置pos处插入元素element
void InsertLinkList(LinkList * linkList, int pos, ElementType element);
//删除链表中的位置为pos的结点；
ElementType DeleteLinkList(LinkList * linkList, int pos);
//打印链表
void PrintLinkList(LinkList * linkList);


#endif // LINKLIST_H_INCLUDED
