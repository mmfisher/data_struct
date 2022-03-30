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
    insertData(sqList, 1, 10);
    insertData(sqList, 2, 11);
    insertData(sqList, 3, 12);
    insertData(sqList, 4, 13);
    printList(sqList);
    return 0;
}