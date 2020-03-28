//顺序队列Demo
#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

#include "DataElement.h"

#define STATE_OK 1;
#define STATE_FAILED 0;


typedef int State;  //给整型起一个别名，专门用来表示状态
/* 循环队列结构 */
typedef struct{
    ElementType data[MAX_SIZE];
    int front;          //队头指针
    int rear;           //队尾指针
    int length;         //队列长度

}SeqQueqe;
//初始化
void InitSeqQueue(SeqQueqe * seqQueue);

//判断队列是否为空
//以TRUE / FALSE的方式返回传入的队列是否为空
State IsSeqQueueEmpty(SeqQueqe * seqQueue);

//判断队列是否为满
State IsSeqQueueFull(SeqQueqe * seqQueue);

//入队
State OfferSeqQueue(SeqQueqe * seq, ElementType ele);

//出队  传进去指针类型的ele是为了用指针记录（返回）被抛出的元素
State PollSeqQueue(SeqQueqe * seq, ElementType * ele);
#endif // SEQQUEUE_H_INCLUDED
