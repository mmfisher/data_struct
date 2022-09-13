//
// Created by yu on 2022-9-13.
//

#ifndef DATA_STRUCT_SELECTIONSORT_H
#define DATA_STRUCT_SELECTIONSORT_H

#endif //DATA_STRUCT_SELECTIONSORT_H


/**
 * 选择排序
 *
 * @param arr
 * @param n
 */
void selectionSort(int arr[], int n){


    for (int j = 0; j < n - 1; ++j) {
        int temp = j;

        for (int i = j; i < n; ++i) {
            if(arr[i] < arr[temp]){
                temp = i;
            }
        }
        if(temp != j){
            swap(temp, arr[j]);

        }
    }


}