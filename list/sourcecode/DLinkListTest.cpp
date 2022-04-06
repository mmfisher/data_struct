//
// Created by yu on 2022-3-31.
//

#include "DLinkList.h"

int main(){

    DLinkList  dLinkList;
    initLinkList(dLinkList);

    printf("尾插法创建链表: \n");
    createWithTailInsert(dLinkList);
    printf("当前链表元素: \n");
    printLinkList(dLinkList);
    return 0;
}

