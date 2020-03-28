//����˳���
#ifndef SEQUENCELIST_H_INCLUDED
#define SEQUENCELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"
/*
 *  ��ʼ��˳���
 *  @param seqList      Ҫ��ʼ����˳���
 *  @param elemArray    ��ʼ��ʱҪ��ӵ�����Ԫ������
 *  @param length       ��ʼ��ʱҪ��ӵ�Ԫ�ظ���
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length);



/*
 *  ��ʼ��˳���
 *  @param seqList      ��˳�����index�±��λ�ô�����ĳ��Ԫ��
 *  @param index        Ҫ������±�
 *  @param element      Ҫ�����Ԫ��
 */
 void InsertElement(SeqList * seqList, int index, ElementType element);


 /*
 *  ɾ��˳�����ָ���±��Ԫ��
 *  @param seqList      Ҫ������˳���
 *  @param index        Ҫɾ�����±�
 *  @return             ����ɾ����Ԫ�أ����ɾ��ʧ�ܣ�����null
 */

ElementType * DeleteElement(SeqList * seqList, int index);
 /*
 *  ����˳�����ָ���±��Ԫ��
 *  @param seqList      Ҫ������˳���
 *  @param index        Ҫ����Ԫ�ص��±�
 *  @return             ����Ҫ���ҵ�Ԫ�أ��������ʧ�ܣ�����null
 */
ElementType * GetElement(SeqList * seqList, int index);

 //��ӡ˳��� @param seqList Ҫ��ӡ��˳���
 void PrintList(SeqList * seqList);



#endif // SEQUENCELIST_H_INCLUDED
