//
// Created by yu on 2022-6-15.
//

#include "QuickSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include <stdio.h>

int  main(){

    int elem[] = {8,6,7,9,10,23,11,4,56,15,29,30};
    quickSort(elem, 0, 12);
    printf("quick sort :\n");
    for (int i = 0; i < 12; ++i) {
        printf("%d, ", elem[i]);
    }
    printf("\n");

    int elem1[] = {0,8,6,7,9,10,23,11,4,56,15,29,30};
    insertSort(elem1, 13);
    printf("insert sort :\n");
    for (int i = 1; i < 13; ++i) {
        printf("%d, ", elem1[i]);
    }

}
