//˳�����Demo
#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

#include "DataElement.h"

#define STATE_OK 1;
#define STATE_FAILED 0;


typedef int State;  //��������һ��������ר��������ʾ״̬
/* ѭ�����нṹ */
typedef struct{
    ElementType data[MAX_SIZE];
    int front;          //��ͷָ��
    int rear;           //��βָ��
    int length;         //���г���

}SeqQueqe;
//��ʼ��
void InitSeqQueue(SeqQueqe * seqQueue);

//�ж϶����Ƿ�Ϊ��
//��TRUE / FALSE�ķ�ʽ���ش���Ķ����Ƿ�Ϊ��
State IsSeqQueueEmpty(SeqQueqe * seqQueue);

//�ж϶����Ƿ�Ϊ��
State IsSeqQueueFull(SeqQueqe * seqQueue);

//���
State OfferSeqQueue(SeqQueqe * seq, ElementType ele);

//����  ����ȥָ�����͵�ele��Ϊ����ָ���¼�����أ����׳���Ԫ��
State PollSeqQueue(SeqQueqe * seq, ElementType * ele);
#endif // SEQQUEUE_H_INCLUDED
