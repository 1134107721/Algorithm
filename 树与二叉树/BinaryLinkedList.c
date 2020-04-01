#include "BinaryLinkedList.h"
#include "LinkedStack.h"
#include <stdio.h>
#include <stdlib.h>

void CreateBinaryLinkedList(BiNode * b){
    printf("��ѡ�񴴽���ʽ��ǰ�򴴽�����1�����򴴽�����2�����򴴽�����3����\n");
    int a;
    scanf("%d", &a);
    //��ʼ����������
    if(a == 1){
        printf("��ʼǰ�򴴽�������\n");
        PreCreate(b);
    }

    else if(a == 2){
        printf("��ʼ���򴴽�������\n");
        InCreate(b);
    }

    else if(a == 3){
        printf("��ʼ���򴴽�������\n");
        PostCreate(b);
    }

    else{
        printf("����Ĵ�����ʽ�����޷�����");
        return;
    }
    printf("�������\n");
}

//���ִ�����������ǰ��������򣩵ĺ���ʵ��
void PreCreate(BiNode * b){
    ElementType e;
    printf("���������id(�������-1����ô�Ͳ������֦���ϴ������):\n");
    scanf("%d",&e.id);
    if(e.id == -1){     //����û�������-1����ô���ý���״̬��Ϊ-999999���Ⱥ�������֮���ͷŸýڵ�

        /*
            Ϊʲô���ﲻֱ���ͷŽ�㲢�ÿ���
            ��������дfree(b);
                      b = NULL;
            ��������ȷ����free��b������ȴ�޷�ִ�еڶ��䣬Ҳ���ǽ�bָ��ָ��NULL
            �����b��Ϊһ��Ұָ��
            Ұָ��Ĵ���ǳ�Σ�ա����º����޷�ʹ��if(b == NULL)��������ж�
            Ҳ����˵����ĳ����޷��ж�b�Ƿ�Ϊ��ָ��

            ԭ�����֤���Ҳ²�Ӧ������Ϊb�ڸú�������һ���βΡ����β������ָ��ָ��null���²���
            ���ǿ���free������βΡ�

            ���Ҫָ�����ǣ�
                1.Ұָ��ǳ�Σ�գ����free��ĳ���ռ�֮�󣬲��Ѹÿռ��ÿգ���ֵΪNULL��
                  ��ô����ĳ�����޷�ͨ��if����жϸÿռ��Ƿ��ͷš�
                2.���������ķ����ǣ�free��ĳ�ռ�֮��(C++Ϊdeleteĳ���ռ�)�����̽��ÿռ�ָ��NULL
                  �Ա���Ұָ������ļ����鷳��
                3.�����������������ĳ�ռ���һ���βΡ���ô�Ͳ���ͨ��ָ��NULL�������βζ�Ӧ�ı����
                  ʵ��ָ���ÿա�����ȴ����ͨ��free(C++Ϊdelete),���βζ�Ӧ�����ʵ���ڴ��ͷš�
                4.�������3�ķ����� ���βθĳ� ָ��ָ���ָ�롣��������̫�����鷳�ˡ�
                5.��Ҫ������˵3�� ��malloc����free����free����NULL��
                                  ��malloc����free����free����NULL��
                                  ��malloc����free����free����NULL��
        */
        b->status = -999999;
        return;
    }


    printf("���������name:\n");
    scanf("%s",e.name);

    //����
    b->data = e;    //������Ľ����Ϣ��ֵ����ǰ����������
    b->lchild = (BiNode *)malloc(sizeof(BiNode));   //������ָ������ڴ�
    PreCreate(b->lchild);                           //�ݹ鴴��������
    if(b->lchild->status == -999999){    //�������ʧ�ܣ���ôɾ���ոշ�������ӵ��ڴ棬���ҽ�ָ���ÿ�
        free(b->lchild);
        b->lchild = NULL;
    }

    b->rchild = (BiNode *)malloc(sizeof(BiNode));   //���Һ���ָ������ڴ�
    PreCreate(b->rchild);                           //�ݹ鴴��������
    if(b->rchild->status == -999999){    //�������ʧ�ܣ���ôɾ���ոշ�����Һ��ӵ��ڴ棬���ҽ�ָ���ÿ�
        free(b->rchild);
        b->rchild = NULL;
    }
}
void InCreate(BiNode * b){

}
void PostCreate(BiNode * b){

}

