//
// Created by yu on 2022-9-8.
//

#ifndef DATA_STRUCT_STRING_H
#define DATA_STRUCT_STRING_H

#endif //DATA_STRUCT_STRING_H
#include <stdlib.h>

/**
 * 对分配字符串
 */
typedef struct {
    char *ch;
    int length;
}HString;


/**
 * 初始化
 *
 * @param string
 * @param chars
 * @return
 */
bool assignString(HString &string, char *chars ){

    int i ;
    char *c;
    //计算chars长度
    for ( i = 0, c= chars; *c; i++, c++);

    if(i == 0){
        //string 为空串
        string.ch = NULL;
        string.length = 0;
    } else{
        string.ch = (char *)malloc(i * sizeof(char));
        if(string.ch == NULL){
            return false;
        }

        for (int j = 0; j < i; ++j) {
            string.ch[j] = chars[j];
            string.length = i;
        }
    }

}


bool subString(HString source, HString &target, int pos, int len){
    if(pos < 0 || pos > source.length -1 || len < 0 || len > source.length - pos ){
        return false;
    }
    if (target.ch != NULL){
        //释放元空间
        free(target.ch);
    }
    if(len == 0){
        target.ch = NULL;
        target.length = 0;
    } else{
        target.ch = (char *)malloc(len * sizeof(char));
        if(target.ch == NULL){
            return false;
        }

        for (int j = 0; j < len; ++j) {

            target.ch[j] = source.ch[pos + j];
        }
        target.length = len;
    }

}