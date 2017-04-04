#include <iostream>

using namespace std;
class B {
    public:
    int i;
    virtual void vB() {
        cout << "B::vB" << endl;
    }
    void fB() {
        cout << "B::fB" << endl;
    }
};

class D1 : virtual public B {
    public:
    int x;
    virtual void vD1() {
        cout << "D1::vD1" << endl;
    }
    void fD1() {
        cout << "D1::fD1" << endl;
    }
};

class D2 : virtual public B {
    public:
    int y;
    void vB() {
        cout << "D2::vB" << endl;
    }
    virtual void vD2() {
        cout << "D2::vD2" << endl;
    }
    void fD2() {
        cout << "D2::fD2" << endl;
    }
};

class GD :  public D1, public D2 {
    public:
    int a;
    void vB() {
        cout << "GD::vB" << endl;
    }
    void vD1() {
        cout << "GD::vD1" << endl;
    }
    virtual void vGD() {
        cout << "GD::vGD" << endl;
    }
    void fGD() {
        cout << "GD::fGD" << endl;
    }
};
typedef void (*Fun)();

void PrintMember(int *pI) {
    cout << *pI << endl << endl;
}
void PrintVT(int *pVT) {
    while (*pVT != NULL) {
        (*(Fun*)(pVT))();
        pVT++;
    }
}

void PrintMemberAndVT(GD *pGD) {
    int *pRoot = (int*)pGD;

    int *pD1VT = (int*)*(pRoot + 0);
    (*(Fun*)(pD1VT))();
    (*(Fun*)(pD1VT +1))();
    int *pVB = (int*)*(pRoot +1);
    cout << "vbtable's adress:" << *pVB << endl;
    int *pX = (pRoot + 2);
    PrintMember(pX);

    int *pD2VT = (int*)*(pRoot + 3);
    (*(Fun*)(pD2VT))();
    int *pVB2 = (int*)*(pRoot +4);
    cout << "vbtable's adress:" << *pVB2 << endl;
    int *pY = (pRoot + 5);
    PrintMember(pY);

    int *pA = (pRoot + 6);
    PrintMember(pA);

    int *pBVT = (int*)*(pRoot + 7);
    (*(Fun*)(pBVT))();
    int *pI = (pRoot + 8);
    PrintMember(pI);
}
/**
测试虚表
需要在vc下进行！！！
这是由于gcc和vc的虚表结构不同！！！
**/
void TestVT() {
    B *pB = new GD();
    GD *pGD = dynamic_cast<GD*>(pB);
    pGD->i = 10;
    pGD->x = 20;
    pGD->y = 30;
    pGD->a = 40;
    PrintMemberAndVT(pGD);
    delete pGD;
}
void TestDynamicCast() {
    B *pB = new GD();
    GD *pGD = dynamic_cast<GD*>(pB);
    cout << "GD:" << pGD << endl;
    D1 *pD1 = dynamic_cast<D1*>(pB);
    cout << "D1:" << pD1 << endl;
    D2 *pD2 = dynamic_cast<D2*>(pB);
    cout << "D2:" << pD2 << endl;
    cout << "B:" << pB << endl;
}

///////////////////////////////////////////////////////////////////
//
//
///
class Base {

    public:

    virtual void f() {
        cout << "Base::f" << endl;
    }

    virtual void g() {
        cout << "Base::g" << endl;
    }

    virtual void h() {
        cout << "Base::h" << endl;
    }

};
/**
通过对象的地址来取得虚函数表的地址
**/
void testVTableAddr() {
    typedef void(*Fun)(void);

    Base b;

    Fun pFun = NULL;

    cout << "虚函数表地址：" << (int*)(&b) << endl;

    cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
    // Invoke the first virtual function
//调用第一个函数
//通过强行把&b转成int *，取得虚函数表的地址，然后，再次取址就可以得到第一个虚函数的地址了，也就是Base::f()
    pFun = (Fun)*((int*)*(int*)(&b));

    pFun();
}
/**
vs2008 中查看对象布局的部分结果
cl main.cpp /d1reportSingleClassLayoutGD
省略部分。。。
。
。
。
class GD        size(36):
        +---
        | +--- (base class D1)
 0      | | {vfptr}
 4      | | {vbptr}
 8      | | x
        | +---
        | +--- (base class D2)
12      | | {vfptr}
16      | | {vbptr}
20      | | y
        | +---
24      | a
        +---
        +--- (virtual base B)
28      | {vfptr}
32      | i
        +---

GD::$vftable@D1@:
        | &GD_meta
        |  0
 0      | &GD::vD1
 1      | &GD::vGD

GD::$vftable@D2@:
        | -12
 0      | &D2::vD2

GD::$vbtable@D1@:
 0      | -4
 1      | 24 (GDd(D1+4)B)

GD::$vbtable@D2@:
 0      | -4
 1      | 12 (GDd(D2+4)B)

GD::$vftable@B@:
        | -28
 0      | &GD::vB

GD::vB this adjustor: 28
GD::vD1 this adjustor: 0
GD::vGD this adjustor: 0

vbi:       class  offset o.vbptr  o.vbte fVtorDisp
               B      28       4       4 0
               测试虚继承后对象的大小
**/
void testVirtualInheritClassSize() {
    class A {
        char k[3];
        public:
        virtual void aa() {}
    };
    class B:public virtual A {
        char j[3];
        public:
        virtual void bb() {}
    };
    class C:public virtual B {
        char i[3];
        public:
        virtual void cc() {}
    };
    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;
}
/////////////////////////////////////////
/////////////////////////////////////////
void testCommonInheritClassSize() {
    class A {
        char k[3];
        public:
        virtual void aa() {}
    };
    class B:public  A {
        char j[3];
        public:
        virtual void bb() {}
    };
    class C:public  B {
        char i[3];
        public:
        virtual void cc() {}
    };
    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;
}
int testVirtualInheritMain() {
    testVirtualInheritClassSize();
//    testCommonInheritClassSize();
//    testVTableAddr();
//    test2();
//    TestVT();
//    TestDynamicCast();
//    cout << "Hello world!" << endl;
    return 0;
}
