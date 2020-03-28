//����Demo
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/* ��������Ľ�� �����������ָ����*/
typedef struct Node
{
    ElementType data;       //������
    struct Node * next;     //ָ����(û�д� ǰ���struct Node������ �ͱ���int * nextһ������)
}Node;
//ͷ���
typedef struct LinkList
{
    Node * next;   //ͷָ�� ���������ͷ��㣬next��ָ��ͷ��㡣���û�о�ָ���һ�����
    int length;     //����ĳ��ȣ���ʼֵΪ0��

}LinkList;
//��ʼ������
void InitLinkList(LinkList * linkList,ElementType * dataArray, int length);

//���ƶ���λ��pos������Ԫ��element
void InsertLinkList(LinkList * linkList, int pos, ElementType element);
//ɾ�������е�λ��Ϊpos�Ľ�㣻
ElementType DeleteLinkList(LinkList * linkList, int pos);
//��ӡ����
void PrintLinkList(LinkList * linkList);


#endif // LINKLIST_H_INCLUDED
