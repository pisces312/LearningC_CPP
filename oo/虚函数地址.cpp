#include <iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include <memory.h>
//////////////////////////////////////////////////
//ǰ������class��struct����
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
    //����������
    int (C::*offset)=&C::a;
//���ڴ��������һ��������ƫ����Ϊ4
    printf("%d\n",offset);
    //
    //
    int (A::*ptr1)=&A::a;
//û�������Ϊ0
    printf("%d\n",ptr1);
    //��ʵ������
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
