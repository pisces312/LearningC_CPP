#include "pointandarray.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
���ڼ�����ʵ��
strlen:  return length of string s */
int strlenCount(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/*
���ڵ�ַ��ʵ��
strlen:  return length of string s */
int strlenAddDif(char *s) {
    //!!����һ��Ҫ����һ������
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}
/////////////////////////////////////////////
////////////////////////////////////////////
/**
�򵥵Ĵ洢����
**/
#define ALLOCSIZE 1024 /* size of available space */
//������Ĵ洢���򣬴��������
//�ٶ�charΪ1�ֽ�
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */
//��λ���ֽ�
void *alloc(int n) {  /* return pointer to n characters */
    //allocbuf+ALLOCSIZEΪ�����ĩβ����allocp��Ϊ���õĿռ�
    if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */
        allocp += n;
        return allocp - n; /* ��Ϊ�ȼӣ�Ҫ���ش�ǰ��ֵold p */
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
    printf("��ַ=%x ����=%f\n",d,*d);
    afree(d);
    printf("%x\n",d);

}



void testPointer() {
    //ͬʱ���������ͺ���
    double *dp,atof4(char *);
    //����������������ָ��
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
���鷽ʽʵ��
strcpy:  copy t to s; array subscript version */
void strcpyArray(char *s, char *t) {
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

//For contrast, here is a version of strcpy with pointers:
/*
ָ�뷽ʽʵ��
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
δ֪���͵Ŀ�������
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
�������͵�˵��
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
//!��������ֻ���壬��ʵ��
//��3��ָ������ָ����ɵ�һά���飬�ú�������ָ����5���ַ���ɵ�һά�����ָ��
//    char* getFiveChar();
 char (*(*x[3])())= {getFiveChar,getFiveChar,getFiveChar};
//    char (*(*x[3])())[5]= {getFiveChar,getFiveChar,getFiveChar};
//    char (*(*x[3])())[5]={(char[5])getFiveChar,(char[5])getFiveChar,(char[5])getFiveChar};

}

/**
ָ�������ָ��
int (*xxx)[yy]
**/
void testArrayPointer() {
    int daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    //![]�����ȼ�����*,����*��pArray֮������Բ���ţ�����Ҫд�ڶ�ά�Ĵ�С
//    int (*pArray)[]=daytab;
//!��ǰ���������е��������ͣ�Ȼ����(*pArray)[13]˵��ָ���ά����
    int (*pArray)[13]=daytab;
//    int array2D[][13]=daytab;
    //������daytab�ĵ�һ��
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
ָ�빹�ɵ�����
**/
void testPointerArray() {
    int array[]= {1,2,3};
    int *p0=&array[0],*p1=&array[1],*p2=&array[2];
//    ((int*)p)[3]={p0,p1,p2};
//Ԫ����ָ��
    int *p[3]= {p0,p1,p2}; //(int *)malloc(sizeof(int*));
    //
    //ָ��һάָ������
    //!��һ
//    int **pArray=p;
//!����
//    (int *)*pArray=p;
//!���� �����е�������int * ��ָ��һά����
    int *(*pArray)=p;
    printf("%d\n",*(pArray[2]));
    //
    //
    //!ָ���������ά����Ĳ�ͬ
    //�����ԣ�ǰ�߸���ʡ�ռ䣬����ÿ�еĴ�С�����
    char *name[]= {"Illegal month","Jan","Feb","Mar"};
    char aname[][15]= {"Illegal month","Jan","Feb","Mar"};

    int sum=0;
    int i;
    for (i=0; i<4; i++) {
        //����ÿ���ַ�����\0
        sum+=(strlen(name[i])+1);
    }
    printf("%d\n",sum);
    printf("%d\n",sizeof(aname));

}
/**
�±�Ϊ����������
**/
void testNegativeIndexArray() {
    //���ýṹ��ķ���֤���˸����±꣡
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
    //�Ӵ�ӡ���Ľ�����Կ�������һ���ո񣬼�\0
    //
    //
    int a[]= {1,2,3};
//��c��a�еڶ���Ԫ�صĵ�ַ
//-1��ָ���һ��Ԫ�صĵ�ַ����
//!��������չ���±�ķ�Χ���ǵĸ����±겻Խ�磡����
    int* c=&a[1];
    printf("%d\n",c[-1]);
    printf("%d\n",*(c-1));

}



void testQuicksort() {
//        const  int size=5;
    char* lineptr[5]= {"white","red","black","yellow","blue"};
//        strcmp
//!��һ
    quickSort((void**)lineptr,0,4,(int (*)(const void *, const void *))strcmp);
//!����
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
//����⿼����ʵ��ָ�������ָ�룬&a��һ����ʽ��ָ��int [5]�����ָ�룬����int* ptr�ǲ�һ���ģ������Ҫ�������ָ�룬Ӧ����int (*ptoa)[5]������ptoaÿһ�μ�һ�������൱�ڿ�Խint a[5]���ڴ沽����Ҳ����5��int���ȣ���Ҳ����˵&a + 1��ʵ����ָ����a[6]���λ�ã�ʵ�����ڴ��������λ���ǷǷ��ģ����Ƕ�ptr��ǿ��ת�������˺���ptr-1���ڴ沽����Ϊ�� 1��int���ȣ����� ptr-1ʵ��ָ����a[5]������*(a+1)ûʲô��˵�ģ�ֵ����2��
}
void testArray2() {
    void foo2(int[][3]);
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    foo2(a);
    printf("%d\n", a[2][1]);


//��ʵ��ǰһ��������ͬ��֮�++b�Ĳ���ʵ������3��int��Ҳ����++b�����Ժ�bָ��{4,5,6}�������Ŀ�ʼ����b[1]���� {7,8,9}, b[1][1]ʵ���Ͼ���8���ֵҲ����main�����е�a[2][1].
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

//��Ȼ��2ά���������Ŀ��ptrΪָ��int [3]�����ָ�룬����ָ��a[0]������(*ptr)[1], (*ptr)[2]����a[0] [1], a[0][2].Ȼ��++ptr���൱��ptrָ����a[1]����ʱ�õ�����a[1][1]��a[1][2]�����Խ������ 2��3, 5, 6��
}
