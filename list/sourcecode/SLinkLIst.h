//
// Created by yu on 2022-4-1.
//
#ifndef DATA_STRUCT_SLINKLIST_H
#define DATA_STRUCT_SLINKLIST_H

#endif //DATA_STRUCT_SLINKLIST_H


#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 10

typedef int ElemType;

/**
 * 静态链表
 * 优点:增删不需要大量移动元素
 * 缺点:不能随机存取,只能从头节点后依次查找
 * 文件分配系统FAT
 */
typedef struct{
    ElemType  elemType;
    int next;
} SLinkList[MAX_SIZE];

void initSLinkList(SLinkList &sLinkList){
    //将游标设置为2,代表节点为空
    for (int i = 0; i < MAX_SIZE; ++i) {
        sLinkList[i].next = -2;
    }
    //用-1代表尾节点
    sLinkList[0].elemType = NULL;
    sLinkList[0].next = -1;
}

bool insertNode(){

}