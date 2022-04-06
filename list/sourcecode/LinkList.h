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
    linkList->next = linkList;
    return true;
}


/**
 * 后插法
 *
 * @param lNode 要在后插入的节点
 */
bool tailInsert(LNode *lNode, ElemType elem){

    if(lNode == NULL){
        return false;
    }
    //创建插入节点
    LNode * newNode = (LNode *)malloc(sizeof(LNode));
    if(lNode == NULL){
        return false;
    }
    newNode->data = elem;
    newNode->next = lNode->next;
    lNode->next = newNode;

    return true;
}

/**
 * 前插操作
 * 在指定节点前插入数据,采用交换的方式,时间复杂度很低
 *
 * @param lNode
 * @return
 */
bool insertToPriorNode(LNode *lNode, ElemType elem){

    if(lNode == NULL){
        return false;
    }
    //创建插入节点
    LNode * newNode = (LNode *)malloc(sizeof(LNode));
    if(lNode == NULL){
        return false;
    }
    newNode->next = lNode->next;
    lNode->next = newNode;

    newNode->data = lNode->data;
    lNode->data = elem;
    return true;

}


/**
 * 查看链表是否为空
 *
 * @param linkList
 * @return
 */
bool isEmpty(LinkList linkList){
    return linkList->next == linkList;
}


/**
 * 求表长
 *
 * @param linkList
 * @return
 */
int length(LinkList linkList){
    int len = 0;
    LNode * currentNode = linkList;
    while (currentNode->next != linkList){
        currentNode = currentNode->next;
        len ++;
    }
    return len;

}

/**
 * 尾插法创建链表
 *
 * @param linkList
 */
bool createWithTailInsert(LinkList &linkList){

    int elem;
    //初始化链表
    initLinkList(linkList) ;
    //记录最后一个节点
    LNode  *tailNode = linkList;
    //输入元素
    scanf("%d", &elem);
    //9999停止
    while (elem != 9999){
        LNode  * newLNode = (LNode *)malloc(sizeof(LNode));
        newLNode->data = elem;
        newLNode ->next = linkList;
        tailNode ->next = newLNode;
        tailNode = newLNode;
        scanf("%d", &elem);
    }
    return true;

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
        //创建插入节点
        LNode * lNode = (LNode *)malloc(sizeof(LNode));
        lNode->data = elem;
        lNode->next = linkList->next;
        linkList->next = lNode;
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
    while (nextNode != linkList){

        printf("%d, ", nextNode->data);
        nextNode = nextNode->next;
    }
    printf("\n");

}

/**
 * 按值查找
 *
 * @param linkList
 * @param elem
 * @return
 */
LNode * locateElem(LinkList linkList, ElemType elem){

    LNode * currentNode = linkList->next;
    while (currentNode->next != linkList && currentNode->data != elem){
       currentNode = currentNode->next;
    }
    return currentNode;

}

/**
 * 按位查找节点
 * 平均时间复杂度O(n)
 *
 * @param linkList
 * @param i
 * @return
 */
LNode * getNodeByPosition(LinkList linkList, int i){
    if(i < 0){
        return NULL;
    }
    //当前指针位置
    LNode * currentPointer = linkList;
    //当前指针在第几个节点
    int j = 0;
    while (currentPointer->next != linkList && j < i){
        currentPointer = currentPointer->next;
        j ++;
    }
    return currentPointer;
}

/**
 * 按位置插入节点
 * 最好时机复杂度O(1)
 * 最坏时间复杂度O(n)
 * 平均时间复杂度O(n)  --- 1/n(1+n)n/2
 *
 * @param linkList 链表引用
 * @param i 插入位置
 * @param elem 插入元素
 * @return 是否插入成功
 */
bool insertByPosition(LinkList &linkList, int i, ElemType elem){
    LNode * currentPointer = getNodeByPosition(linkList, i-1);
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

/**
 * 按位置删除节点
 *
 * @return
 */
bool deleteNodeByPosition(LinkList &linkList, int i, ElemType &elem){
    //找到第i-1个元素
    LNode * currentPointer = getNodeByPosition(linkList, i-1);
    //没有找到指定位置,i不合法
    if(currentPointer == NULL){
        return false;
    }
    LNode * needDelNode = currentPointer->next;
    elem = needDelNode->data;
    currentPointer->next = needDelNode->next;
    //释放空间
    free(needDelNode);
    return true;
}



/**
 * 删除指定节点,将后面节点的数据挪到当前节点
 * 然后删除后面节点,相当于删除指定节点,时间复杂度为O(1)
 *
 * @param lNode
 * @return
 */
bool deleteNode(LNode *lNode){

    if(lNode == NULL){
        return false;
    }
    LNode * nextNode = lNode->next;
    lNode->data = nextNode->data;
    lNode->next = nextNode->next;
    //如果是最后一个节点有问题
    free(nextNode);
    return true;

}

/**
 * 删除不带头结点的单链表L中所有值为x的节点
 *
 */
void deleteElemByValue(LNode *lNode, ElemType elem){
    if(lNode ==NULL){
        return;
    }
    LNode * p;
    if(lNode->data == elem){

        p = lNode;
        lNode = lNode->next;
        free(p);
        deleteElemByValue(lNode, elem);
    } else{
        deleteElemByValue(lNode->next, elem);
    }

}

void deleteElemByValueWithHead(LinkList &linkList, ElemType elem){

    LNode * currentNode = linkList;
    LNode * nextNode;
    while (currentNode->next != NULL){
        nextNode = currentNode->next;
        if(currentNode->next->data == elem){
            currentNode->next = nextNode->next;
            free(nextNode);
        } else{
            currentNode = currentNode->next;
        }

    }

}


void createWithOrder(){

    int elem;
    LinkList  linkList;
    initLinkList(linkList);

    LNode * currentNOde;
    while (currentNOde->data <= elem){
        LNode * lNode = (LNode *)malloc(sizeof(LNode));
        lNode->data = elem;
        lNode->next = currentNOde->next;
        currentNOde->next = lNode;
        currentNOde = lNode;
    }
}
