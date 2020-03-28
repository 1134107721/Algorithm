#include "SequenceList.h"
/*
 *  初始化顺序表
 *  @param seqList      要初始化的顺序表
 *  @param elemArray    初始化时要添加的内容元素数组
 *  @param length       初始化时要添加的元素个数
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length)
{
    seqList->length = 0;
    //记得在初始化顺序表时，把顺序表长度置零
    for(int i = 0; i < length; i++)
    {
        InsertElement(seqList, i, elemArray[i]);
    }
}


/*
 *  向顺序表中index下标的位置处插入某个元素
 *  @param seqList      要初始化的顺序表
 *  @param index        要插入的下标
 *  @param element      要插入的元素
 */
 void InsertElement(SeqList * seqList, int index, ElementType element)
 {
     for(int i = seqList->length - 1; i >= index; i--)
     {
          seqList->datas[i + 1] = seqList->datas[i];
     }
     //将要插入的值赋给index个元素
     seqList->datas[index] = element;
     //顺序表的总长度加一 非常容易漏掉！！！！
     seqList->length++;
 }

ElementType * DeleteElement(SeqList * seqList, int index)
{
   //1.找到要删除的元素，保存起来以便返回（保存的是值不是地址。是副本）
   ElementType * delElement = (ElementType*)malloc(sizeof(ElementType)); //这一套操作可以写一个临时笔记了 临时笔记就在桌面
   //单独定义并调用查找函数，返回要删除元素的指针
   *delElement = *GetElement(seqList,index);

   //2.从指定位置删除，后面一个元素赋值给前面一个元素
   for(int i = index; i < seqList->length-1; i++)
   {
       seqList->datas[i] = seqList->datas[i + 1];
   }
   //3.顺序表的总长度-1
   seqList->length--;
    return delElement; // 这里没有错 就是返回的指针（指针变量指向的那块地址）。容易想当然的认为应该返回*delElement
    //使用完毕记得free  否则就会内存泄漏
}
ElementType * GetElement(SeqList * seqList, int index)
{
    ElementType * element; //这是要查找的元素，保存起来是为了返回
    element = &seqList->datas[index];
   return element;
}

void PrintList(SeqList * seqList)
{
    for(int i = 0; i < seqList->length; i++)
    {
        printf("%d\t%s\n",seqList->datas[i].id,seqList->datas[i].name);
    }
}























