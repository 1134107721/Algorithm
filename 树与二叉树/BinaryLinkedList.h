//二叉链表（二叉树的链式存储结构）
#ifndef BINARYLINKEDLIST_H_INCLUDED
#define BINARYLINKEDLIST_H_INCLUDED
#include "DataElement.h"

//定义二叉链表结点的存储结构
typedef struct BiNode{
    int key;                    //按照完全二叉树的方法给树的结点编号
    int status;             //判断该结点是否成功创建
    ElementType data;           //数据域
    struct BiNode * lchild;     //左孩子（指针域）
    struct BiNode * rchild;     //右孩子（指针域）
}BiNode;

//以b为根节点，创建二叉树
void CreateBinaryLinkedList(BiNode * b);
//以下3个函数是CreateBinaryLinkedList的子函数，用来配合它使用的
void PreCreate(BiNode * b);     //前序创建
void InCreate(BiNode * b);      //中序创建
void PostCreate(BiNode * b);    //后序创建

//以某种顺序遍历二叉树
void TraverseBinaryTree(BiNode *b);
//以下6个函数是TraverseBinaryTree的子函数.
void PreOrderTraverse(BiNode *b);    //前序遍历
void InOrderTraverse(BiNode *b);     //中序遍历
void PostOrderTraverse(BiNode *b);   //后序遍历

void InOrderTraverse_Re(BiNode *b);     //中序遍历的非递归算法
void PreOrderTraverse_Re(BiNode *b);    //前序遍历的非递归算法
void PostOrderTraverse_Re(BiNode *b);   //后序遍历的非递归算法    注意 这里有坑。后序遍历的非递归算法比较复杂。暂不实现

#endif // BINARYLINKEDLIST_H_INCLUDED