//�����Ǳ����㷨
void TraverseBinaryTree(BiNode *b){
    printf("��ѡ�������ʽ��ǰ���������1�������������2�������������3\nǰ��ǵݹ��������4������ǵݹ��������5������ǵݹ��������6����\n");
    int a;
    scanf("%d", &a);
    //��ʼ����������
    if(a == 1){
        printf("��ʼǰ�����������\n");
        PreOrderTraverse(b);
    }

    else if(a == 2){
        printf("��ʼ�������������\n");
        InOrderTraverse(b);
    }

    else if(a == 3){
        printf("��ʼ�������������\n");
        PostOrderTraverse(b);
    }
    else if(a == 4){
        printf("��ʼǰ��ǵݹ����������\n");
        PreOrderTraverse_Re(b);
    }
    else if(a == 5){
        printf("��ʼ����ǵݹ����������\n");
        InOrderTraverse_Re(b);
    }
    else if(a == 6){
        printf("��ʼ����ǵݹ����������\n");
        PostOrderTraverse_Re(b);
    }

    else{
        printf("����ı�����ʽ�����޷�����");
        return;
    }
    printf("�������\n");
}
void PreOrderTraverse(BiNode *b){
    if(b == NULL)       //��Ӧ�����һ��ע�͡��������ͨ��if����ж�ָ���Ƿ�ΪNULL
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


void InOrderTraverse_Re(BiNode *b){
    //��������ķǵݹ��㷨
    //�����������ݽṹ ���������Ϊ�������㷨˼�롣��ô����ʵ�ַǵݹ�����������
    //�㷨˼�룺
        //1.��ʼʱɨ�������ջ����ɨ���������������㲢������һһ��ջ
        //2.��ջһ����㣬���������������Ǵ�ӡ����
        //3.ɨ��ýڵ���Һ��ӽ�㽫���ջ��ֻɨ�������Һ��ӣ��������У�
        //4.����ɨ���Һ��ӽ�������㲢������һһ��ջ����ʵ���ǵ�1�����ظ������Һ��ӽ�㿴���˸���㣩
        //5.�����ù���ֱ��ջ��Ϊֹ��

    LinkedStack *s = (LinkedStack*)malloc(sizeof(LinkedStack));     //����һ����ջ
    InitLinkedStack(s);
    BiNode * temp = b;          //����һ���м���������βη����������
    while(temp != NULL || s->length != 0){  //ֻҪ�����ڻ���ջ�ǿգ���ô�ͼ���ѭ��
        if(temp != NULL){
            Push(s,*temp);                  //��һ�����ø��ڵ��ջ
            temp = temp->lchild;                    //ͨ��ѭ���ø��ڵ�������ǽ�ջ
        }
        else{                               //else���������
            BiNode * t = (BiNode*)malloc(sizeof(BiNode));
            Pop(s,t);                   //ע�� ���ﲻ�ǽ��ս���ӳ�ȥ���ս�������û�н�ջ
                                        //    �����ǳ�ջһ����ʵ�Ľ�㡣
                                        //��ջ��ʵ���Ǹ���㣬��������ʱ����t����

            printf("%d\t%s\n",t->data.id,t->data.name);
            temp = t->rchild;           //��һ����ʱ����t����ý�㣬Ȼ��temp��ֵ��t���Һ���
            free(t);                    //����ռ�֮��ǵ��ͷţ����ҽ�ָ���ÿա��������Ұָ��
            t = NULL;
        }
    }
    free(s);

}
void PreOrderTraverse_Re(BiNode *b){    //ǰ������ķǵݹ��㷨

    //�����������ࡣ���Ǵ���˳���иı� �Ұ�ע�Ͷ�ɾ��

    LinkedStack *s = (LinkedStack*)malloc(sizeof(LinkedStack));
    InitLinkedStack(s);
    BiNode * temp = b;
    while(temp != NULL || s->length != 0){
        if(temp != NULL){
            printf("%d\t%s\n",temp->data.id,temp->data.name);     //�����������ͬ˳���������ȴ�ӡ
            Push(s,*temp);
            temp = temp->lchild;
        }
        else{
            BiNode * t = (BiNode*)malloc(sizeof(BiNode));
            Pop(s,t);
            temp = t->rchild;
            free(t);
            t = NULL;
        }
    }
    free(s);
}
void PostOrderTraverse_Re(BiNode *b){   //��������ķǵݹ��㷨  ע�� �����пӡ���������ķǵݹ��㷨�Ƚϸ��ӡ��ݲ�ʵ��

    ;
}
