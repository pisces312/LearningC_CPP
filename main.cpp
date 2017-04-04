#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <memory.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <typeinfo>
#include <string>
#include <iomanip>
#include <hash_map>
#include <vector>
#include <deque>
#include <list>
#include <cstring>
#include <climits>

#ifdef WIN32
#include  <iso646.h>
#endif

//#include"ch01.h"
//#include"testlimits.h"
//#include"testfloath.h"
//#include"ch02.h"
//#include"testctypeh.h"
//#include"testrandom.h"
//#include"testmathh.h"
//#include"ch03.h"
//#include"teststdlibh.h"
//#include"ch04.h"
//#include"testtime.h"
//#include "file1.h"
//#include "testmarco.h"


//#include "unkowntypeopr.h"
#include "pointandarray.h"
//#include "dcl.h"
#include "teststruct.h"
//#include "hashlist.h"
//#include "testtyepdef.h"
//#include "testunion.h"
//#include "testbitfield.h"
//#include "testio.h"
//#include "calcforfunc.h"


//#include "struct.h"
#include "class.h"
//#include "Student.h"
#include "testSTLSet.h"
//#include "ch12_15.h"
//#include "testCIN.h"



//#include"teststl.h"
//#include"tutility.h"
//#include"tallocator.h"
//#include"tmemory.h"
//#include"talgorit.h"
//#include "ManOrBoyTest.h"
//#include "difFunction.h"

////
//#include "mystrcat.h"
//#include "dataconverter.h"
//#include "arraypoint.h"
//#include "testboost.h"
//#include "PointAndArray.h"
//#include "mianshi.h"
//#include "linkknowledge.h"


using namespace std;





/**
求概率
**/
void calcProbability() {
    int c = 0;
    int loop = 1000;
    for (int i = 0; i < loop; i++) {
        int x = rand();
        int y = rand();
        if (x * x + y * y < RAND_MAX * RAND_MAX)
            c++;
    }
    printf ("%d\n   %f\n", c, loop * 3.1415926 / 4);
}
/**
STL对象指针能够自动析构
**/
class CDemo {
public:
    CDemo() {
        cout << "constructor\n";
    }
    ~CDemo() {
        cout << "destructor\n";
    }
};
void testVectorPtr() {

    vector<CDemo> *v = new vector<CDemo>();
    v->push_back (CDemo() );
//    v->push_back("b");
//    delete v;
}
//////////////////////////////////////////
void testDupElements() {
    vector<int> array;
    array.push_back (1);
    array.push_back (2);
    array.push_back (6);
    array.push_back (1);
    array.push_back (6);
//    array.erase(remove(array.begin(),array.end(),6));
//    array.erase(remove(array.begin(),array.end(),6),array.end());
    for (vector<int>::iterator itr = array.begin(); itr != array.end(); itr++) {
        cout << *itr << endl;
    }
}


void testCannotRefToArray() {
    //不能建立数组的引用
//    char a[5]="hello“；
//    char &b[5]=a;
}
/**
关于无符号的计算，负数的情况
**/
void testUnsignedCalc() {
    unsigned short int i = 0;
    i--;
    cout << i << endl;
//    cout<<(i-1)<<endl;
}
/**
测试地址的强制转换
**/
void testAddrCast() {
    int* a = new int (1);
    cout << a << endl;
    int* ptr = (int*) 0x270f86;
    cout << *ptr << endl;
    //
    //晦涩的方式
    * (int * const) (0x1234) = 123456;


}
/**

**/
void testUnsignedInt() {
//    unsigned int zero=0;
    //unsigned int compzero=0xffff;
//    cout<<compzero<<endl;
    //0的补码
    unsigned int compzero2 = ~0;
    cout << compzero2 << endl;
    cout << (~0) << endl;

}
/**
返回全1的掩码
**/
unsigned int getFullOneBitMask() {
    return ~0;
}
/**
判断大小端存放
1 小端
0 大端
**/
int checkCPU() {
    union w {
        int a;
        char b;
    } c;
    c.a = 1;
    return (c.b == 1);
}
///
double f1() {
    printf ("f1\n");
    return 0;
}
void test2() {
    typedef double (*f2) ();
    f2* e = new f2[9];
    e[0] = f1;
    e[0]();
}
//
//typedef double(*)() (*ea)[9];

