//
// Created by yu on 2022-4-7.
//

#include "LinkQueue.h"
#include <stdio.h>


int main(){
    LinkQueue sqQueue;
    initLinkNode(sqQueue);
    enQueue(sqQueue, 1);
    enQueue(sqQueue, 2);
    enQueue(sqQueue, 3);
    enQueue(sqQueue, 4);
    enQueue(sqQueue, 5);
    ElemType  elemType;
    deQueue(sqQueue, elemType);
    printf("出队: %d\n", elemType);
    deQueue(sqQueue, elemType);
    printf("出队: %d\n", elemType);
    deQueue(sqQueue, elemType);
    printf("出队: %d\n", elemType);
    deQueue(sqQueue, elemType);
    printf("出队: %d\n", elemType);
    deQueue(sqQueue, elemType);
    printf("出队: %d\n", elemType);
    return 0;
}

