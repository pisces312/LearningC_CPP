#ifndef TWO_D_ARRAY_C_H_INCLUDED
#define TWO_D_ARRAY_C_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��̬�����ά����
template <typename T>
T** malloc_Array2D(int row, int col) {
    int size = sizeof(T);
    int point_size = sizeof(T*);
    //�������ڴ棬����point_size * row��ʾ���row����ָ��
    T **arr = (T **) malloc(point_size * row + size * row * col);
    if(arr != NULL) {
        memset(arr, 0, point_size * row + size * row * col);
        T *head = (T*)((int)arr + point_size * row);
        while(row--)
            arr[row] = (T*)((int)head + row * col * size);
    }
    return (T**)arr;
}
//�ͷŶ�ά����
void free_Aarray2D(void **arr) {
    if(arr != NULL)
        free(arr);
}

///////////////////////////////////////////
#include <new>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
//��̬�����ά����
template <typename T>
T** new_Array2D(int row, int col) {
    int size = sizeof(T);
    int point_size = sizeof(T*);
    //�������ڴ棬����sizeof(T*) * row��ʾ���row����ָ��
    T **arr = (T **) malloc(point_size * row + size * row * col);
    if(arr != NULL) {
        T *head = (T*)((int)arr + point_size * row);
        for(int i = 0; i < row; ++i) {
            arr[i] = (T*)((int)head + i * col * size);
            for(int j = 0; j < col; ++j)
                new(&arr[i][j]) T;
        }
    }
    return (T**)arr;
}
//�ͷŶ�ά����
template <typename T>
void delete_Array2D(T **arr, int row, int col) {
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            arr[i][j].~T();
    if(arr != NULL)
        free((void**)arr);
}

///////////////////////////////////////////



void print2DArray(int **p,int nRow,int nCol) {
    for(int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++)
            printf("%4d ", p[i][j]);
        putchar('\n');
    }
}
#endif // TWO_D_ARRAY_C_H_INCLUDED
