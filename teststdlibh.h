#ifndef TESTSTDLIBH_H_INCLUDED
#define TESTSTDLIBH_H_INCLUDED
#include<stdlib.h>
//#include<string.h>
//    The header <stdlib.h> declares functions for
//1 number conversion,
//2 storage allocation,
//3 and similar tasks.

//double atof(const char *s)
//atof converts s to double; it is equivalent to strtod(s, (char**)NULL).
//
//int atoi(const char *s)
//converts s to int; it is equivalent to (int)strtol(s, (char**)NULL, 10).
//
//long atol(const char *s)
//converts s to long; it is equivalent to strtol(s, (char**)NULL, 10).
//
//double strtod(const char *s, char **endp)
//strtod converts the prefix of s to double, ignoring leading white space; it stores a pointer to any unconverted suffix in *endp unless endp is NULL. If the answer would overflow, HUGE_VAL is returned with the proper sign; if the answer would underflow, zero is returned. In either case errno is set to ERANGE.
//
//long strtol(const char *s, char **endp, int base)
//strtol converts the prefix of s to long, ignoring leading white space; it stores a pointer to any unconverted suffix in *endp unless endp is NULL. If base is between 2 and 36, conversion is done assuming that the input is written in that base. If base is zero, the base is 8, 10, or 16; leading 0 implies octal and leading 0x or 0X hexadecimal. Letters in either case represent digits from 10 to base-1; a leading 0x or 0X is permitted in base 16. If the answer would overflow, LONG_MAX or LONG_MIN is returned, depending on the sign of the result, and errno is set to ERANGE.
//
//unsigned long strtoul(const char *s, char **endp, int base)
//strtoul is the same as strtol except that the result is unsigned long and the error value is ULONG_MAX.
//
//int rand(void)
//rand returns a pseudo-random integer in the range 0 to RAND_MAX, which is at least 32767.
//
//void srand(unsigned int seed)
//srand uses seed as the seed for a new sequence of pseudo-random numbers. The initial seed is 1.
//
//void *calloc(size_t nobj, size_t size)
//calloc returns a pointer to space for an array of nobj objects, each of size size, or NULL if the request cannot be satisfied. The space is initialized to zero bytes.
//
//void *malloc(size_t size)
//malloc returns a pointer to space for an object of size size, or NULL if the request cannot be satisfied. The space is uninitialized.
//
//void *realloc(void *p, size_t size)
//realloc changes the size of the object pointed to by p to size. The contents will be unchanged up to the minimum of the old and new sizes. If the new size is larger, the new space is uninitialized. realloc returns a pointer to the new space, or NULL if the request cannot be satisfied, in which case *p is unchanged.
//
//void free(void *p)
//free deallocates the space pointed to by p; it does nothing if p is NULL. p must be a pointer to space previously allocated by calloc, malloc, or realloc.
//
//void abort(void)
//abort causes the program to terminate abnormally, as if by raise(SIGABRT).
//
//void exit(int status)
//exit causes normal program termination. atexit functions are called in reverse order of registration, open files are flushed, open streams are closed, and control is returned to the environment. How status is returned to the environment is implementation-dependent, but zero is taken as successful termination. The values EXIT_SUCCESS and EXIT_FAILURE may also be used.
//
//int atexit(void (*fcn)(void))
//atexit registers the function fcn to be called when the program terminates normally; it returns non-zero if the registration cannot be made.
//
//int system(const char *s)
//system passes the string s to the environment for execution. If s is NULL, system returns non-zero if there is a command processor. If s is not NULL, the return value is implementation-dependent.
//
//char *getenv(const char *name)
//getenv returns the environment string associated with name, or NULL if no string exists. Details are implementation-dependent.
//void *bsearch(const void *key, const void *base,
//              size_t n, size_t size,
//              int (*cmp)(const void *keyval, const void *datum))
//
//bsearch searches base[0]...base[n-1] for an item that matches *key. The function cmp must return negative if its first argument (the search key) is less than its second (a table entry), zero if equal, and positive if greater. Items in the array base must be in ascending order. bsearch returns a pointer to a matching item, or NULL if none exists.
//void qsort(void *base, size_t n, size_t size,
//           int (*cmp)(const void *, const void *))
//
//qsort sorts into ascending order an array base[0]...base[n-1] of objects of size size. The comparison function cmp is as in bsearch.
//
//int abs(int n)
//abs returns the absolute value of its int argument.
//
//long labs(long n)
//labs returns the absolute value of its long argument.
//
//div_t div(int num, int denom)
//div computes the quotient and remainder of num/denom. The results are stored in the int members quot and rem of a structure of type div_t.
//
//ldiv_t ldiv(long num, long denom)
//ldiv computes the quotient and remainder of num/denom. The results are stored in the long members quot and rem of a structure of type ldiv_t.

