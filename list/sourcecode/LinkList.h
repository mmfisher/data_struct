//
// Created by yu on 2022-3-30.
//

#ifndef DATA_STRUCT_LINKLIST_H
#define DATA_STRUCT_LINKLIST_H

#endif //DATA_STRUCT_LINKLIST_H


#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;


typedef struct LNode{
    //数据域
    ElemType  data;
    //指针域
    struct LNode * next;
}LNode, *LinkList;

/**
 * 带头结点的初始化
 *
 * @param linkList
 */
bool initLinkList(LinkList &linkList){

    //申请内存
    linkList  = (LNode *)malloc(sizeof(LNode));
    if(linkList == NULL){
        return false;
    }
    linkList->next = NULL;
    return true;
}

/**
 * 头插法
 *
 * @param linkList
 */
void headInsert(LinkList &linkList, ElemType elem){

    //创建插入节点
    LNode * lNode = (LNode *)malloc(sizeof(LNode));
    lNode->data = elem;
    lNode->next = linkList->next;
    linkList->next = lNode;
}

/**
 * 查看链表是否为空
 *
 * @param linkList
 * @return
 */
bool isEmpty(LinkList linkList){
    return linkList->next == NULL;
}

/**
 * 尾插法创建链表
 *
 * @param linkList
 */
void createWithTailInsert(LinkList &linkList){

    int elem;

    LNode * newLNode, *tailNode;
    initLinkList(linkList) ;
    scanf("%d", &elem);

    while (elem != 9999){
        newLNode = (LNode *)malloc(sizeof(LNode));
        newLNode->data = elem;
        newLNode ->next = NULL;
        linkList->next = newLNode;
    }



}

/**
 * 头插法建立链表, 输入9999表示结束
 *
 * @return
 */
LinkList crateWithHeadInsert(LinkList &linkList){

    int elem;
    initLinkList(linkList) ;
    scanf("%d", &elem);
    while (elem != 9999){
        headInsert(linkList, elem);
        scanf("%d", &elem);
    }
}


/**
 * 打印链表节点
 *
 * @param linkList
 */
void printLinkList(LinkList linkList){

    LNode * nextNode = linkList->next;
    while (nextNode != NULL){

        printf("%d\n", nextNode->data);
        nextNode = nextNode->next;
    }

}

/**
 * 按位置插入节点
 *
 * @param linkList 链表引用
 * @param i 插入位置
 * @param elem 插入元素
 * @return 是否插入成功
 */
bool insertByPosition(LinkList &linkList, int i, ElemType elem){
    if(i < 1){
        return false;
    }
    //当前指针位置
    LNode * currentPointer = linkList;
    //当前指针在第几个节点
    int j = 0;
    while (currentPointer != NULL && j < i-1){
        currentPointer = currentPointer->next;
        j ++;
    }
    //没有找到指定位置,i不合法
    if(currentPointer == NULL){
        return false;
    }
   LNode * newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = currentPointer->next;
    currentPointer->next = newNode;
    return true;
}