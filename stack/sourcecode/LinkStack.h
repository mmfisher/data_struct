//
// Created by yu on 2022-4-6.
//

#ifndef DATA_STRUCT_LINKSTACK_H
#define DATA_STRUCT_LINKSTACK_H

#endif //DATA_STRUCT_LINKSTACK_H
#include <stdlib.h>

typedef int ElemType;
//typedef char ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode * next;
} LinkNode, *LinkStack;

/**
 * 初始化
 *
 * @param linkStack
 */
void initStack(LinkStack &linkStack){

    linkStack = NULL;
}

/**
 * 压栈
 *
 * @param linkStack
 * @param elemType
 * @return
 */
bool push(LinkStack &linkStack, ElemType elemType){

    LinkNode * linkNode = (LinkNode *)malloc(sizeof(LinkNode));
    if(linkNode == NULL){
        return false;
    }
    linkNode->data = elemType;
    linkNode->next = linkStack;
    linkStack = linkNode;
    return true;
}

/**
 * 出栈
 *
 * @param linkStack
 * @param elemType
 * @return
 */
bool pop(LinkStack &linkStack, ElemType &elemType){
    if(linkStack == NULL){
        return false;
    }
    LinkNode * linkNode = linkStack;
    elemType = linkStack->data;
    linkStack = linkStack->next;
    free(linkNode);
    return true;
}

/**
 * 判断是否为空
 *
 * @param linkStack
 * @return
 */
bool isEmpty(LinkStack linkStack){
    return linkStack == NULL;
}


/**
 * 读栈顶元素
 *
 * @param sqStack
 * @param elemType
 * @return
 */
bool getTop(LinkStack &linkStack, ElemType &elemType){
    if(linkStack == NULL){
        return false;
    }
    elemType = linkStack->data;
    return true;
}