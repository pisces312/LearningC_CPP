#include "2d_array_c.h"



void test2DArray1() {
    printf("  �д�С�̶��Ķ�ά�����������һά���ݲ���ָ��ǿת�ɶ�ά����\n");

    //��ֵ�̶�
    const int MAXCOL = 3;

    int nRow;
//    printf("�������ά���������(��ֵ�̶�Ϊ%d): ", MAXCOL);
//    scanf("%d", &nRow);
    nRow=4;

    //����һά���ݲ�����ת�ɶ�ά����ָ��
    int *pp_arr = new int[nRow * MAXCOL];
    int (*p)[MAXCOL] = (int(*)[MAXCOL])pp_arr;

    //Ϊ��ά���鸳ֵ
    int i, j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < MAXCOL; j++)
            p[i][j] = i + j;

    //�����ά����
    for(i = 0; i < nRow; i++) {
        for(j = 0; j < MAXCOL; j++)
            printf("%5d", p[i][j]);
        putchar('\n');
    }

    //�ͷ���Դ
    delete[] pp_arr;
}

void test2DArrayInC() {
    printf("  C�����ж�̬�������ά���� malloc free\n");

//    printf("����������(�Կո�ֿ�): ");
    int nRow=12, nCol=10;
//    scanf("%d %d", &nRow, &nCol);

    //��̬���������Ķ�ά����
    int **p = malloc_Array2D<int>(nRow, nCol);

    //Ϊ��ά���鸳ֵ
    int i, j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < nCol; j++)
            p[i][j] = i + j;

    print2DArray(p,nRow,nCol);
    free_Aarray2D((void**)p);

}

void test2DArrayInCPP() {

    printf("  C++�����ж�̬�������ά���� new delete\n");

//    printf("����������(�Կո�ֿ�): ");
    int nRow=7, nCol=9;
//    scanf("%d %d", &nRow, &nCol);

    //��̬���������Ķ�ά����
    int **p = new_Array2D<int>(nRow, nCol);

    //Ϊ��ά���鸳ֵ
    int i, j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < nCol; j++)
            p[i][j] = i + j;

    //�����ά����
    print2DArray(p,nRow,nCol);

    delete_Array2D<int>(p, nRow, nCol);
}
