#include <iostream>

using namespace std;
class A {
public:
    void foo() {
        cout<<"A::foo()\n";
    }
};
class A2 {
public:
    void foo() {
        cout<<"A2::foo()\n";
    }
};
class D:public A,public A2 {
};

int testNameConflictFromMultiInherit() {
    D d;
    //±àÒëÊ±»á±¨´í
//    d.foo();
//    d.A::foo();
//    d.A2::foo();
//    cout << "Hello world!" << endl;
    return 0;
}
