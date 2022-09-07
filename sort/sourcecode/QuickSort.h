//
// Created by yu on 2022-6-15.
//

#ifndef DATA_STRUCT_QUICKSORT_H
#define DATA_STRUCT_QUICKSORT_H

#endif //DATA_STRUCT_QUICKSORT_H

typedef int ElemType;

int partition(ElemType elem[], int low, int high){
    int pivot = elem[low];
    while (low < high){
        while (low < high && elem[high] >= pivot){
            high --;
        }
        elem[low] = elem[high];

        while (low < high && elem[low] <= pivot){
            low ++;
        }
        elem[high] = elem[low];
    }
    elem[low] = pivot;
    return low;
}

void quickSort(ElemType elem[], int low, int high){
    if(low < high){
        int pivotpos = partition(elem, low, high);
        quickSort(elem, low, pivotpos -1);
        quickSort(elem, pivotpos +1, high);
    }
}

