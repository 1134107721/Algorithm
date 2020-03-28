#include "LinkList.h"



void InitLinkList(LinkList * linkList,ElementType * dataArray, int length)
{
    for(int i = 0; i < length; i++){
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}


void InsertLinkList(LinkList * linkList, int pos, ElementType element)
{
    //1.�����ս�㲢��������ֵ
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;  //��ʼ���ÿ�
    //2.�ҵ�Ҫ����λ�õĽ��
    if(pos == 1) //���������ǵ�һ��Ԫ�أ��������� ��ߵĽ����ˣ��ұ�û�н��� node��next����NULL��
    {
        node->next = linkList->next;    //�����ұ�
        linkList->next = node;      //�������    //ͷָ��ָ�����´����Ľ��
        linkList->length++;
        return;
    }
    //ͨ��ѭ���ҵ�Ҫ�������λ��
    Node * currNode = linkList->next;//�ִ�����һ����㣬������ָ��ͷָ��ָ��ĵط�����һ����㣩
    for(int i = 1; currNode && i < pos - 1; i++)
    {
        currNode = currNode->next;
    }
    //�������벢�Խ�ǰ��Ľ��
    if(currNode)
    {
        node->next = currNode->next;
        currNode->next = node;
        linkList->length++;
    }
}
ElementType DeleteLinkList(LinkList * linkList, int pos)
{
    ElementType element;        //Ҫɾ����Ԫ�ء�����������Ǳ���Ҫɾ����Ԫ��
    element.id = -999;          //��һ�������ܵ�ֵ����֤�Ƿ�ɾ���ɹ�
    Node * node = NULL;
    if(pos == 1)                //���Ҫɾ���Ľ���ǵ�һ�����
    {
        node = linkList->next;
        if(node)
        {
           element = node->data;
           linkList->next = node->next;
           free(node);      //�ͷű�ɾ�������ڴ�
           linkList->length--;
        }
        return element;
    }

    //1.�ҵ�Ҫɾ����������ǰ׺���
    //2.Ҫɾ������next��ֵ��ǰ׺����next
    //3.�ͷ�Ҫɾ���Ľڵ��ڴ�
    Node * preNode;  //ǰ׺���
    node = linkList->next;
    for(int i = 1; i < pos && node; i++)
    {
        preNode = node;     //����node֮ǰ���Ǹ���㣨ǰ׺��㣩
        node = node->next;
    }
    if(node)
    {
        element = node->data;
        preNode->next = node->next;
        free(node);
        linkList->length--;
    }
    return element;








}
void PrintLinkList(LinkList * linkList)
{
    Node * node = linkList->next;
    if(!node)
    {
        printf("����Ϊ��\n");
        linkList->length = 0;
        return;
    }
    for(int i = 0; i < linkList->length; i++)
    {
        printf("%d\t%s\n",node->data.id,node->data.name);
        node = node->next;
    }
}