void test3() {
    typedef double (*e[9]) ();
    e evar;
    evar[0] = f1;
    evar[0]();
}
/**
原来
d        s
|        |
1 2 3 \0 1 2 3 4 5 6 7 8 9 \0
strcpy后
1 2 3  4 5 6 7 8 9 \0 7 8 9 \0
所以d的输出（到\0结束）
123456789
s的输出
56789
**/
void test4() {
    char s[] = "123456789";
    char d[] = "123";
    strcpy (d, s);
    printf ("%s,\n%s", d, s);

}
/**
循环右移
???不能修改源指针所指的内容
**/
void loopMove (char* pStr, int steps) {
    //不管最后的一个\0
    int n = strlen (pStr) - steps;
    cout << n << endl;
//    char tmp[100];
    char* tmp = new char [100];
    memcpy (tmp, pStr + n, steps);
    //??不能修改pStr中的内容？

    memcpy (pStr + steps, pStr, n);
//    memcpy(tmp+steps,pStr,n);
//    memcpy(pStr,tmp,n);
    memcpy (pStr, tmp, steps);

}
void testLoopMove() {
    char* pStr = "1234567";
    loopMove (pStr, 3);
    cout << pStr << endl;
}
/**
一般整型和数组在同一行声明，且数组大小由变量确定
supported by gcc
**/
void test5() {
    /*int n = 10, a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;
        cout << a[i] << endl;
    }*/
}
typedef struct bitstruct {
    int b1: 5;
    int : 2;
    int b2: 2;
} bitstruct;
void testLittleEndian() {
    bitstruct b;
    memcpy (&b, "EMC EXAMINATION", sizeof (b) );
    printf ("%d,%d size=%d\n", b.b1, b.b2, sizeof (b) );
}
struct S1 {
    char c;
    int i;
};
void myalloc (char* x, int n) {
    x = (char*) malloc (n * sizeof (char) );
//    memset(x,\0,n*sizeof(char));//wrong
}
void StructCanExtend() {
    struct A {
    };
    struct B: public A {
    };
    char* const p = "abc";
    p[0] = 'd';
}
void test6() {
    struct A {
        double a;
        int b;
    };
    struct B {
        int a;
        int b;
    };
    struct C {
        char a;
        int b;
    };
    printf ("%d,%d\n", sizeof (A), sizeof (B) );
    C* c = (C*) malloc (5);
    memset (c, 0, 5);
    printf ("%d,%d\n", c->a, c->b);
    printf ("%x,%x\n", &c->a, &c->b);

    struct D {
        C c;
        A a;

    };
    printf ("%d\n", sizeof (D) );
}
void test7() {
    int i = 1, j = i++;
    if ( (i++) > ++j && (++i == j) ) {
        i += j;
    }
    printf ("%d\n", i);
}
void test8() {
    int a[5]= {0};
    int b[5]= {1};
    for(int i=0; i<5; ++i) {
        printf("%d\n",a[i]);
    }
    for(int i=0; i<5; ++i) {
        printf("%d\n",b[i]);
    }
}

void test10() {
    struct A {
//        int b;
//        char a;
//        char c;
//short int a;
//long long a;
        long double a;//12bytes

    };
//    A a,b;

    printf("%d\n",sizeof(A));
}
void testLexicographicalCompare() {
    int a[]= {1,2,3,4,5};
    int b[]= {1,2,3,4,5};
    bool ret= lexicographical_compare(a, a+5,b,b+5);
    printf("%d\n",ret);
}
double calc() {
    return 1.0;
}
//double calc;
void testPrintFixedWidth() {
    char parStr[32];
//        parStr[0]='%';
//        parStr[1]='-';
    int w =9;
//        int w =8;
    cout<<"|"<<setw(8)<<"中文"<<"|"<<endl;
    cout<<"|"<<setw(8)<<"中"<<"|"<<endl;
    cout<<"|"<<setw(8)<<"abc"<<"|"<<endl;

//    sprintf(parStr,"||%s-%ds||\n","%",w);
//    printf(parStr,L"abc");
//
//    sprintf(parStr,"||%s-%dls||\n","%",11);
//    printf(parStr,L"中a国");
//
//    sprintf(parStr,"||%s-%dls||\n","%",w);
//    printf(parStr,L"中aasd");
//
//    sprintf(parStr,"||%s-%dls||\n","%",11);
//    printf(parStr,L"abc");
//
//    sprintf(parStr,"||%s-%ds||\n","%",w);
//    printf(parStr,"中a国");

}
void testTypeid() {
    class A {
    };
    class B:public A {
    };
    class C:public B {
        void func() const volatile {
        }
        void func2() volatile const {
        }
    };
    A *pa=new C;
    cout<<typeid(pa).name()<<endl;
}
const char* g_a="abc";
void testConstChar() {
    const char* a="abc";
    const char* b="abc";
    const char* c="ABC";
    if(a==b) {
        printf("equal!\n");
    }

    if(g_a==b) {
        printf("equal2!\n");
    }

    if(a==c) {
        printf("equal3!\n");
    }
    if("abc"=="abc") {
        printf("equal4!\n");
    }
    const void *d=&"abc";

    char* e="abc";
    char f[]="abc";//给数组初始化，

    if(a==e) {
        printf("equal5!\n");
    }

    if(f==e) { //不等
        printf("equal6!\n");
    }


}
//void fcn(const int){}
//void fcn(int){}
void func(int (&arr)[10]) {
}
void func(int *arr) {
}
void test11() {
    class Base {

    protected:
        int a;
    public:
        static void* operator new(size_t size) {
            printf("opr new\n");
            return NULL;
        }

    };
    class D:virtual public  Base {
//    class D:private Base{
//    class D:protected Base{
    public:
        void func() {
//            int b=a;
        }
    };
    Base* b=new Base;
    if(b==NULL) {
        printf("null\n");
    }
}
void test12() {
//    class A { //4
//        int a;
//        void b();
//        int aa();
//    };
    /**
    sizoe(B)+size(int)+一个指向基类B的位移指针+虚指针=20
    VS环境下派生类虚继承基类时，且定义了新的虚函数时有自己的虚表和相应的虚指针，GCC编译器下，派生类虚继承基类时总是沿用其基类的虚表，所以在GCC下的编译结果为sizoe(B)+sizeof(int)+一个指向基类B的位移指针=16
    **/
    class B {  //8
        int b;
        virtual void bu();
    };
    class C:virtual public B {
        int c;
        virtual void c4();
    };//20
    printf("%d\n",sizeof(C));
}
void test13() {
    struct A {
        int a:2;
        int:10;
        short b:1;
        float c;
        int d:33;
        //float d:1;
    };
    //printf("%d\n",sizeof(A::a));
    //printf("%d\n",sizeof(A.a));
}
void test14() {
    typedef struct bitstruct {
// int b1:2;
//        int b2:5;
        int b1:5;
        int b2:2;
//        int b3:3;
        unsigned int b3:3;
        //int b3:3;
    } bitstruct;
    bitstruct b;
    const char* str="EMC";
    memcpy(&b,str,sizeof(b));
    bitstruct* c=&b;
    printf("%d\n%d\n%d\n",b.b1,b.b2,b.b3);


    struct B1 {
        int b1:5;
    };
    B1 b1;

    *((char*)&b1)='M';
    B1* b2=&b1;
    printf("%d\n",b1.b1);
}
void test22() {
//    printf("0x%x", (&0)[-1]);
}

