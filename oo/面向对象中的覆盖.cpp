#include <iostream>
//���Ǽ���д��ovveride��ʵ�ֻ����virtual
//��̬��ʵ��
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
