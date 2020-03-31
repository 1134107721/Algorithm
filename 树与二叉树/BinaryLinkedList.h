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

typedef struct BinaryLinkedList{

};
//��bΪ���ڵ㣬����������
void CreateBinaryLinkedList(BiNode * b);
//����3��������CreateBinaryLinkedList���Ӻ��������������ʹ�õ�
void PreCreate(BiNode * b);     //ǰ�򴴽�
void InCreate(BiNode * b);      //���򴴽�
void PostCreate(BiNode * b);    //���򴴽�

//��ĳ��˳�����������
void TraverseBinaryTree(BiNode *b);
//����3��������TraverseBinaryTree���Ӻ���.
void PreOrderTraverse(BiNode *b);    //ǰ�����
void InOrderTraverse(BiNode *b);     //�������
void PostOrderTraverse(BiNode *b);   //�������


#endif // BINARYLINKEDLIST_H_INCLUDED
