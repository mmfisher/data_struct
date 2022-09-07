//
// Created by yu on 2022-4-6.
//

#ifndef DATA_STRUCT_LINKQUEUE_H
#define DATA_STRUCT_LINKQUEUE_H

#endif //DATA_STRUCT_LINKQUEUE_H

#include <stdlib.h>

typedef int ElemType;

/**
 * 不带头结点版本
 *
 */
typedef struct LNode{
    ElemType data;
    struct LNode * next;
}QueuePtr;

typedef struct{
    QueuePtr *front, *rear;
}LinkQueue;

/**
 * 初始化
 *
 * @param linkQueue
 * @return
 */
bool initLinkNode(LinkQueue &linkQueue){
    linkQueue.front = NULL;
    linkQueue.rear = NULL;
}

/**
 * 入队
 *
 * @param linkQueue
 * @param data
 * @return
 */
bool enQueue(LinkQueue &linkQueue, ElemType data){
    QueuePtr * node = (QueuePtr *)malloc(sizeof(QueuePtr));
    node->data = data;
    node->next = NULL;

    //空队
    if(linkQueue.front == NULL){
        linkQueue.front = node;
        linkQueue.rear = node;
    } else{
        linkQueue.rear->next = node;
        linkQueue.rear = node;
    }
    return true;
}

/**
 * 出队
 *
 * @param linkQueue
 * @param data
 * @return
 */
bool deQueue(LinkQueue &linkQueue, ElemType &data){

    if(linkQueue.front == NULL){
        return false;
    }
    QueuePtr * ptr = linkQueue.front;
    data = ptr->data;
    linkQueue.front = ptr->next;
    if(linkQueue.rear == ptr){
        linkQueue.rear = NULL;
        linkQueue.front = NULL;
    }
    free(ptr);
    return true;
}


bool isEmpty(LinkQueue linkQueue){
    return linkQueue.front == NULL;
}
