//
// Created by yu on 2022-9-8.
//

#ifndef DATA_STRUCT_KMP_H
#define DATA_STRUCT_KMP_H

#endif //DATA_STRUCT_KMP_H

#include <stdlib.h>

#include "HString.h"


/**
 * 朴素模式匹配算法
 *
 * @param s
 * @param t
 * @return
 */
int index(HString s, HString t){
    //s串指针i, t串指针j
    int i = 0,j = 0;
    while (i < s.length && j < t.length){
        if(s.ch[i] == t.ch[j]){
            i ++;
            j ++;
        } else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == t.length){
        return i - t.length;
    }else{
        return 0;
    }
}


/**
 * kmp
 *
 * @param s
 * @param t
 * @return
 */
int kmpIndex(HString s, HString t, int next[]){
    //s串指针i, t串指针j
    int i = 0,j = 0;
    while (i < s.length && j < t.length){
        if(j == -1 || s.ch[i] == t.ch[j]){
            i ++;
            j ++;
        } else{
            j = next[j];
        }
    }
    if(j == t.length){
        return i - t.length;
    }else{
        return 0;
    }
}

/**
 * 最长相等前后缀 +1
 *
 * @param target
 * @param next
 */
void getNext(HString target, int next[]){

    int j = 1, k = 0;
    next[0] = -1;  
    next[1] = 0;

    while (j < target.length){
        if(target.ch[j] == target.ch[k]){
            j ++;
            k ++;
            //p
            next[j] = k ;
        } else if(k == 0){
            next[j+1] = 0;
            j ++;
        }else{
            k = next[k];
        }
    }
}

