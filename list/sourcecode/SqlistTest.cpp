//
// Created by yu on 2022-3-29.
//

typedef int ElemType;    // 顺序表中元素类型为int
# include "stdio.h"
# include "stdlib.h"     // 该文件包含malloc()、realloc()和free()等函数
//# include "iomanip.h"    // 该文件包含标准输入输出流cout和cin及控制符setw()等函数
# include "SqList.h"     // 该文件中包含链表数据对象的描述及相关操作

int main(){
    Sqlist sqList;

    initList(sqList);
    insertData(sqList, 1, 1);
    insertData(sqList, 2, 2);
    insertData(sqList, 3, 3);
    insertData(sqList, 4, 4);
    insertData(sqList, 5, 5);
    insertData(sqList, 6, 6);
    insertData(sqList, 7, 7);
    insertData(sqList, 8, 8);
    insertData(sqList, 9, 9);
    insertData(sqList, 10, 10);
    printList(sqList);
    converse(sqList, 10, 5);
    printList(sqList);
    return 0;
}