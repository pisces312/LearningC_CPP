#ifndef POINTANDARRAY_H_INCLUDED
#define POINTANDARRAY_H_INCLUDED
#include <string.h>
#include <stdlib.h>
namespace Sort {
    /*
    未知类型的快速排序
    qsort:  sort v[left]...v[right] into increasing order */
    void quickSort(void *v[], int left, int right,
                   int (*comp)(const void *, const void *)) {
        int i, last;

        void swap(void *v[], int, int);

        if (left >= right)    /* do  nothing if array contains */
            return;           /* fewer than two elements */
        swap(v, left, (left + right)/2);
        last = left;
        for (i = left+1; i <= right;  i++)
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        swap(v, left, last);
        quickSort(v, left, last-1, comp);
        quickSort(v, last+1, right, comp);
    }
    void swap(void *v[],  int i, int j) {
        void *temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }


//  void testQuicksort() {
////        const  int size=5;
//    char* lineptr[5]={"white","red","black","yellow","blue"};
////        strcmp
//    quickSort(lineptr,0,4,(int (*)(const void *, const void *))strcmp);
//    //
//    int i;
//    for (i=0;i<5;i++) {
//        printf("%s\n",lineptr[i]);
//    }
//
//
//
//}
};


#endif // POINTANDARRAY_H_INCLUDED
