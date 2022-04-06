//
// Created by yu on 2022-3-31.
//

#ifndef DATA_STRUCT_DLINKLIST_H
#define DATA_STRUCT_DLINKLIST_H

#endif //DATA_STRUCT_DLINKLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"

typedef int ElemType;


typedef struct DNode{
    ElemType  data;
    struct DNode * next, *prior;
}DNode, *DLinkList;


/**
 * 带头结点的初始化,
 * 改为循环链表
 *
 * @param linkList
 */
bool initLinkList(DLinkList &dLinkList){

    //申请内存
    dLinkList  = (DNode *)malloc(sizeof(DNode));
    if(dLinkList == NULL){
        return false;
    }
    dLinkList->next = dLinkList;
    dLinkList->prior = dLinkList;
    return true;
}

/**
 * 在p后插入节点
 *
 * @param priorNode 在该节点后插入
 * @param insertDNode 要插入的节点
 * @return 是否插入成功
 */
bool insertNextDNode(DNode *priorNode, DNode *insertDNode){
    if(priorNode == NULL || insertDNode == NULL){
        return false;
    }
    //插入节点后记指向p的后继
    insertDNode->next = priorNode->next;
    //p的后继不为空
    //这里是非循环链表写法
//    if(priorNode->next != NULL){
//        //p的后继的前驱指向插入节点
//        priorNode->next->prior = insertDNode;
//    }
    //循环链表不用判断,必不为空
    priorNode->next->prior = insertDNode;
    //插入节点的前驱指向p
    insertDNode->prior = priorNode;
    //p的后继指向插入节点
    priorNode->next = insertDNode;
    return true;
}


/**
 * 尾插法创建循环双链表
 *
 * @return
 */
bool createWithTailInsert(DLinkList &dLinkList){
    int elem;
    DNode * tail = dLinkList;
    //输入元素
    scanf("%d", &elem);
    while (elem != 9999){
        DNode * insertNode = (DNode *)malloc(sizeof(DNode));
        insertNode->data = elem;
        insertNode->next = NULL;
        insertNode->prior = NULL;
        insertNextDNode(tail, insertNode);
        tail= insertNode;
        scanf("%d", &elem);
    }
    return true;
}
/**
 * 删除后继节点
 *
 * @param dNode
 * @return
 */
bool deleteNextNode(DNode * dNode){
    if(dNode == NULL){
        return false;
    }

    DNode * needDeleteNode = dNode->next;
    //没有后继节点
    //改为不能是头结点
    if(needDeleteNode->data == NULL){
        return false;
    }

    dNode->next = needDeleteNode->next;
    //改为循环链表不需要判断是否为空
   /* if(needDeleteNode->next != NULL){
        needDeleteNode->next->prior = dNode;
    }*/
    needDeleteNode->next->prior = dNode;
    free(needDeleteNode);
    return true;
}
/**
 * 销毁双链表
 *
 * @param dLinkList
 */
void distoryList(DLinkList &dLinkList){

    while (dLinkList->next != dLinkList){
        deleteNextNode(dLinkList);
    }
    free(dLinkList);
    dLinkList = NULL;
}


/**
 * 打印链表节点
 *
 * @param linkList
 */
void printLinkList(DLinkList dLinkList){

    DNode * nextNode = dLinkList->next;
    while (nextNode != dLinkList){

        printf("%d, ", nextNode->data);
        nextNode = nextNode->next;
    }
    printf("\n");

}