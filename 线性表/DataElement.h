
#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 255
//1.��������Ԫ��
typedef struct{
    int id;
    char * name;
}ElementType;
//2.����˳���ṹ
typedef struct{
    ElementType datas[MAX_SIZE];        //˳���������Ԫ�صļ���
    int length;                         //��ǰ˳����е�Ԫ�ظ���
}SeqList;


#endif // DATAELEMENT_H_INCLUDED
