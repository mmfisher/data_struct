//
// Created by yu on 2022-4-6.
//

#ifndef DATA_STRUCT_SQSTACK_H
#define DATA_STRUCT_SQSTACK_H

#endif //DATA_STRUCT_SQSTACK_H
#define MAX_SIZE 10

typedef int ElemType;
/**
 * 顺序栈
 *
 */
typedef struct {
    ElemType data[MAX_SIZE];
    int top;
}SqStack;

/**
 * 初始化
 *
 * @param sqStack
 */
void initStack(SqStack &sqStack){
    sqStack.top = -1;
}

/**
 * 是否为空
 *
 * @param sqStack
 * @return
 */
bool isEmpty(SqStack sqStack){
    return -1 == sqStack.top;
};

/**
 * 入栈
 *
 * @param sqStack
 * @param elemType
 * @return
 */
bool push(SqStack &sqStack, ElemType elemType){
    if(sqStack.top == MAX_SIZE -1){
        return false;
    }

    sqStack.data[++sqStack.top] = elemType;
    return true;
}

/**
 * 出栈
 *
 * @param sqStack
 * @param elemType
 * @return
 */
bool pop(SqStack &sqStack, ElemType &elemType){
    if(sqStack.top == -1){
        return false;
    }
    elemType = sqStack.data[sqStack.top--];
    return true;
}

/**
 * 读栈顶元素
 *
 * @param sqStack
 * @param elemType
 * @return
 */
bool getTop(SqStack &sqStack, ElemType &elemType){
    if(sqStack.top == -1){
        return false;
    }
    elemType = sqStack.data[sqStack.top];
    return true;
}