int compare(const void *keyval,const void *datum) {
    if (*(int *)keyval<*(int*)datum) {
        return -1;
    }
    if (*(int*)keyval==*(int*)datum) {
        return 0;
    }
    return 1;

}
void testBsearch() {
    //!二分查找
    int (*cmp)(const void*,const void *);
    cmp=compare;
    //!数组必须已排序
    int base[10]={1,2,4,6,7,9,12,34,65,67};
    int key=9;
    void *result=bsearch(&key,base,10,sizeof(int),cmp);
    if (result!=NULL) {
        printf("found! %d\n",(*(int*)result));
    }
}
void testQsort() {
    int (*cmp)(const void*,const void *);
    cmp=compare;
    //!数组必须已排序
    int base[10]={8,2,4,6,1,45,12,9,65,0};
    qsort(base,10,sizeof(int),cmp);
    int i;
    for (i=0;i<10;i++) {
        printf("%d\n",base[i]);
    }
}
struct Book {
    int id;
//    string name;
    char* name;
};
void callOnExitSuccess() {
    printf("Success\n");
}
void testStdlibHeader() {
    //string to float/double
    double d=atof("123.4567");
    printf("%f\n",d);
    //string to d (dec)
    //第二个参数非空，则函数把字符串中未转换的部分保存到其中
    double d2=strtod("234.5678",(char**)NULL);
    printf("%f\n",d2);
    //
    //
    int i=atoi("1234567");
    printf("%d\n",i);
    //基数是10
    int i2=(int)strtol("234567",(char**)NULL,10);
    printf("%d\n",i2);
    //
    //
    long l=atol("53454234");
    printf("%d\n",l);
    long l2=strtol("53454234",(char**)NULL,10);
    printf("%d\n",l2);
    //
    //
    unsigned long ul=strtoul("342351235",(char**)NULL,10);
    printf("%d\n",ul);
    //
    //
    unsigned int seed=123;
    srand(seed);
    int r=rand();
    printf("RAND_MAX=%d\n%d\n",RAND_MAX,r);
    //
    //

    //为对象数组分配内存calloc ( class allocatie )
    //返回无类型指针void*
    int arraySize=10;
//    struct Book book;
//    Book* ptr;
    struct Book* bookArray=(struct Book*)calloc(sizeof(struct Book),arraySize);
    bookArray[0].id=1;
    bookArray[0].name="nili";
    printf("%d\n%s\n",bookArray[0].id,bookArray[0].name);
    //
    //
    //
    int* array=(int*)malloc(10*sizeof(int));
    printf("%p--%p\n",array,&array);
//    printf("%p\n",array);

    //
    //realloc即重新分配指定指针锁指向的对象的大小
    //
    //!新分配的内存比原内存小，则保持内容不变
    //!新分配的内存比原内存大，则保持内容不变，增加的空间不进行初始化
    //!返回指向新空间的指针
    //!gcc中都地址都没有变化
    realloc(array,5*sizeof(int));//比原来小的情况
    printf("%p--%p\n",array,&array);//地址不变
    //
    realloc(array,15*sizeof(int));//比原来大的情况
    printf("%p--%p\n",array,&array);//地址不变??
    //
    //
    free(array);
    if (array==NULL) {
        printf("released\n");
    }
    //
    //
    //system把字符串传送给执行环境
//    system("notepad.exe");
//
//返回与参数字符串相关的环境字符串
//!获得环境变量
    char* env=getenv("Path");
    printf("%s\n",env);
//

//
//!快速排序
    testQsort();
//!二分查找
    testBsearch();



    int intAbs=abs(-234);
    long longAbs=labs(-234);
//!求余数
//!div_t为typedef过后的结构型，不需要加struct
    div_t result;
    result=div(10,3);
    printf("商%d,余%d\n",result.quot,result.rem);

    //
    //!求long余数
//div_t为结构型
//    struct div_t result=div(10,3);
//    struct div_t result;
    ldiv_t result2;
    result2=ldiv(134729380,3);
    printf("商%d,余%d\n",result2.quot,result2.rem);




    //
    //!非正常终止
//    abort();
    //!等价于
//    raise(SIGABRT);
    //
    //
    //!正常终止,0表示终止成功
//    exit(EXIT_SUCCESS);//EXIT_SUCCESS=0

//
//!注册程序正常终止时所要调用的函数
    void (*fcn)(void);
    fcn=callOnExitSuccess;
    atexit(fcn);










}


#endif // TESTSTDLIBH_H_INCLUDED
