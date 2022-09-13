//
// Created by yu on 2022-9-13.
//

#ifndef DATA_STRUCT_BUBBLESORT_H
#define DATA_STRUCT_BUBBLESORT_H

#endif //DATA_STRUCT_BUBBLESORT_H


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 冒泡排序
 *
 * @param array
 * @param n
 */
void sort(int array[], int n){

    for (int j = 0; j < n-1; ++j) {
        bool isSwap = false;

        for (int i = n-1; i > j; i--) {
            if(array[i] <array[i-1]){
                swap(array[i], array[i-1]);
                isSwap = true;
            }
        }

        if(!isSwap){
            return;
        }
    }

}

