#include <iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include <memory.h>
//////////////////////////////////////////////////
//前置声明class与struct互换
class C {
public:
    int a;
    double d;
    C():
        a(128),
        d(128.0) {}
    virtual void Print() {
        printf("virtual void Print()\n");
    }
};
class A {
public:
    int a;
};
int testVirtualAddr() {
    //用类名调用
    int (C::*offset)=&C::a;
//由于存在虚表，第一个变量的偏移量为4
    printf("%d\n",offset);
    //
    //
    int (A::*ptr1)=&A::a;
//没有虚表，则为0
    printf("%d\n",ptr1);
    //用实例调用
    A a;
    int *ptr2=&a.a;
    printf("%x\n",&a);
    printf("%x\n",ptr2);
    //
    C c;
    int *ptr3=&c.a;
    printf("%x\n",&c);
    printf("%x\n",ptr3);
    typedef void (C::*CPrintFunc)();
    CPrintFunc funcPtr=&C::Print;
//    void (C::*funcPtr)()=&C::Print;
    printf("%x\n",funcPtr);

    int pos=1;//=reinterpret_cast<size_t>(funcPtr);
//    memcpy(&pos,funcPtr,sizeof(int));
    printf("%d\n",pos);
    C* cPtr=&c;
    (cPtr->*funcPtr)();
//    ((((CPrintFunc**)cPtr)[pos]))(cPtr);
//    c.*funcPtr();

    return 0;
}
