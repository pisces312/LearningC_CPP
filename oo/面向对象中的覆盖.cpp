#include <iostream>
//覆盖即重写，ovveride，实现基类的virtual
//多态的实现
using namespace std;
void tesetOverride() {
    class A {
    public:
        void virtual f() {
            cout<<"A\n";
        }
    };
    class B:public A {
    public:
        void virtual f() {
            cout<<"B\n";
        }
    };
    A *pa=new A();
    pa->f();
    B *pb=(B*)pa;
    pb->f();
    delete pa,pb;
    //
    pa=NULL;
    pb=NULL;
    //
    pa=new B();
    pa->f();
    pb=(B*)pa;
    pb->f();
}
