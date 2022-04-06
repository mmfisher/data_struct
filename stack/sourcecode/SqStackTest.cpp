//
// Created by yu on 2022-4-6.
//

#include "SqStack.h"
#include <stdio.h>

int main(){
    SqStack sqStack;

    initStack(sqStack);

    push(sqStack, 1);
    push(sqStack, 2);
    push(sqStack, 3);
    push(sqStack, 4);
    push(sqStack, 5);

    ElemType  elemType;
    pop(sqStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(sqStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(sqStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(sqStack, elemType);
    printf("出栈: %d\n", elemType);
    pop(sqStack, elemType);
    printf("出栈: %d\n", elemType);


}
