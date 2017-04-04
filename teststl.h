#ifndef TESTSTL_H_INCLUDED
#define TESTSTL_H_INCLUDED
//迭代器
void testitr1() {
    int size=10;
    int *array=new int[size];
    //数组实现的迭代器
    for (int i=0;i<size;i++) {
        array[i]=i;
    }
    //这里last不表示容器中的任何一个位置
    int *last=array+size;
    //指针实现的输出迭代器
    int *next=array;
    for (;next<last;++next) {
        *next=1;
    }
    //另一种输出迭代器实现
    next=array;
    while (next<last) {
        *next++=1;
    }

//输入迭代器
//类似Fortran语言的Do循环
    int *first=array;
    for (int *p=first;p<last;++p) {
        printf("%d\n",*p);
    }

    for (int *p=first;p!=last;++p) {
        printf("%d\n",*p);
    }


}


#endif // TESTSTL_H_INCLUDED
