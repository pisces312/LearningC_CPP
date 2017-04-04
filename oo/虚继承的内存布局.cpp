#include <iostream>

using namespace std;
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

class B1 : virtual public B{
public:
    int ib1;
    char cb1;
public:
    B1():ib1(11),cb1('1') {    }
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

class B2: virtual public B{
public:
    int ib2;
    char cb2;
public:
    B2():ib2(12),cb2('2') {
//        cb='2';
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
typedef void(*Fun)(void);
void testGCC() {
    int** pVtab = NULL;

    Fun pFun = NULL;

    B1 bb1;

    pVtab = (int**)&bb1;

    cout << "[0] B1::_vptr->" << endl;

    pFun = (Fun)pVtab[0][0];

    cout << " [0] ";

    pFun(); //B1::f1();

    cout << " [1] ";

    pFun = (Fun)pVtab[0][1];

    pFun(); //B1::bf1();

    cout << " [2] ";
    pFun = (Fun)pVtab[0][2];
    pFun();
    cout << " [3] ";

    cout << pVtab[0][3] << endl;
    cout << "[1] B1::ib1 = ";
    cout<<(int)pVtab[1]<<endl; //B1::ib1
    cout << "[2] B1::cb1 = ";
    cout<<(char)(int)pVtab[2]<<endl;
//
    cout << "[3] B::_vptr->" << endl;
    pFun = (Fun)pVtab[3][0];

    cout << " [0] ";

    pFun(); //B1::f1();

    cout << " [1] ";

    pFun = (Fun)pVtab[3][1];

    pFun(); //B1::bf1();

    cout << " [2] ";
    cout << pVtab[3][2] << endl;
    cout << "[4] B::ib = ";
    cout<<(int)pVtab[4]<<endl;
    cout << "[5] B::cb = ";
    cout<<(char)(int)pVtab[5]<<endl;

//
    cout << "[6] ";
    pFun = (Fun)pVtab[6];
    pFun();
    cout<<"[7] ";
    //
    //
//    pFun = (Fun)pVtab[7];//[0];
//    pFun = (Fun)pVtab[7];
//    pFun();
//    cout<<pVtab[7]<<endl;
//    cout<<(int)pVtab[7]<<endl;
//    int offset=(sizeof(B1)+sizeof(B2))>>4;
//    pFun=(Fun)(int*)&bb1+offset;

//    pFun();


}
void testVC() {
    int** pVtab = NULL;

    Fun pFun = NULL;

    B1 bb1;

    pVtab = (int**)&bb1;

    cout << "[0] B1::_vptr->" << endl;

    pFun = (Fun)pVtab[0][0];

    cout << " [0] ";

    pFun(); //B1::f1();

    cout << " [1] ";

    pFun = (Fun)pVtab[0][1];

    pFun(); //B1::bf1();

    cout << " [2] ";

    cout << pVtab[0][2] << endl;

    cout << "[1] = 0x";

    cout << (int*)*((int*)(&bb1)+1) <<endl; //B1::ib1

    cout << "[2] B1::ib1 = ";

    cout << (int)*((int*)(&bb1)+2) <<endl; //B1::ib1

    cout << "[3] B1::cb1 = ";

    cout << (char)*((int*)(&bb1)+3) << endl; //B1::cb1

    cout << "[4] = 0x";

    cout << (int*)*((int*)(&bb1)+4) << endl; //NULL

    cout << "[5] B::_vptr->" << endl;

    pFun = (Fun)pVtab[5][0];

    cout << " [0] ";

    pFun(); //B1::f();

    pFun = (Fun)pVtab[5][1];

    cout << " [1] ";

    pFun(); //B::Bf();

    cout << " [2] ";

    cout << "0x" << (Fun)pVtab[5][2] << endl;

    cout << "[6] B::ib = ";

    cout << (int)*((int*)(&bb1)+6) <<endl; //B::ib

    cout << "[7] B::cb = ";
}
int testVIrtualInheritMemLayoutMain() {
    testGCC();
//    cout << "Hello world!" << endl;
    return 0;
}
