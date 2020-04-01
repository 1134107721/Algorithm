//������������������ʽ�洢�ṹ��
#ifndef BINARYLINKEDLIST_H_INCLUDED
#define BINARYLINKEDLIST_H_INCLUDED
#include "DataElement.h"

//�������������Ĵ洢�ṹ
typedef struct BiNode{
    int key;                    //������ȫ�������ķ��������Ľ����
    int status;             //�жϸý���Ƿ�ɹ�����
    ElementType data;           //������
    struct BiNode * lchild;     //���ӣ�ָ����
    struct BiNode * rchild;     //�Һ��ӣ�ָ����
}BiNode;

//��bΪ���ڵ㣬����������
void CreateBinaryLinkedList(BiNode * b);
//����3��������CreateBinaryLinkedList���Ӻ��������������ʹ�õ�
void PreCreate(BiNode * b);     //ǰ�򴴽�
void InCreate(BiNode * b);      //���򴴽�
void PostCreate(BiNode * b);    //���򴴽�

//��ĳ��˳�����������
void TraverseBinaryTree(BiNode *b);
//����6��������TraverseBinaryTree���Ӻ���.
void PreOrderTraverse(BiNode *b);    //ǰ�����
void InOrderTraverse(BiNode *b);     //�������
void PostOrderTraverse(BiNode *b);   //�������

void InOrderTraverse_Re(BiNode *b);     //��������ķǵݹ��㷨
void PreOrderTraverse_Re(BiNode *b);    //ǰ������ķǵݹ��㷨
void PostOrderTraverse_Re(BiNode *b);   //��������ķǵݹ��㷨    ע�� �����пӡ���������ķǵݹ��㷨�Ƚϸ��ӡ��ݲ�ʵ��

#endif // BINARYLINKEDLIST_H_INCLUDED
