//定义顺序表
#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/*
 *  初始化顺序表
 *  @param seqList      要初始化的顺序表
 *  @param elemArray    初始化时要添加的内容元素数组
 *  @param length       初始化时要添加的元素个数
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length);



/*
 *  初始化顺序表
 *  @param seqList      向顺序表中index下标的位置处插入某个元素
 *  @param index        要插入的下标
 *  @param element      要插入的元素
 */
 void InsertElement(SeqList * seqList, int index, ElementType element);


 /*
 *  删除顺序表中指定下标的元素
 *  @param seqList      要操作的顺序表
 *  @param index        要删除的下标
 *  @return             返回删除的元素，如果删除失败，返回null
 */

ElementType * DeleteElement(SeqList * seqList, int index);
 /*
 *  查找顺序表中指定下标的元素
 *  @param seqList      要操作的顺序表
 *  @param index        要查找元素的下标
 *  @return             返回要查找的元素，如果查找失败，返回null
 */
ElementType * GetElement(SeqList * seqList, int index);

 //打印顺序表 @param seqList 要打印的顺序表
 void PrintList(SeqList * seqList);



#endif // SEQUENCELIST_H_INCLUDED
