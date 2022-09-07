//
// Created by yu on 2022-4-7.
//

//中缀转后缀
#include "LinkStack.h"
#include <stdio.h>

//todo
void process(char *midExpression, char * postExpression){

    //初始化栈
    LinkStack  linkStack;
    initStack(linkStack);
    //读取中缀表达式
    int *pInt = midExpression;
    char postChar[];
    int postLocal = 0, midLocal = 0;
    char midChar = midExpression[midLocal];
    while (true){
        //取字符
        //判断是操作数,还是操作符
        if(midChar != '+' && midChar != '-'
            && midChar != '*' && midChar != '/'
            && midChar != '('  && midChar != ')'){
            //操作数
            postChar[postLocal ++] = midChar;
            midChar = midExpression[++ midLocal];
        } else{
            //操作符
            //压栈
            //压栈前判断栈顶操作符的优先级是否高于当前操作符
            char topOpera;
            getTop(linkStack, topOpera);
            //括号
            if(){

            }else if(comparePriority(topOpera, midChar)){
                push(linkStack, midChar);
            } else {
                //弹栈
                pop(linkStack, topOpera);
                postChar[postLocal ++] = topOpera;
            }
        }
    }
}