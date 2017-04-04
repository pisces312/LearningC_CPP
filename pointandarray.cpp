#include "pointandarray.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
基于计数的实现
strlen:  return length of string s */
int strlenCount(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/*
基于地址的实现
strlen:  return length of string s */
int strlenAddDif(char *s) {
    //!!这里一定要用另一个变量
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}
/////////////////////////////////////////////
////////////////////////////////////////////
/**
简单的存储分配
**/
#define ALLOCSIZE 1024 /* size of available space */
//被分配的存储区域，从这里分配
//假定char为1字节
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */
//单位是字节
void *alloc(int n) {  /* return pointer to n characters */
    //allocbuf+ALLOCSIZE为缓存的末尾，减allocp后为已用的空间
    if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */
        allocp += n;
        return allocp - n; /* 因为先加，要返回从前的值old p */
    }
    return 0;
}

void afree(void *p) { /* free storage pointed to by p */
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = (char*)p;
//    p=0;
//free(p);
}
void testAlloc() {
    double *d=(double *)alloc(sizeof(double));
    *d=3.14159;
    printf("地址=%x 内容=%f\n",d,*d);
    afree(d);
    printf("%x\n",d);

}



void testPointer() {
    //同时声明变量和函数
    double *dp,atof4(char *);
    //不能用数组名接收指针
//    int* pa=(int *)malloc(sizeof(int));
//    int a[1]=pa;
//


    //
    testAlloc();
    //
    //
    char *str="Hello world!\n";
    printf("%d\n",strlenCount(str));
    printf("%d\n",strlenAddDif(str));
    //
    char amessage[]="now is the time";
    char *pmessage=amessage;//"now is the time";
    printf("%x\n",amessage);
    printf("%x\n",pmessage);
    printf("%x\n",&pmessage[0]);
    //
    printf("%x\n",pmessage[0]);
    printf("%x\n",*pmessage);

}

