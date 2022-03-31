//
// Created by yu on 2022-3-30.
//

#include "LinkList.h"


int main() {

    LinkList linkList;
    //头插建立链表
     //crateWithHeadInsert(linkList);
    //尾插法建立链表
    printf("尾插法创建链表: \n");
    createWithTailInsert(linkList);
    printf("当前链表元素: \n");
    printLinkList(linkList);
//    LNode * lNode1 = locateElem(linkList , 3);
   // printf("第三个位置的node是: %d\n", lNode1->data);


    LNode * lNode2 = getNodeByPosition(linkList, 4);
    printf("第4个位置的node是: %d\n", lNode2->data);
    //插入
    printf("第3个位置插入10, \n");
    insertByPosition(linkList , 3, 10);
    printf("当前链表元素: \n");
    lNode2 = getNodeByPosition(linkList , 4);
    printf("修改后第4个位置的node是: %d\n", lNode2->data);
    printLinkList(linkList);

    printf("删除第4个节点: \n");
    deleteNode(lNode2);
    printf("当前链表元素: \n");
    printLinkList(linkList);

    ElemType  elemType;
    deleteNodeByPosition(linkList, 10, elemType);
    printf("删除第10个位置节点为 %d: \n", elemType);
    printf("当前元素个数 %d: \n", length(linkList));

}
