#ifndef FILE1_H_INCLUDED
#define FILE1_H_INCLUDED
#include "file2.h"
//static int same_int_name=0;
extern int file2_int_var;
//���Բ���дԪ�ظ���
extern double file2_double_array[];
/**
����������
**/
void testExternVarScope(){
    printf("%d\n",file2_int_var);
}

#endif // FILE1_H_INCLUDED
