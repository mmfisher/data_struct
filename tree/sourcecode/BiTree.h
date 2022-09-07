//
// Created by yu on 2022-4-14.
//

#include <cstdio>
#include <stdlib.h>
#include "..\..\queue\sourcecode\LinkQueue.h"
#include "..\..\stack\sourcecode\LinkStack.h"


#ifndef DATA_STRUCT_BITREE_H
#define DATA_STRUCT_BITREE_H

#endif //DATA_STRUCT_BITREE_H

typedef int ElemType;
typedef int ElemType;


typedef struct BiTNode{
    ElemType data;
    BiTNode * lChild, *rChild;
} BiTNode, *BiTree;


void initBiTree(BiTree &biTree){
    biTree = NULL;
}

//按照先序创建树,0代表空节点
void createBiTree(BiTree &biTree){
    ElemType  elem;
    scanf("%d", &elem);
    if(elem == 0){
        biTree = NULL;
    } else if (elem == 9999){
        return;
    }else{
        biTree = (BiTree )malloc(sizeof(BiTree));
        if(biTree == NULL){
            exit(1);
        }
        biTree->data = elem;
        createBiTree(biTree->lChild);
        createBiTree(biTree->rChild);
    }
}

void visitTNode(BiTNode biTNode){

    printf("%d",biTNode.data);
}

/**
 * 先序遍历
 *
 * @param biTree
 */
void preOrderBiTree(BiTree biTree){
    if(biTree != NULL){
        visitTNode(*biTree);
        preOrderBiTree(biTree->lChild);
        preOrderBiTree(biTree->rChild);
    }
}

/**
 * 中序遍历
 *
 * @param biTree
 */
void inOrderBiTree(BiTree biTree){
    if(biTree != NULL){
        inOrderBiTree(biTree->lChild);
        visitTNode(*biTree);
        inOrderBiTree(biTree->rChild);
    }
}

/**
 * 中序遍历
 *
 * @param biTree
 */
void inOrderNoRecursive(BiTree biTree){
    LinkStack linkStack;
    initStack(linkStack);
    BiTNode * biTNode = biTree;
    while (biTNode != NULL || isEmpty(linkStack)){
//        if(biTNode = NULL){
//            push(linkStack, biTNode);
//            biTNode = biTNode->lChild;
//        } else{
//            pop(linkStack, biTNode);
//            visitTNode(biTNode);
//            biTNode = biTNode->rChild;
//        }
    }
}

/**
 * 后序遍历
 *
 * @param biTree
 */
void postOrderBiTree(BiTree biTree){
    if(biTree != NULL){
        postOrderBiTree(biTree->lChild);
        postOrderBiTree(biTree->rChild);
        visitTNode(*biTree);
    }
}

/**
 * 层次遍历
 *
 */
void levelOrder(BiTree biTree){
    LinkQueue linkQueue;
    initLinkNode(linkQueue);
    BiTNode current;
//    enQueue(linkQueue, biTree);
//
//    while (!isEmpty(linkQueue)){
//        deQueue(linkQueue, current);
//        visitTNode(*biTree);
//        if(current.lChild != NULL){
//            enQueue(linkQueue, current.lChild);
//        }
//        if(!isEmpty(linkQueue)){
//            enQueue(linkQueue, current.rChild);
//        }
//    }

}


