#ifndef UNKOWNTYPEOPR_H_INCLUDED
#define UNKOWNTYPEOPR_H_INCLUDED
/**
未知类型的操作
可用宏来实现类型参数！！！
**/
#undef swap2(t,x,y)
#define swap2(t,x,y)                             \
do {                                            \
    unsigned char* a=(unsigned char *)(&(x)); \
    unsigned char* b=(unsigned char *)(&(y)); \
    size_t i = sizeof(t);                       \
    while (i--) {                               \
        *a ^= *b;                               \
        *b ^= *a;                               \
        *a ^= *b;                               \
        a++;                                    \
        b++;                                    \
    }                                           \
} while (0)
#undef swap4(t,x,y)
#define swap4(t,x,y)                                     \
do {                                                    \
    (unsigned char *)_0=(unsigned char *)(&(x));        \
    (unsigned char *)_1=(unsigned char *)(&(y));        \
    unsigned long _2 = (unsigned long)                  \
       ((unsigned char *)(&(x)+1)                       \
        - (unsigned char *)(&(x)));                     \
    while (_2--) {                                      \
        *_0 ^= *_1;                                     \
        *_1 ^= *_0;                                     \
        *_0 ^= *_1;                                     \
        _0++;                                           \
        _1++;                                           \
    }                                                   \
} while (0)
void swapUnkownType(int len,void *x,void *y) {
    unsigned char* a=(unsigned char *)x;
    unsigned char* b=(unsigned char *)y;
    size_t i=len;

    while (i--) {
        //使用3次异或来交换
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
        a++;
        b++;
    }
}
void testUnkownTypeOpr(){
    int x=2,y=1;
    printf("integers before swap: %d and %d\n", x, y);
	swapUnkownType(sizeof(int),&x,&y);
	printf("integers after swap: %d and %d\n", x, y);
}

#endif // UNKOWNTYPEOPR_H_INCLUDED
