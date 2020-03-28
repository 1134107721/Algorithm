#include "SeqQueue.h"
#include <stdlib.h>
// 初始化
void InitSeqQueue(SeqQueqe * seqQueue){
    //如果队列不存在，那么就创建一个队列（开辟一个内存）
    if(seqQueue == NULL){
        seqQueue = (SeqQueqe *)malloc(sizeof(SeqQueqe));
    }
    seqQueue->length = 0;
    seqQueue->front = 0;
    seqQueue->rear = 0;
}

//判断队列是否为空
//以TRUE / FALSE的方式返回传入的队列是否为空
State IsSeqQueueEmpty(SeqQueqe * seqQueue){
    //对头指针如果等于队尾指针，那么队列为空
    if(seqQueue->front == seqQueue->rear){
        return STATE_OK;
    }
    else
        return STATE_FAILED;
}
//判断队列是否为满
State IsSeqQueueFull(SeqQueqe * seqQueue){
    if( (seqQueue->rear+1) % MAX_SIZE == seqQueue->front){
        return  STATE_OK;
    }
    else
        return  STATE_FAILED;
}

//入队
State OfferSeqQueue(SeqQueqe * seq, ElementType ele){
    if(IsSeqQueueFull(seq)){
        return STATE_FAILED;
    }
    seq->data[seq->rear] = ele;
    //rear指针向后移动一位
    seq->rear = (seq->rear + 1) % MAX_SIZE;
    seq->length++;
    return STATE_OK;
}

//出队  传进去指针类型的ele是为了用指针记录（返回）被抛出的元素
State PollSeqQueue(SeqQueqe * seq, ElementType * ele){
    if(IsSeqQueueEmpty(seq))
        return STATE_FAILED;
    //取出队头元素  (下一行的ele用不用加星号？？？)
    *ele = seq->data[seq->front];
    //front指针向后移动一位
    seq->front = (seq->front + 1) % MAX_SIZE;
    seq->length--;
    return STATE_OK;
}