////////////////////////////////////////////////////
template<class T>
void function(T t){
    printf("template\n");
}
template<>
void function(int){
    printf("specialized\n");
}
void function(int n){
    printf("common function\n");
}
void test23(){
    function(1);

}


void testFloat() {
    float a;
    float b;
    float c;
    if((a+b)+c==(b+a)+c) {
        printf("equal\n");
    }
    if((a+b)+c==(a+c)+b) {
        printf("equal\n");
    }

}

struct S { //class S可自行试验，结果相同
//private:
    int x;
//public:
    double y;
//    S(void) {}
//    S(int idemo,double ddemo) {
//        x=idemo;
//        y=ddemo;
//    }
    void show(void) {
        cout<<x<<"\t"<<y<<endl;
    }
};
void testS() {
    S os[4];
//    S os[4]={S(10,1.234),S(20,2.234)};//未初始化的将调用默认构造函数。如果此时没有默认构造函数将会出错。
}

//void test2(int a,const int b,int*c,const int*d){
//    printf("%d\n",a);
//
//}
void test3(const int& a) {
}
class test3 {
public:
    test3() {}
};
extern int array[];
//char *p=(char*)malloc(10);
void testConstPtrAndPtrConst() {
    int b=1;
    int c=2;

    int const* a=&b;
    a=&c;
    const int * a2=&b;
    a2=&c;

    int* const a3=&b;
    *a3=2;

    const int d=3;
    const int* const a4=&d;
    int const* const a5=&d;
//    const* int a4=&b;
//    *a=2;
//    printf("%d\n",*a);
}
int fn1() {
    printf("next.\n");
    return 0;
}

int fn2() {
    printf("executed ");
    return 0;
}

int fn3() {
    printf("is ");
    return 0;
}

int fn4() {
    printf("This ");
    return 0;
}
void testOnExit() {
    int fn1(void), fn2(void), fn3(void), fn4(void);
    _onexit_t func=fn1;
    _onexit(func);
    _onexit(fn2);
    _onexit(fn3);
    _onexit(fn4);
    printf("This is executed first.\n");

}

