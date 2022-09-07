//
// Created by yu on 2022-5-10.
//
//BV1p34y1Q7Uu

#ifndef DATA_STRUCT_THREADTREE_H
#define DATA_STRUCT_THREADTREE_H

#endif //DATA_STRUCT_THREADTREE_H


typedef struct ThreadNode{
    ElemType data;
    ThreadNode * lChild, *rChild;
    int lTag, rTag;
} ThreadNode, *ThreadTree;

/**
 * 中序线索化
 *
 */
void inTread(ThreadTree &threadTree, ThreadNode pre){

    if(p != NULL){
        inTread(threadTree->lChild, pre);
        visit(threadTree, pre);
        inTread(threadTree->rChild, pre);
    }

}

void visit(ThreadTree &threadTree, ThreadNode pre){

    //左子树为空,指向前驱节点
    if(threadTree->lChild == NULL){
        threadTree->lChild = pre;
        threadTree->lTag = 1;
    }
    //右子树为空,指向后继节点
    if(pre != NULL && pre->rChild == NULL){
        pre.rChild = threadTree;
        pre.rTag = 1;
    }
    pre = threadTree;
}

void creatInThread(ThreadTree threadTree){
    ThreadNode * pre = NULL;

    if(threadTree != NULL){
        inTread(threadTree, pre);
        pre->rChild = NULL;
        pre->rTag = 1;
    }

}