//
//
//
/*
数组方式实现
strcpy:  copy t to s; array subscript version */
void strcpyArray(char *s, char *t) {
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

//For contrast, here is a version of strcpy with pointers:
/*
指针方式实现
 strcpy:  copy t to s; pointer version */
void strcpyPointer(char *s, char *t) {
    int i;

    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
/* strcpy:  copy t to s; pointer version 2 */
void strcpyPointer2(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}
/* strcpy:  copy t to s; pointer version 3 */
void strcpyPointer3(char *s, char *t) {
    while (*s++ = *t++)
        ;
}
//
//
//
/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpArray(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

//The pointer version of strcmp:
/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpPointer(char *s, char *t) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}


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
int strcmp2(const void* a,const void *b) {
    return strcmp((const char*)a,(const char*)b);
}
/**
复杂类型的说明
dcl:       optional *'s direct-dcl
direct-dcl name
                 (dcl)
                 direct-dcl()
                 direct-dcl[optional size]


**/
//char[] getFiveChar(){
//    return NULL;
//}
char* getFiveChar() {
    return NULL;
}
void testComplicateType() {
//    char (*(*x())[])()
//    x: function returning pointer to array[] of
//    pointer to function returning char
//char (*(*x[3])())[5]
//    x: array[3] of pointer to function returning
//    pointer to array[5] of char

//    char* str getFiveChar();
//    char str[5] getFiveChar();
//!函数不能只定义，不实现
//由3个指向函数的指针组成的一维数组，该函数返回指向由5个字符组成的一维数组的指针
//    char* getFiveChar();
 char (*(*x[3])())= {getFiveChar,getFiveChar,getFiveChar};
//    char (*(*x[3])())[5]= {getFiveChar,getFiveChar,getFiveChar};
//    char (*(*x[3])())[5]={(char[5])getFiveChar,(char[5])getFiveChar,(char[5])getFiveChar};

}

/**
指向数组的指针
int (*xxx)[yy]
**/
void testArrayPointer() {
    int daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    //![]的优先级大于*,所以*与pArray之间必须加圆括号，必须要写第二维的大小
//    int (*pArray)[]=daytab;
//!最前面是数组中的数据类型，然后是(*pArray)[13]说明指向二维数组
    int (*pArray)[13]=daytab;
//    int array2D[][13]=daytab;
    //这里获得daytab的第一行
    int *p0=pArray[0];
    int i;
    for (i=0; i<13; i++) {
        printf("%d\n",p0[i]);
    }
    //
    //
//    (int *pArray2)[13]=daytab;
}
/**
指针构成的数组
**/
void testPointerArray() {
    int array[]= {1,2,3};
    int *p0=&array[0],*p1=&array[1],*p2=&array[2];
//    ((int*)p)[3]={p0,p1,p2};
//元素是指针
    int *p[3]= {p0,p1,p2}; //(int *)malloc(sizeof(int*));
    //
    //指向一维指针数组
    //!法一
//    int **pArray=p;
//!错误
//    (int *)*pArray=p;
//!法二 数组中的类型是int * ，指向一维数组
    int *(*pArray)=p;
    printf("%d\n",*(pArray[2]));
    //
    //
    //!指针数组与二维数组的不同
    //很明显，前者更节省空间，后者每行的大小都相等
    char *name[]= {"Illegal month","Jan","Feb","Mar"};
    char aname[][15]= {"Illegal month","Jan","Feb","Mar"};

    int sum=0;
    int i;
    for (i=0; i<4; i++) {
        //加上每个字符串的\0
        sum+=(strlen(name[i])+1);
    }
    printf("%d\n",sum);
    printf("%d\n",sizeof(aname));

}
/**
下标为负数的数组
**/
void testNegativeIndexArray() {
    //采用结构体的方法证明了负数下标！
    struct TT {
        char str1[5];
        char str2[5];
    } t;
//    struct TT t;
    strcpy(t.str1, "abcd");
    strcpy(t.str2, "1234");
    int i;
    for (i=-1; i > -6; i--)
        printf("%c",t.str2[i]);
    printf("\n");
    //从打印出的结果可以看到先有一个空格，即\0
    //
    //
    int a[]= {1,2,3};
//给c赋a中第二个元素的地址
//-1则指向第一个元素的地址！！
//!这样就扩展了下标的范围，是的负数下标不越界！！！
    int* c=&a[1];
    printf("%d\n",c[-1]);
    printf("%d\n",*(c-1));

}



void testQuicksort() {
//        const  int size=5;
    char* lineptr[5]= {"white","red","black","yellow","blue"};
//        strcmp
//!法一
    quickSort((void**)lineptr,0,4,(int (*)(const void *, const void *))strcmp);
//!法二
//    quickSort((void *)lineptr,0,4,strcmp2);
    //
    int i;
    for (i=0; i<5; i++) {
        printf("%s\n",lineptr[i]);
    }

}




void testArray1() {
    int a[5] = { 1, 2, 3, 4, 5 };
    int *ptr = (int*)(&a + 1);
    printf("%d %d\n",*(a + 1),*(ptr-1));
//这道题考的其实是指向数组的指针，&a是一个隐式的指向int [5]数组的指针，它和int* ptr是不一样的，如果真要定义这个指针，应该是int (*ptoa)[5]。所以ptoa每一次加一操作都相当于跨越int a[5]的内存步长（也就是5个int长度），也就是说&a + 1其实就是指向了a[6]这个位置，实际上内存里面这个位置是非法的，但是对ptr的强制转换导致了后面ptr-1的内存步长改为了 1个int长度，所以 ptr-1实际指向了a[5]。至于*(a+1)没什么好说的，值就是2。
}
void testArray2() {
    void foo2(int[][3]);
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    foo2(a);
    printf("%d\n", a[2][1]);


//其实和前一题有异曲同工之妙，++b的步长实际上是3个int，也就是++b运算以后，b指向{4,5,6}这个数组的开始，而b[1]就是 {7,8,9}, b[1][1]实际上就是8这个值也就是main函数中的a[2][1].
}
void foo2(int b[][3]) {
    ++b;
    b[1][1] = 9;
}
void testArray3() {
    int a[][3] = {1, 2, 3, 4, 5, 6};
    int (*ptr)[3] = a;

    printf("%d %d ", (*ptr)[1], (*ptr)[2]);

    ++ptr;
    printf("%d %d\n", (*ptr)[1], (*ptr)[2]);

//依然是2维数组相关题目，ptr为指向int [3]数组的指针，首先指向a[0]，所以(*ptr)[1], (*ptr)[2]就是a[0] [1], a[0][2].然后++ptr，相当于ptr指向了a[1]，这时得到的是a[1][1]，a[1][2]，所以结果就是 2，3, 5, 6。
}
