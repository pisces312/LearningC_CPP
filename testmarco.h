#ifndef TESTMARCO_H_INCLUDED
#define TESTMARCO_H_INCLUDED
//
//!�����ò����ʽ��
//������ƻ�define�ĸ�ʽ
#undef max
#define max(A,B) ((A)>(B)?(A):(B))
//#��ʹ��,���ַ���֮�����ֱ������
#define  dprint(expr)   printf(#expr " = %g\n", (expr))
//##�ṩ����ʵ�ʱ�Ԫ������
#define paste( front,back) front##back
/**
�ú���ʵ�ֽ�������
**/
//��һ
#define swap1(t,x,y) do{    t z=x;    x=y;    y=z;    } while(0)
//"\"��ʾ����
//����
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
//����
//�����������ͻ
#define swap3(t, x, y) \
	do { \
		t safe ## x ## y; \
		safe ## x ## y = x; \
		x = y; \
		y = safe ## x ## y; \
	} while (0)

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

void testMarcoSwap(){
    	int ix, iy;
	double dx, dy;
	char *px, *py;

	ix = 42;
	iy = 69;
	printf("integers before swap: %d and %d\n", ix, iy);
	swap1(int, ix, iy);
	printf("integers after swap: %d and %d\n", ix, iy);

	dx = 123.0;
	dy = 321.0;
	printf("doubles before swap: %g and %g\n", dx, dy);
	swap2(double, dx, dy);
	printf("integers after swap: %g and %g\n", dx, dy);

	px = "hello";
	py = "world";
	printf("pointers before swap: %s and %s\n", px, py);
	swap3(char *, px, py);
	printf("integers after swap: %s and %s\n", px, py);

}
void testMarco() {
    #define min(A,B) ((A)<(B)?(A):(B))
    printf("%d\n",max(2,1));
    //!���������
    int i=1;
    int j=2;
    printf("%d\n",max(i++,j++));
    //����i��j�Ĵ�С��i<j����ִ��һ��i++����j++
    printf("%d  %d\n",i,j);
    double x=2;
    double y=1;
    //???�޷��õ�2
//    int x=2;
//    int y=1;
    dprint(x/y);
    printf("%d\n",min(1,20));
    //
    int a=32,b=33;
    int paste(a,b)=34;
    printf("%d\n",ab);
    //
    //
    testMarcoSwap();

//the macro is expanded into
//   printf("x/y" " = &g\n", x/y);


}

#endif // TESTMARCO_H_INCLUDED
