//
// Created by yu on 2022-9-8.
//

#include "KMP.h"
#include <stdio.h>


/**
 * 打印
 *
 * @param sqlist
 */
void printList(int next[]){

    for (int i = 0; i < 10; ++i) {
        printf("%d ", next[i]);
    }
    printf("\n");
}

int main(){

    HString hString;
    HString tar;

    assignString(hString, "abcabcabbbbbbb");
    assignString(tar, "abaabcaba");

//    printf("%d", index(hString, tar));

    int next[10];
    getNext(tar, next);
    printList(next);
//    printf("kmp:  %d", kmpIndex(hString, tar, next));


}



