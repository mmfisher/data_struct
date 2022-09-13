//
// Created by yu on 2022-9-9.
//

#include <stdlib.h>

#ifndef DATA_STRUCT_TSMATRIX_H
#define DATA_STRUCT_TSMATRIX_H

#endif //DATA_STRUCT_TSMATRIX_H

#define MAX_SIZE 100
typedef int ElemType;


typedef struct {
    int row;
    int col;
    ElemType data;
}Triple;

typedef struct {
    int rows;
    int cols;
    int nozero;
    Triple data[MAX_SIZE];
}TSMatrix;


bool createTSMatrix(TSMatrix &matrix, int mat[5][5]){

    int nozero = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            if(mat[i][j] != 0){
                nozero ++;
                Triple * triple = (Triple *)malloc(sizeof(Triple));
                if(triple == NULL){
                    return false;
                }
                triple->row = i;
                triple->col = j;
                triple->data = mat[i][j];

                matrix.data[nozero] = *triple;
            }
        }
    }
}