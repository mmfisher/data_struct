//
// Created by yu on 2022-6-20.
//

#ifndef DATA_STRUCT_INSERTSORT_H
#define DATA_STRUCT_INSERTSORT_H

#endif //DATA_STRUCT_INSERTSORT_H
#include <stdio.h>


typedef int ElemType;

/**
 * 带哨兵的插排
 *
 * @param elem
 * @param n
 */
void insertSort(ElemType elem[], int n){

    int i, j;
    for (i = 2; i < n; ++i) {
        //哨兵存放要插入的数据
        elem[0] = elem[i];
        //对比已经插好的数组
        int j ;
        for (j = i-1; elem[0] < elem[j]; --j){
            elem[j + 1] = elem[j];
        }
        elem[j + 1] = elem[0];
    }

}