//void testConstRef()
void testConstClassFunction() {
    class D {
    public:
        D() {}
        void func() {
            printf("D func\n");

        }
        void func() const {
            printf("D const func\n");

        }
    };
    class Base {
    public:
        Base():data2(1) {}
        void nonConstFunc() {
            printf("non-const func\n");
        }
        void func() {
            printf("non-const func\n");
        }
        void func() const {
            printf("const func\n");
        }
        //ok
        int& FuncA(const int& a) {
            return number;
        }
        int FuncB(const int& a) const {
            return number;
        }
        int& FuncC(const int& a) const {
            //a+=number;//x
//            return number;
            static int b;
            return b;
        }


//        int& FuncB(const int& a) const {
////            a=number;
//            return number;
//        }
        const int& getData() const {
            return data2;
        }

        int getData2() const {
            return data1;
        }

        //return type is changed from int to const int
//        int& getData3() const {
//            return data1;
//        }

        const int& getData3() const {
            return data1;
        }

        const int func4(int& a) {
            return number+a;
        }
    private:
        int number;
    public:
        int data1;
        const int data2;

        D d;
        const D d2;
    };


    const int b=1;
    const int& a=b;

    Base base1;
    base1.func();

    const Base base2;
    base2.func();

    base2.d.func();
    base2.d2.func();
//    printf("%x\n",base2.c);
//    printf("%x\n",base2.c2);

    base2.getData();
    base2.getData2();
    base2.getData3();

    const Base& base3=base1;
    base3.func();
    //base3.nonConstFunc();//x

    //????
    const int e=base3.data1;
    const int d=base3.data2;

//    class Screen {
//    public:
//        Screen() {}
//    };
//    const Screen s;
}
//not allowed on msvc
//int nonReturnValueFunc(){
//}
void testArrayToPtr(int a[10],char b[10]) {
    printf("%d,%d\n",sizeof(a),sizeof(b));
}
#ifndef WIN32
void function(int n) {
    int a[n];   /*定义一个int数组，其元素个数为n。*/
    /*注意：这个数组的空间是在栈上分配的，一般会比malloc快*/
    /*对数组进行各种操作*/
}
#endif
void testInlineVirtual() {
    class B {
    public:
        inline virtual void func1() {
            printf("B\n");
        }
        inline virtual void func2()=0;
    };
    class D:public B {
    public:
        void func1() {
            printf("D\n");
        }
        void func2() {
            printf("D pure virtual function\n");
        }
    };
    D* d=new D;
    D* d2=new D();
}
void testMemOverlapped() {
    char *p = NULL;
    p = (char *)malloc(10);
    memcpy(p,"1234679",strlen("1246789"));
    printf("before p = %s\n", p);
    strcpy(p+1,p);//这重叠了
    printf("after p = %s\n", p);
    free(p);

}
void testImplicitCast() {
    class Integer {
    public:
        Integer():m_i(0) {}
        Integer(int a):m_i(a) {
            printf("ctor\n");
        }
        Integer(const Integer& i):m_i(i.m_i) {
            printf("copy ctor\n");
        }
        Integer& operator=(const Integer& i) {
            m_i=i.m_i;
            printf("operator=\n");
            return *this;
        }
    private:
        int m_i;
    };
    Integer a(1);
    Integer i=2;
    Integer i2(a);
    Integer i3=a;
    Integer i4;
    i4=i3;
    Integer i5;
    i5=3;

//    Integer i=2*a;
}
void testGoto() {
    class B {
    public:
        B() {
            printf("B ctor\n");
        }
        ~B() {
            printf("B dtor\n");
        }
    };
    int i=0;
start:
    B b;
    if(i==0) {
        ++i;
        goto start;
    }

//end:
//    B d;
}
void testFor() {
    int i=0;
    int sz=1;
    for(; i!=sz; ++i) {
        printf("a\n");
    }
}
void testSwitch() {
    int a=0;
    switch(a) {
    case 1:
    case 2:
        break;
    }
}
void testIf() {
    if(int a=0) {
    } else {
        a=1;
    }
}
#ifndef WIN32
void testCStyleAndString() {
    size_t count=1000000;
    clock_t start,end;

    const char *pc = "a very long literal string";
    const size_t len = strlen(pc +1);      // space to
    // performance test on string allocation and copy

    start=clock();
    for(size_t ix = 0; ix != count; ++ix) {
        char *pc2 = new char[len + 1]; // allocate the space
        strcpy(pc2, pc);               // do the copy
        if(strcmp(pc2, pc))            // use the new string
            ;   // do nothing
        delete [] pc2;                 // free the memory
    }
    end=clock()-start;
    printf("c style %d\n",end);


    char *pc3 = new char[len + 1]; // allocate the space
    start=clock();
    for(size_t ix = 0; ix != count; ++ix) {
        strcpy(pc3, pc);               // do the copy
        if(strcmp(pc3, pc))            // use the new string
            ;   // do nothing
    }
    end=clock()-start;
    delete[] pc3;
    printf("c style ex %d\n",end);

    char *pc4 = new char[len + 1]; // allocate the space
    start=clock();
    for(size_t ix = 0; ix != count; ++ix) {
        memcpy(pc4,pc,len+1);
        if(strcmp(pc4, pc))            // use the new string
            ;   // do nothing
    }
    end=clock()-start;
    delete[] pc4;
    printf("c style ex2 %d\n",end);

    char *pc5 = new char[len + 1]; // allocate the space
    start=clock();
    for(size_t ix = 0; ix != count; ++ix) {
        memcpy(pc5,pc,len+1);
        if(memcmp(pc5, pc,len))            // use the new string
            ;   // do nothing
    }
    end=clock()-start;
    delete[] pc5;
    printf("c style ex3 %d\n",end);


    // string implementation
    string str("a very long literal string");
    // performance test on string allocation and copy
    start=clock();
    for(int ix = 0; ix != count; ++ix) {
        string str2 = str; // do the copy, automatically
        if(str != str2)            // use the new string
            ;  // do nothing
    }
    end=clock()-start;
    printf("string %d\n",end);



    start=clock();
    string str3;
    for(int ix = 0; ix != count; ++ix) {
        str3 = str; // do the copy, automatically
        if(str != str3)            // use the new string
            ;  // do nothing
    }
    end=clock()-start;
    printf("string ex %d\n",end);


}

