//
// Created by yu on 2022-4-6.
//

#include "LinkStack.h"
#include <stdio.h>

int main(){
    LinkStack linkStack;
    initStack(linkStack);

    push(linkStack, 1);
    push(linkStack, 2);
    push(linkStack, 3);
    push(linkStack, 4);
    push(linkStack, 5);

    ElemType  elemType;
    pop(linkStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(linkStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(linkStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(linkStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(linkStack, elemType);
    printf("出栈: %d\n", elemType);

}
