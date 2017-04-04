#include <iostream>

using namespace std;
/**
也即不使用虚继承的多重继承
**/
class B{

public:

    int ib;

    char cb;

public:

    B():ib(0),cb('B') {}

    virtual void f() {
        cout << "B::f()" << endl;
    }

    virtual void Bf() {
        cout << "B::Bf()" << endl;
    }

};

class B1 : public B

{

public:

    int ib1;

    char cb1;

public:

    B1():ib1(11),cb1('1') {
        cb='1';
    }

    virtual void f() {
        cout << "B1::f()" << endl;
    }

    virtual void f1() {
        cout << "B1::f1()" << endl;
    }

    virtual void Bf1() {
        cout << "B1::Bf1()" << endl;
    }

};

class B2: public B

{

public:

    int ib2;

    char cb2;

public:

    B2():ib2(12),cb2('2') {
        cb='2';
    }

    virtual void f() {
        cout << "B2::f()" << endl;
    }

    virtual void f2() {
        cout << "B2::f2()" << endl;
    }

    virtual void Bf2() {
        cout << "B2::Bf2()" << endl;
    }

};

class D : public B1, public B2

{

public:

    int id;

    char cd;

public:

    D():id(100),cd('D') {}

    virtual void f() {
        cout << "D::f()" << endl;
    }

    virtual void f1() {
        cout << "D::f1()" << endl;
    }

    virtual void f2() {
        cout << "D::f2()" << endl;
    }

    virtual void Df() {
        cout << "D::Df()" << endl;
    }

};
/**
[0] D::B1::_vptr->
 [0] D::f()
 [1] B::Bf()
 [2] D::f1()
 [3] B1::Bf1()
 [4] D::f2()
 [5] 0x1
[1] B::ib = 0
[2] B::cb = B
[3] B1::ib1 = 11
[4] B1::cb1 = 1
[5] D::B2::_vptr->
 [0] D::f()
 [1] B::Bf()
 [2] D::f2()
 [3] B2::Bf2()
 [4] 0x0
[6] B::ib = 0
[7] B::cb = B
[8] B2::ib2 = 12
[9] B2::cb2 = 2
[10] D::id = 100
[11] D::cd = D
第一个父类的虚表
第一个父类的父类变量
。。。向上走
第一个父类的变量
第二个父类的虚表
。。。
自身的变量

存在二义性
**/
void printVTable() {
    typedef void(*Fun)(void);

    int** pVtab = NULL;

    Fun pFun = NULL;

    D d;

    pVtab = (int**)&d;

    cout << "[0] D::B1::_vptr->" << endl;

    pFun = (Fun)pVtab[0][0];

    cout << " [0] ";
    pFun();

    pFun = (Fun)pVtab[0][1];

    cout << " [1] ";
    pFun();

    pFun = (Fun)pVtab[0][2];

    cout << " [2] ";
    pFun();

    pFun = (Fun)pVtab[0][3];

    cout << " [3] ";
    pFun();

    pFun = (Fun)pVtab[0][4];

    cout << " [4] ";
    pFun();

    pFun = (Fun)pVtab[0][5];

    cout << " [5] 0x" << pFun << endl;

    cout << "[1] B::ib = " << (int)pVtab[1] << endl;

    cout << "[2] B::cb = " << (char)(int)pVtab[2] << endl;

    cout << "[3] B1::ib1 = " << (int)pVtab[3] << endl;

    cout << "[4] B1::cb1 = " << (char)(int)pVtab[4] << endl;

    cout << "[5] D::B2::_vptr->" << endl;

    pFun = (Fun)pVtab[5][0];

    cout << " [0] ";
    pFun();

    pFun = (Fun)pVtab[5][1];

    cout << " [1] ";
    pFun();

    pFun = (Fun)pVtab[5][2];

    cout << " [2] ";
    pFun();

    pFun = (Fun)pVtab[5][3];

    cout << " [3] ";
    pFun();

    pFun = (Fun)pVtab[5][4];

    cout << " [4] 0x" << pFun << endl;

    cout << "[6] B::ib = " << (int)pVtab[6] << endl;

    cout << "[7] B::cb = " << (char)(int)pVtab[7] << endl;

    cout << "[8] B2::ib2 = " << (int)pVtab[8] << endl;

    cout << "[9] B2::cb2 = " << (char)(int)pVtab[9] << endl;

    cout << "[10] D::id = " << (int)pVtab[10] << endl;

    cout << "[11] D::cd = " << (char)(int)pVtab[11] << endl;
}
int testDupInheritMemMain() {
    printVTable();
    D d;
//打印来自不同父类的具有相同祖先的类中的变量，不同的继承体系，对同一父类也有不同的值
//同一个类的变量的不同值！！！
    cout<<d.B1::cb<<endl;
    cout<<d.B2::cb<<endl;
//    cout << "Hello world!" << endl;
    return 0;
}
