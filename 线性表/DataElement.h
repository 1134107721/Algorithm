
#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 255
//1.定义数据元素
typedef struct{
    int id;
    char * name;
}ElementType;
//2.定义顺序表结构
typedef struct{
    ElementType datas[MAX_SIZE];        //顺序表中数据元素的集合
    int length;                         //当前顺序表中的元素个数
}SeqList;


#endif // DATAELEMENT_H_INCLUDED