void testCharAndString() {
    int i,time1,time2,time3,timec=0,times=0;
    time1 = clock();
    for(i=0; i <= 5000000; i++) void();
    time2 = clock();
    time3 = time2 - time1;
    printf("5000000次加法所花时间：%dms\n\n\n",time3);


    {
        char a[]="asdifkhvlanlawoeifdyuhoijqwoienvklsaoiyudpify7382109r789hvoih298375489yhvoiaoiuy39876890rfhoiajsdoify9827r89fhoaijhdsflkjaklsdjfklasjldkfjoiyr890ghoiavhsdowe";
        char temp[160];
        char b[]="hvoih29";
        char c[]="asdifkhvlanlawoeifdyuhoijqwoienvklsaoiyudpify7382109r789hvoih298375489yhvoiaoiuy39876890rfhoiajsdoify9827r89fhoaijhdsflkjaklsdjfklasjldkfjoiyr890ghoiavhsdow2";
        char * pos;
        int t;
        time1 = clock();
        for(i=0; i <= 5000000; i++) {
            strcpy(temp,a);
        }
        time2 = clock();
        timec = time2-time1-time3;
        printf("char *复制5000000次所花时间：%dms\n",time2-time1-time3);


        time1 = clock();
        for(i=0; i <= 5000000; i++) {
            pos = strstr(b,temp);
        }
        time2 = clock();
        timec = timec + time2 - time1 - time3;
        printf("char *查找子串5000000次所花时间：%dms\n",time2-time1-time3);


        time1 = clock();
        for(i=0; i <= 5000000; i++) {
            t = strcmp(temp,c);
        }
        time2 = clock();
        timec = timec + time2 - time1 - time3;
        printf("char *比较5000000次所花时间：%dms\n",time2-time1-time3);
    }
    printf("char *三项操作所花时间：%dms\n\n\n",timec);

    {
        string a = "asdifkhvlanlawoeifdyuhoijqwoienvklsaoiyudpify7382109r789hvoih298375489yhvoiaoiuy39876890rfhoiajsdoify9827r89fhoaijhdsflkjaklsdjfklasjldkfjoiyr890ghoiavhsdowe";
        string b = "hvoih29";
        string c= "asdifkhvlanlawoeifdyuhoijqwoienvklsaoiyudpify7382109r789hvoih298375489yhvoiaoiuy39876890rfhoiajsdoify9827r89fhoaijhdsflkjaklsdjfklasjldkfjoiyr890ghoiavhsdow2";
        int pos;
        bool t;
        string temp;
        time1 = clock();
        for(i=0; i <= 5000000; i++) {
            temp = a;
        }
        time2 = clock();
        times = times + time2 - time1 - time3;
        printf("string复制5000000次所花时间：%dms\n",time2-time1-time3);

//使用string自带的
//        time1 = clock();
//        for (i=0; i <= 5000000; i++) {
//            pos = temp.find(b);
//        }
//        time2 = clock();
//        times = times + time2 - time1 - time3;
//        printf("string查找子串5000000次所花时间：%dms\n",time2-time1-time3);

//借用char的
        time1 = clock();
        char* pc;
        for(i=0; i <= 5000000; i++) {
            pc= strstr(b.c_str(),temp.c_str());
        }
        time2 = clock();
        times = times + time2 - time1 - time3;
        printf("string查找子串5000000次所花时间：%dms\n",time2-time1-time3);



        time1 = clock();
        for(i=0; i <= 5000000; i++) {
            t = temp == c ;
        }
        time2 = clock();
        times = times + time2 - time1 - time3;
        printf("string比较5000000次所花时间：%dms\n",time2-time1-time3);
    }
    printf("string三项操作所花时间：%dms\n",times);
}
#endif
void testMod() {
    printf("%d\n",21%6);
    printf("%d\n",21%7);
    printf("%d\n",-21%-8);
    printf("%d\n",21%-5);

    printf("%d\n",21/6);
    printf("%d\n",21/7);
    printf("%d\n",-21/-8);
    printf("%d\n",21/-5);

    assert(21/-4==-5);

    assert(34/-5==-6);
}
void testImplicitThis() {
    class B {

        mutable int a;
//    mutable const int a;
    public:
        B():a(0) {}
        void func(B* a) { //int this){

        }
        void func() const {
            a=1;
        }
    };
}
void testInitRef() {
    class B {
        int& ri;
    public:
        B(int i):ri(i) {
            printf("%d\n",ri);
        }
        void func() {
            ri=2;
            printf("%d\n",ri);

        }
    };
    int i=1;
    B b(i);
    b.func();
}
//void testTemplateDeclare(){
template<class Type> class C1 {};
//template<class Type,int size> class C1 {};
//}
void testMemVirtual() {
    class Base {
    public:
        virtual void eval() const {
            printf("base eval\n");
        }
        virtual void func() {
            printf("base func\n");

        }
    };
    class Derived:public Base {
    public:
        virtual void eval() {
            printf("derived eval\n");

        }
        void func() {
            printf("Derived func\n");

        }
    };
    Base* p=new Derived;
    p->eval();
    p->func();

    p->Base::func();
    (p->Base::func)();
    //p->(Base::func)();//xx


    Derived* d=new Derived;
    d->eval();
    d->func();
}
#ifndef _WIN32
namespace TestClassConstStatic {
class Base {
public:
    static const int a=1;
    const static int a2=2;

    static const double d=1.1;
    const static double d2=1.2;

    static const float f=1.1;
    const static float f2=1.2;

    const static std::string str1;
    static const std::string str2;
};
//std::string Base::str1;//="123";
//std::string Base::str2;//="1234";
void testClassConstStatic() {


}
}
#endif

void testClassExplicitInit() {
    class Data {
    public:
        int a;
        double b;
    };
    Data d= {1,1.2};
}
void testPrintfOrder() {
    int a[]= {1,5,7,9,11,13};
    int *p;
    p=a+3;
    printf("%d,%d\n",*p,*p++);

    int arr[]= {6,7,8,9,10};
    int *ptr=arr;
    *(ptr++)+=123;
    printf("%d,%d\n",*ptr,*(++ptr));
}
void testClassTypeConversionOpr() {
    using namespace std;
    class Base {
    public:
        Base() {}
        Base(int a):m_a(a) {}
        Base(double d):m_d(d) {}
        operator int() {
            return m_a;
        }
        operator double() {
            return m_d;
        }
        operator string() {
            return string("abc");
        }
    private:
        int m_a;
        double m_d;
    };
    int a=Base(1);
    printf("%d\n",a);

    double d=Base(10.0);
    printf("%f\n",d);

    string str=Base();
    printf("%s\n",str.c_str());
}
//////////////////////////////
//Macro
//## concat two string in macro scope
#define call(x,y) x##y
void testTwoPondsInMacro() {
    int x=5,y=10,xy=20;
    printf("%d\n",xy+call(x,y));//40
}
//////////////////////////////
void testPrintFloat() {
    float a=3.5f;
//    printf("%d\n",a%3);//编译不过
//    printf("%d\n",3.5%3);//编译不过
}
void testFloatComparision() {
    float a=5.5f;
    if(a==5.5f) {
//    if(a==5.5){
        printf("equal\n");//ok
    } else {
        printf("not equal\n");
    }
}
//What happened when negative value is assigned to unsigned int
void testNegtiveUnsignedInt() {
    unsigned int a=5;
    int b=-20;
    (a+b)>6?printf(">6\n"):printf("<=6\n");
}
namespace MoreEffective {
class BST {

};
ostream& operator<<(ostream& s,const BST& bst) {
    s<<"bst\n";
    return s;
}
class BalancedBST: public BST {
    int m_i;
};
void printBSTArray(ostream& s,
                   const BST array[],
                   int numElements) {
    for(int i = 0; i < numElements; i++) {
        s << array[i];          //假设BST类
    }                         //重载了操作符<<

}
void test1() {
    BST BSTArray[10];
    printBSTArray(cout, BSTArray, 10);          // 运行正常

    BalancedBST bBSTArray[10];
    printBSTArray(cout, bBSTArray, 10);         // 还会运行正常么？


}
}

