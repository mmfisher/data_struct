//
// Created by yu on 2022-3-28.
//

#ifndef DATA_STRUCT_SQLIST_H
#define DATA_STRUCT_SQLIST_H

#endif //DATA_STRUCT_SQLIST_H

#define INIT_SIZE   100;
#define LIST_INCREMENT 10;

#include <stdlib.h>

typedef int ElemType;

typedef struct {
    ElemType  *data;
    int maxSize, length;
} Sqlist;

bool initList(Sqlist &sqlist){
    //分配存储空间
    sqlist.data =  (ElemType* )malloc(sizeof(ElemType)*INIT_SIZE);

    //分配失败
    if(!sqlist.data){
        exit(1);
    }
    sqlist.length = 0;
    sqlist.maxSize = INIT_SIZE;
}

/**
 * 插入元素
 *
 * @param sqlist 顺序表引用
 * @param i 位置
 * @param elemType  插入元素
 * @return 是否成功
 */
bool insertData(Sqlist &sqlist, int i, ElemType elemType){
    //判断i是否有效
    if(i<1 || i > sqlist.length +1){
        return false;
    }
    //判断存储空间是否已满
    if(sqlist.length >= INIT_SIZE){
        return false;
    }
    //将第i个元素及后面的后移
    for (int j = sqlist.length; j >= i; j--) {

        sqlist.data[j] = sqlist.data[j-1];
    }
    //存储数据
    sqlist.data[i-1] = elemType;
    //长度加一
    sqlist.length ++;
    return true;
}

/**
 * 删除元素
 *
 * @param sqlist 顺序表引用
 * @param i 删除位置
 * @param elemType 删除元素引用
 * @return
 */
bool deleteElem(Sqlist &sqlist, int i, ElemType &elemType){
    //判断i是否有效
    if(i<1 || i > sqlist.length){
        return false;
    }
    //返回移除的元素
    elemType = sqlist.data[j-1];
    //从i位开始前移
    for (int j = i; j < sqlist.length; ++j) {
        sqlist.data[j-1] = sqlist.data[j];
    }
    //长度减一
    sqlist.length --;
    return true;
}

/**
 * 按值查找
 *
 * @param sqlist 查找顺序表
 * @param elemType 查找元素
 * @return 元素位置,没找到返回0
 */
int locateElem(Sqlist &sqlist, ElemType elemType){

    for (int i = 0; i < sqlist.length; ++i) {
        if(sqlist.data[i] == elemType){
            return i + 1;
        }
    }
    return 0;
}


