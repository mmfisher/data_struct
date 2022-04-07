//
// Created by yu on 2022-4-6.
//

#ifndef DATA_STRUCT_SQQUEUE_H
#define DATA_STRUCT_SQQUEUE_H

#endif //DATA_STRUCT_SQQUEUE_H
#define MAX_SIZE 10

typedef int ElemType;

typedef struct {
    ElemType data[MAX_SIZE];
    int front, rear;
} SqQueue;

void initQueue(SqQueue &sqQueue){
    sqQueue.front = 0;
    sqQueue.rear = 0;
};

/**
 * 入队
 *
 * @param sqQueue
 * @param elemType
 * @return
 */
bool enQueue(SqQueue &sqQueue, ElemType elemType){
    //队列已满
    //判断队尾的下一个元素是否为队头,空出一个元素用于判断
    if((sqQueue.rear + 1) % MAX_SIZE == sqQueue.front){
        return false;
    }
    sqQueue.data[sqQueue.rear ] = elemType;
    //循环列队
    sqQueue.rear = (sqQueue.rear + 1) % MAX_SIZE;
    return true;

}

/**
 * 出队
 *
 * @param sqQueue
 * @param elemType
 * @return
 */
bool deQueue(SqQueue &sqQueue, ElemType &elemType){

    //判断是否为对空
    if(sqQueue.front == sqQueue.rear){
        return false;
    }

    elemType = sqQueue.data[sqQueue.front];
    //头指针后移
    sqQueue.front = (sqQueue.front + 1) % MAX_SIZE;
    return true;
}


/**
 * 出队
 *
 * @param sqQueue
 * @param elemType
 * @return
 */
bool getElem(SqQueue &sqQueue, ElemType &elemType){

    //判断是否为对空
    if(sqQueue.front == sqQueue.rear){
        return false;
    }
    elemType = sqQueue.data[sqQueue.front];
    return true;
}

/**
 * 列队长度
 *
 * @param sqQueue
 * @return
 */
int length(SqQueue sqQueue){
    return (sqQueue.rear + MAX_SIZE - sqQueue.front) % MAX_SIZE;
}