void test20() {
    struct A {
        signed a:1;
        unsigned b:1;
        signed c:2;
        unsigned d:2;
    };
    A a;
    unsigned int* i=(unsigned int*)&a;
    *i=0x3f;
    printf("%d\n%d\n%d\n%d\n",a.a,a.b,a.c,a.d);
    //-1 1 -1 3

}
void testWprintf() {
//            setlocale(LC_ALL,"zh_CN.gb2312");
//    setlocale(LC_ALL,"zh_CN.gbk");
//    setlocale(LC_ALL,"zh_CN.utf8");
//    wchar_t wstr[] = L"中文";
////    setlocale(LC_ALL, "zh_CN.UTF-8");
//    wprintf(L"%s ",wstr);
//    wprintf(L"%ls ",wstr);
    ///////////////

//    const wchar_t* p=L"测试数据";
//    wprintf(L"%ls\n",p);
//    wprintf(L"%s\n",p);
//    wprintf(L"%S\n",p);

}
void test21() {
    class B {
    public:
        void func() {}
    private:
        void func2() {}
    };
    class D:B {
    public:
        void print() {
            func();
//            func2();
        }
    };
    D d;
    d.print();
    class E {
    public:
    private:
        ~E() {}
    };
    //E e;
    //d.func();
}
void testStringLib() {
    using namespace std;
    string s("hello");
    //s.push_back('\0');
    s.push_back('\0');
    //or s.insert(s.end(),'\0');
    s+="fucing world!";
    cout<<s<<endl;

}
void testIncrese() {
    int x=2;
    int a=(++x)*(++x);
    printf("%d\n",a);//16
    x=2;
    int b=(x++)*(x++);

    printf("%d\n",b);//4

    x=2;
    int c=(++x)++;
    printf("%d\n",c);//3
    //test22();

    x=3;
    int d=(x++)+(++x)+(x++);
    printf("%d\n",d);//3

}
void testStructPtrUsage() {
    struct ST {
        char* name;
    } a,*p;
    p=&a;
    *p->name=0;
    (*p).name=0;
}
void test24() {
    struct ST {
        char a1;
        char a2;
        char a3;
        char a4;
        char a5;
        char a6;
    };
    printf("%d\n",sizeof(ST));
    ST A[6][8];
    printf("%d\n",sizeof(A));
    printf("%x\n",&A);
    printf("%x\n",&A[5][7]);
    printf("%d\n",10000+((ST *)&A[5][7]-(ST *)&A)*sizeof(ST));
    printf("%d\n",10000+((ST *)&A[1][4]-(ST *)&A)*sizeof(ST));
}
void test25() {
//    printf("0x%x", (&0)[-1]);
}
void test26() {
    int m=5;
    if(m++>5)
        printf("%d\n", m);
    else printf("%d\n", --m);
}
//define的副作用
void test27() {
#define SQR(x) x*x
    int a=10;
    int k=2;
    int m=1;
    a/=SQR(k+m)/SQR(k+m);
    printf("%d\n",SQR(k+m)/SQR(k+m));
    printf("%d\n",a);
}
void test28() {
    unsigned short a=65535;
    unsigned short b=10;
    unsigned short c=a+b;
    printf("%d\n",c);
}
void test29() {
    int a[10]= {};
    printf("%d\n",a[9]);
    int b[]= {};
    int n=sizeof(b)/sizeof(int);
    printf("%d\n",n);
}
void testArrayOfRef() {
//        int a;
//    int& b=a;
//    int& c[4];//xxx
}
void test0Array() {
    int a[0];
}
namespace AA {
class C {
    friend void f(const C&) {
    }
};
}
void test30() {

    AA::C cobj;
    f(cobj);
//    AA::f(cobj);


}
void test31() {
    class B {
    protected:
        int m_a;
    };
    class D: public B {
    public:
//    protected:
        using B::m_a;
    };
    D d;
    printf("%d\n",d.m_a);

}
void test32() {
    enum Animal {Cat,Dog};
    Animal a;
    printf("%d\n",a);
    printf("%x\n",a);
    printf("%d\n",Cat);
//    printf("%d\n",&Cat);
//    printf("%x\n",Animal);
}
void test33() {
    class B {
    public:
        virtual ~B() {}
        short a;
        int b;
        char c;
    };
    printf("%d\n",sizeof(B));
}
int g_a2;
void test34() {
    const int a=1;
    //只能转换指针或引用
    //int b=const_cast<int>(a);
}





void testZTE() {
    int p[6][4];

    printf("%d,%d,%d\n",p,p+1,(&p)+1);
    //
    char str[]="ZTE CORP";
    char *p2=str;
    int n;
    //!表示一个字符的大小
    printf("%d\n",sizeof(*p2));
}
/**
在C中也可以用常量作为数组的大小参数
**/
void testConstAsArraySize() {
    const int size=10;
    char a[size];
    //
    //!No need type in C, can be compiled in gcc
//    const bufsize=100;
//    char buf[bufsize];
//    printf("%d\n",sizeof(buf));
}
inline fac(float i) {
    return i*i;
};
void testInline() {
    printf("%d\n",fac(8));
}
void testEmptyClass() {
    struct A {};
    struct A a,b;

//??gcc下为0？
    printf("%d\n",sizeof(struct A));
    printf("%x\n",&a);
    printf("%x\n",&b);
}
//C中不能重载函数！！
//void overrideFunc(int a){
//}
//void overrideFunc(int a,int b){
//}
//char *p=(char*)malloc(10);
int foo(int x, int n) {
    int val = 1;
    if(n > 0) {
        if(n % 2 == 1) val *= x;
        val *= foo(x * x, n / 2);
    }
    return val;
}
void testExp() {
    int a, b, c, d;
    a = 3;
    b = 5;
    c = a, b;
    d = (a, b);

    printf("c=%d  ", c);
    printf("d=%d\n", d);

//这个其实有两个C语言知识点，一个是等号操作符优先级高于逗号操作符，另一个是逗号操作符相当于运算逗号前半部后半部的表达式，然后返回后半部表达式的值。所以c等于a（先计算等号），而d等于b（逗号表达式返回b）。
}

