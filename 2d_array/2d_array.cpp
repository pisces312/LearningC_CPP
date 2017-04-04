#include "2d_array_c.h"



void test2DArray1() {
    printf("  列大小固定的二维数组可以申请一维数据并将指针强转成二维数组\n");

    //列值固定
    const int MAXCOL = 3;

    int nRow;
//    printf("请输入二维数组的行数(列值固定为%d): ", MAXCOL);
//    scanf("%d", &nRow);
    nRow=4;

    //申请一维数据并将其转成二维数组指针
    int *pp_arr = new int[nRow * MAXCOL];
    int (*p)[MAXCOL] = (int(*)[MAXCOL])pp_arr;

    //为二维数组赋值
    int i, j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < MAXCOL; j++)
            p[i][j] = i + j;

    //输出二维数组
    for(i = 0; i < nRow; i++) {
        for(j = 0; j < MAXCOL; j++)
            printf("%5d", p[i][j]);
        putchar('\n');
    }

    //释放资源
    delete[] pp_arr;
}

void test2DArrayInC() {
    printf("  C语言中动态的申请二维数组 malloc free\n");

//    printf("请输入行列(以空格分开): ");
    int nRow=12, nCol=10;
//    scanf("%d %d", &nRow, &nCol);

    //动态申请连续的二维数组
    int **p = malloc_Array2D<int>(nRow, nCol);

    //为二维数组赋值
    int i, j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < nCol; j++)
            p[i][j] = i + j;

    print2DArray(p,nRow,nCol);
    free_Aarray2D((void**)p);

}

void test2DArrayInCPP() {

    printf("  C++语言中动态的申请二维数组 new delete\n");

//    printf("请输入行列(以空格分开): ");
    int nRow=7, nCol=9;
//    scanf("%d %d", &nRow, &nCol);

    //动态申请连续的二维数组
    int **p = new_Array2D<int>(nRow, nCol);

    //为二维数组赋值
    int i, j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < nCol; j++)
            p[i][j] = i + j;

    //输出二维数组
    print2DArray(p,nRow,nCol);

    delete_Array2D<int>(p, nRow, nCol);
}
