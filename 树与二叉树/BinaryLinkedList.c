#include "BinaryLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void CreateBinaryLinkedList(BiNode * b){
    printf("请选择创建方式（前序创建输入1，中序创建输入2，后序创建输入3）：\n");
    int a;
    scanf("%d", &a);
    //开始创建二叉树
    if(a == 1){
        printf("开始前序创建二叉树\n");
        PreCreate(b);
    }

    else if(a == 2){
        printf("开始中序创建二叉树\n");
        InCreate(b);
    }

    else if(a == 3){
        printf("开始后序创建二叉树\n");
        PostCreate(b);
    }

    else{
        printf("输入的创建方式有误，无法创建");
        return;
    }
    printf("创建完成\n");
}

//三种创建二叉树（前序中序后序）的函数实现
void PreCreate(BiNode * b){
    ElementType e;
    printf("请输入结点的id(如果输入-1，那么就不在这个枝干上创建结点):\n");
    scanf("%d",&e.id);
    if(e.id == -1){     //如果用户输入了-1，那么将该结点的状态设为-999999，等函数返回之后释放该节点

        /*
            为什么这里不直接释放结点并置空呢
            比如这里写free(b);
                      b = NULL;
            这样做的确可以free掉b。但是却无法执行第二句，也就是将b指针指向NULL
            后果是b成为一个野指针
            野指针的错误非常危险。导致后面无法使用if(b == NULL)这个条件判断
            也就是说后面的程序将无法判断b是否为空指针

            原因待考证，我猜测应该是因为b在该函数中是一个形参。将形参这个空指针指向null恐怕不行
            但是可以free掉这个形参。

            最后要指出的是：
                1.野指针非常危险，如果free掉某个空间之后，不把该空间置空（赋值为NULL）
                  那么后面的程序就无法通过if语句判断该空间是否被释放。
                2.解决该问题的方法是，free掉某空间之后(C++为delete某个空间)，立刻将该空间指向NULL
                  以避免野指针带来的极大麻烦。
                3.如果遇到这里的情况，某空间是一个形参。那么就不能通过指向NULL来将该形参对应的背后的
                  实参指针置空。但是却可以通过free(C++为delete),将形参对应背后的实参内存释放。
                4.解决问题3的方法是 将形参改成 指向指针的指针。这样做就太过于麻烦了。
                5.重要的事情说3遍 有malloc就有free，有free就有NULL！
                                  有malloc就有free，有free就有NULL！
                                  有malloc就有free，有free就有NULL！
        */
        b->status = -999999;
        return;
    }


    printf("请输入结点的name:\n");
    scanf("%s",e.name);

    //以下
    b->data = e;    //将输入的结点信息赋值给当前结点的数据域
    b->lchild = (BiNode *)malloc(sizeof(BiNode));   //给左孩子指针分配内存
    PreCreate(b->lchild);                           //递归创建左子树
    if(b->lchild->status == -999999){    //如果创建失败，那么删除刚刚分配的左孩子的内存，并且将指针置空
        free(b->lchild);
        b->lchild = NULL;
    }

    b->rchild = (BiNode *)malloc(sizeof(BiNode));   //给右孩子指针分配内存
    PreCreate(b->rchild);                           //递归创建右子树
    if(b->rchild->status == -999999){    //如果创建失败，那么删除刚刚分配的右孩子的内存，并且将指针置空
        free(b->rchild);
        b->rchild = NULL;
    }
}
void InCreate(BiNode * b){

}
void PostCreate(BiNode * b){

}

//以下是遍历算法
void TraverseBinaryTree(BiNode *b){
    printf("请选择遍历方式（前序遍历输入1，中序遍历输入2，后序遍历输入3）：\n");
    int a;
    scanf("%d", &a);
    //开始遍历二叉树
    if(a == 1){
        printf("开始前序遍历二叉树\n");
        PreOrderTraverse(b);
    }

    else if(a == 2){
        printf("开始中序遍历二叉树\n");
        InOrderTraverse(b);
    }

    else if(a == 3){
        printf("开始后序遍历二叉树\n");
        PostOrderTraverse(b);
    }

    else{
        printf("输入的遍历方式有误，无法遍历");
        return;
    }
    printf("遍历完成\n");
}
void PreOrderTraverse(BiNode *b){
    if(b == NULL)       //对应上面的一大串注释。这里就是通过if语句判断指针是否为NULL
        return;
    printf("%d\t%s\n",b->data.id,b->data.name);
    PreOrderTraverse(b->lchild);
    PreOrderTraverse(b->rchild);
}
void InOrderTraverse(BiNode *b){
    if(b == NULL)
        return;
    InOrderTraverse(b->lchild);
    printf("%d\t%s\n",b->data.id,b->data.name);
    InOrderTraverse(b->rchild);
}
void PostOrderTraverse(BiNode *b){
    if(b == NULL)
        return;
    PostOrderTraverse(b->lchild);
    PostOrderTraverse(b->rchild);
    printf("%d\t%s\n",b->data.id,b->data.name);
}
