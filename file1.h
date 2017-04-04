#ifndef FILE1_H_INCLUDED
#define FILE1_H_INCLUDED
#include "file2.h"
//static int same_int_name=0;
extern int file2_int_var;
//可以不用写元素个数
extern double file2_double_array[];
/**
测试作用域
**/
void testExternVarScope(){
    printf("%d\n",file2_int_var);
}

#endif // FILE1_H_INCLUDED