////////////////////////
//declare/invoke func in func
void testDeclareFuncInFunc() {
    void declareFunc(int);
    declareFunc(1);
}
void declareFunc(int n) {
    printf("%d\n",n);
}
////////////////////////
//???recursive exercise
void test42() {
    void e(int);
    int a = 3;
    e(a);
}
void e(int n) {
    if(n > 0) {
        e(-n);
        printf("%d ", n);
        e(-n);
    }
}
////////////////////////
inline void testInline2() {
    printf("hello\n");
}
inline void testInline3() {
    testInline2();
}
//char* gadfasdg=malloc(10);



//\main.c|24|error: `globalChar' undeclared (first use in this function)|
//void testBeforeGlobalVar2(){
////        extern char globalChar;
//    printf("%c\n",globalChar);
//}
void testBeforeGlobalVar() {
    extern char globalChar;
    printf("%c\n",globalChar);
    extern void globalFunc();
    globalFunc();
}
char globalChar='a';
void globalFunc() {
    printf("Global Func\n");
}
void testAfterGlobalVar() {
    //这里只声明，其值已经在外部变量声明时初始化
    extern char globalChar;
    printf("%c\n",globalChar);

}
void testAfterGlobalVar2() {
    //这里只声明，其值已经在外部变量声明时初始化
    char globalChar;
    printf("%c\n",globalChar);
//    printf("%c\n",::globalChar);
}
//??
//power(base,n)
//int base,n;
//{
//
//    return 0;
//}
void testRegisterVar() {
    register int x;
}





/////////////////////////////////////
//External functions
extern void test2DArrayInC();
extern void test2DArrayInCPP();


