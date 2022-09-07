//
// Created by yu on 2022-4-7.
//
//栈的应用,检查左右括号是否匹配

#include "LinkStack.h"
#include <stdio.h>


bool bracketCheck(char str[6], int i);

int main(){

    char str[] = {'(', ')', '{', '[', ']', '}', '(',')'};

    bool result = bracketCheck(str, 8);
    printf("是否匹配: %s", result?"YES":"NO");
    return 0;
}

bool bracketCheck(char str[6], int length) {
    //初始化链栈
    LinkStack linkStack;
    initStack(linkStack);

    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str [i] == '[' || str[i] == '{'){
            push(linkStack, str[i]);
        } else{
            //空栈
            if(isEmpty(linkStack)){
                return false;
            } else{
                ElemType  right;
                pop(linkStack, right);
                if(str[i] == ')' && right != '('){
                    return false;
                } else if(str[i] == ']' && right != '['){
                    return false;
                } else if(str[i] == '}' && right != '{'){
                    return false;
                }
            }
        }
    }

    if(isEmpty(linkStack)){
        return true;
    } else{
        return false;
    }
}
