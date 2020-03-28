#include "LinkList.h"



void InitLinkList(LinkList * linkList,ElementType * dataArray, int length)
{
    for(int i = 0; i < length; i++){
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}


void InsertLinkList(LinkList * linkList, int pos, ElementType element)
{
    //1.创建空结点并给数据域赋值
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;  //初始化置空
    //2.找到要插入位置的结点
    if(pos == 1) //如果插入的是第一个元素（问题在于 左边的接上了，右边没有接上 node的next域还是NULL）
    {
        node->next = linkList->next;    //接上右边
        linkList->next = node;      //接上左边    //头指针指向了新创建的结点
        linkList->length++;
        return;
    }
    //通过循环找到要插入结点的位置
    Node * currNode = linkList->next;//又创建了一个结点，这个结点指向头指针指向的地方（第一个结点）
    for(int i = 1; currNode && i < pos - 1; i++)
    {
        currNode = currNode->next;
    }
    //将结点插入并对接前面的结点
    if(currNode)
    {
        node->next = currNode->next;
        currNode->next = node;
        linkList->length++;
    }
}
ElementType DeleteLinkList(LinkList * linkList, int pos)
{
    ElementType element;        //要删除的元素。这个变量就是保存要删除的元素
    element.id = -999;          //附一个不可能的值，验证是否删除成功
    Node * node = NULL;
    if(pos == 1)                //如果要删除的结点是第一个结点
    {
        node = linkList->next;
        if(node)
        {
           element = node->data;
           linkList->next = node->next;
           free(node);      //释放被删除结点的内存
           linkList->length--;
        }
        return element;
    }

    //1.找到要删除结点和他的前缀结点
    //2.要删除结点的next赋值给前缀结点的next
    //3.释放要删除的节点内存
    Node * preNode;  //前缀结点
    node = linkList->next;
    for(int i = 1; i < pos && node; i++)
    {
        preNode = node;     //保存node之前的那个结点（前缀结点）
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
        printf("链表为空\n");
        linkList->length = 0;
        return;
    }
    for(int i = 0; i < linkList->length; i++)
    {
        printf("%d\t%s\n",node->data.id,node->data.name);
        node = node->next;
    }
}