//标准中没有main()的形式（无没有传入参数的形式）
int main(void) {
    test2DArrayInCPP();
//    test2DArrayInC();


//    int a;
//    int &b=a;
//    const int a=10;
//    int b[a];
//    printf("%d\n",b[0]);
//    int a[3];
//    int b=2[a];
    //对inline函数取地址
//    printf("%x\n",testInline3);
//    printf("%x\n",testInline2);
//    testInline3();
//    testInline2();
//    int a=-128;
//    unsigned int b=128;
//    printf("%d,%d\n",(a>>1),(b>>1));

//    printf("%d\n",NAN);
//    test4();
//    testExp();
//    testArray3();
//    printf("%d\n",foo(2,3));
//    printf("%d\n",foo(2,4));
//    printf("%d\n",foo(3,3));
//    printf("%d\n",foo(3,4));
//    testStruct();
//    test4();
//    char* p="abc";
//char a{ [3] }= "abc";
    //p[0]='d';wrong!!
//    testEmptyClass();
//    testInline();\
//inline fac(float i)(return i*i);
//    testConstAsArraySize();
//    testVariableArgs();
//    testIO();
    //
//    testBitField();
//    testUnionType();
//    testTypedef();
//    testTableList();
//testStruct();
//    testDCL();
//testUnDCL();
//    testComplicateType();
//    testQuicksort();
//    testPointerArray();
//    testArrayPointer();
//    testNegativeIndexArray();
//    testPointer();

//    testUnkownTypeOpr();
//    testMarco();
//    testDeclareFuncInFunc();
//testExternVarScope();
//testRegisterVar();
//FuncCalc::testFuncCalc();
//    polishCalculator();
//    testTimeHeader();
//    testset::testSet();
    //
//    testStdlibHeader();
    //
//    testCh03();
//    testCh04();
    //
//    testMathHeader();
    //
//    testRandom();
    //

//    testCtypeHeader();
//    testCh02();
    //
//    long double d=1.234L;
    //
//    testFloatHeader();
//testLimits();
//    printf("%d\n",sizeof(long double));
//    printf("%d\n",sizeof(double));
//    printf("%d\n",MAXLONG);
//    printf("%d\n"MINLONG);
//    printf("%d\n",MAXINTATOM);
//    testBeforeGlobalVar();
//    testAfterGlobalVar();
//    testAfterGlobalVar2();
//    power(0,0);
//    char a=-1;
//    printf("%d\n",a);
//printArbitaryLongLine();
//testCh01();
//    double a=1.23;
//        printf("%.0f\n",a);
//    printf("%d\n",EOF);
//printf("%d\n",getchar()!=EOF);
//    testStruct();
//if(true){
//
//    printf("abc\n");
//}

//    int a=1;
//    int &r=a;
//    printf("Hello world!\n");

//    test34();
//        int e;
//    int &f=e;
//    static int a;
//    printf("%d\n",a);
//    printf("%d\n",g_a2);
//    test33();
//    test32();


//    test28();
//    test24();
//testIncrese();
    //    testWprintf();

//    test20();
//    MoreEffective::test1();
//    int volatile a=1;
//    int b=a;
//    int a=1+"2";
//    printf("%d\n",a);
//    test3();
//    test4();
//    test3();
//    test2();
//    test();

//    class B{
//        public :
//
//    };
//    class D:virtual public  B{
////    class D:public virtual B{
//    };
//    int a=CONST_INT_VALUE;
//    testClassTypeConversionOpr();

//    std::vector<int> c1;
//    std::vector<vector<int> > c2;
//    std::vector c2(c1);
//    testPrintfOrder();
//    enum a {x1,x2,x3=10,x4,x5,} x;
//    printf("%d\n",x);
    //printf("%d\n",x1);



//    int a[2][2]={{1},{2,3}};
//    printf("%d\n",a[0][1]);
//    float a=1.0;
//    switch(a){
//        case 1:
//        break;
//    }
//    TestClassConstStatic::testClassConstStatic();
//    testMemVirtual();
//    testInitRef();
//    static int i=2;
//    if(i==0){
////        getchar();
//        return 0;
//    }
//    i--;
//    main();
//    string s2;
//    cout<<s2[0]<<endl;
//    string s;
//    cout<<s[0]<<endl;
//    const int* pci=new const int[100](0);
//    const int* pci=new const int[100]();
//    for(int i=0;i<100;++i){
//        printf("%d ",pci[i]);
//    }
//    printf("\n");
//    testCharAndString();
//    testCStyleAndString();
//    testMod();
//    testFor();
//    testGoto();
//    testImplicitCast();
//    testMemOverlapped();
//    memcpy();

//    int a[10];
//    char b[10];
//    testArrayToPtr(a,b);
//    printf("%x\n",testArrayToPtr);
//    function(10);
//int n;
//scanf("%d",&n);
//int c[n];
//int *d=(int*)malloca(12);
    //printf("%d\n",nonReturnValueFunc());
//    testConstClassFunction();
//    testOnExit();
//testConstPtrAndPtrConst();


//    B* b2=(B*)malloc(sizeof(B));
    // b2->B::B();

//    double b;
//    const double const &d=1;//会显示重复的const，只要有一个即可
//    const double &pb=b;
    //也可写成
//    double const &pb2=b;

//int a;

//    class test3 t;
//    void test3(const int& );
//    test3(a);
//    int test3;


//    test3(1);
//    B* b=new B;
//    b->~B();
//    const int a=1;
//    int c=2;
//    const int *d=&c;
//
//    test2(a,c,d,d);
//    test1();

//    b.Print()

//    testFloat();
    //
//    double d=0.0;
//    if(d==0.0){
//        printf("%f\n",d);
//    }
//    std::list<A*> classList;
//    A *a=new A;
//    classList.push_back(a);
//    std::list<A*>::iterator itr=classList.begin();
//    int b=*itr->a;
//    int c=(*itr)->a;






//    testset::testHashSet();
//    LinkKnowledge::test();
//    Interview::test();
//    Sort::testQuicksort();
//
//    BoostTest::testSuite();
//    ArrayPointer::test();
//    DataConverter::testDataConverter();
//    MyStringOpr::testStrcat();
//    MyStringOpr::testStrend();
//    MyStringOpr::testNStringOpr();

//    testBoost();
//    testDifFun();
//    testManOrBoy();
//    testAlgorithm();
//    test_alloc();
//    double minimum = Min(8, 1, 4);
//    testMemory();
//    testUtility();
//    testitr1();
//    testset::testSet();
//    testClimits();
//    testCin();
//    fn5();

//    testStruct();
//    test1();
//testClass();
//testStudent();
//testCh12_15();
//testSet();

//    test23();
//    printf("%d\n",140%3);
//    char p = {"a", "b", "c", "d", "e"};
//    printf("%d\n", sizeof(p));




//    test22();
//    test14();

    //test13();
    //test12();

//        class D:public virtual Base{
////    class D:private Base{
////    class D:protected Base{
//        public:
//        void func(){
////            int b=a;
//        }
//    };
//    class E:public D{
//        void func(){
//            int b=a;
//        }
//    };
//    int c;
//    int *b=&c;
//    int *&d=b;
////    int &*e=b;
//    const int*a=b;
//    int f[5];
//    func(f);
//    func(f);
//    testConstChar();

//    testTypeid();
//    testPrintFixedWidth();
//    string s[]={string("a"),string("b")};
//    int b[0];
////    double calc();
////    double calc=calc();
//    std::string s;
////    s[0]='a';
//    cout<<s[0]<<endl;
//    int __A;
//    bool a=1 and 2;
//    printf("%d\n",sizeof(long double));
    //printf("%d\n",sizeof(bool));
//    testLexicographicalCompare();
//    test10();
    //test9();
//    test8();
//    test7();



//    char *g="String";
//    myalloc(g,20);
//    strcpy(g,"Oldstring");
//    printf("The string is %s",g);
    //printf("%d\n",sizeof(S1));
    //testLittleEndian();

    //wchar_t str;//="abc";
//    test5();
//    test4();
//    double(*)() *e2[9];

//    typedef double(**e2[9])();


//    test3();
//    double(*e[9])();
//    e[0]=f1;
//    e[0]();

//    doube(*)() (*e)[9];
//    test2();
//    cout<<strlen("abc")<<endl;
//    cout<<checkCPU()<<endl;
//    cout<<hex<<getFullOneBitMask()<<endl;
//    testUnsignedInt();
//    testAddrCast();
//    testUnsignedCalc();
//    testClassMemberInit();
//    testDupElements();
//    testVectorPtr();
//    calcProbability();

//////////////////////////////////

//system("pause");

#ifdef _WIN32
//    getchar();
#endif
    return 0;
}
