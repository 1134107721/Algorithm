#include "SeqQueue.h"
#include <stdlib.h>
// ��ʼ��
void InitSeqQueue(SeqQueqe * seqQueue){
    //������в����ڣ���ô�ʹ���һ�����У�����һ���ڴ棩
    if(seqQueue == NULL){
        seqQueue = (SeqQueqe *)malloc(sizeof(SeqQueqe));
    }
    seqQueue->length = 0;
    seqQueue->front = 0;
    seqQueue->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
//��TRUE / FALSE�ķ�ʽ���ش���Ķ����Ƿ�Ϊ��
State IsSeqQueueEmpty(SeqQueqe * seqQueue){
    //��ͷָ��������ڶ�βָ�룬��ô����Ϊ��
    if(seqQueue->front == seqQueue->rear){
        return STATE_OK;
    }
    else
        return STATE_FAILED;
}
//�ж϶����Ƿ�Ϊ��
State IsSeqQueueFull(SeqQueqe * seqQueue){
    if( (seqQueue->rear+1) % MAX_SIZE == seqQueue->front){
        return  STATE_OK;
    }
    else
        return  STATE_FAILED;
}

//���
State OfferSeqQueue(SeqQueqe * seq, ElementType ele){
    if(IsSeqQueueFull(seq)){
        return STATE_FAILED;
    }
    seq->data[seq->rear] = ele;
    //rearָ������ƶ�һλ
    seq->rear = (seq->rear + 1) % MAX_SIZE;
    seq->length++;
    return STATE_OK;
}

//����  ����ȥָ�����͵�ele��Ϊ����ָ���¼�����أ����׳���Ԫ��
State PollSeqQueue(SeqQueqe * seq, ElementType * ele){
    if(IsSeqQueueEmpty(seq))
        return STATE_FAILED;
    //ȡ����ͷԪ��  (��һ�е�ele�ò��ü��Ǻţ�����)
    *ele = seq->data[seq->front];
    //frontָ������ƶ�һλ
    seq->front = (seq->front + 1) % MAX_SIZE;
    seq->length--;
    return STATE_OK;
}









