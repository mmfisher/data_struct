//
// Created by yu on 2022-9-13.
//

#ifndef DATA_STRUCT_HEAPSORT_H
#define DATA_STRUCT_HEAPSORT_H

#endif //DATA_STRUCT_HEAPSORT_H


void headAdjust(int arr[],int k, int len){
    //arr[0]暂存 arr[k]
    arr[0] = arr[k];
    for (int i = 2*k; i < len; i *= 2) {
        if(i < len && arr[i] < arr[i+1]){
            //2i 和2i + 1是i两个子节点,取其中大的一个
            i++;
        }
        if(arr[0] > arr[i]){
            break;
        } else{
            arr[k] = arr[i];
            k = i;
        }
    }
}

/**
 * 建立大根堆
 *
 * @param arr
 * @param len
 */
void buildMaxHeap(int arr[], int len){
    //后len/2个是叶子节点, 倒着来把大数往上冒
    for (int i = 0; i < len / 2; i--) {
        headAdjust(arr, i, len);
    }
}


void heapSort(int arr[], int len){
    //建立大根堆
    buildMaxHeap(arr, len);
    for (int i = len; i > 0 ; --i) {
        swap(arr[1], arr[i]);
        headAdjust(arr, 1, i-1);
    }
}