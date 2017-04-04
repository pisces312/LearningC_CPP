#include <iostream>

using namespace std;
typedef void(*Fun)(void);
void printVTable(int *address) {
    int c=0;
    while (*address!=0) {
        //每找到一个虚函数，就执行s

        cout<<address<<endl;
        address++;
        c++;
    }
    cout<<"一共有"<<c<<"个虚函数\n";
}
class Base {
    private:
    virtual void nonPublicMethod() {
        cout << "访问非公共虚函数" << endl;
    }

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
//1）  每个父类都有自己的虚表。
//
//2）  子类的成员函数被放到了第一个父类的表中。（所谓的第一个父类是按照声明顺序来判断的）
class Derive1:public Base {
    virtual void f1() {
        cout << "Derive1::f" << endl;
    }

    virtual void g1() {
        cout << "Derive1::g" << endl;
    }

    virtual void h1() {
        cout << "Derive1::h" << endl;
    }
};
void testFatherAndSonVTable() {
    Derive1 d;
    Fun pFun = NULL;
    int* address=(int*)*(int*)(&d);
//*address为0时，到达虚函数表的末尾
    int c=0;
    while (*address!=0) {
        //每找到一个虚函数，就执行s
        pFun=(Fun)*address;
        pFun();
        cout<<address<<endl;

        address++;
        c++;
    }
    cout<<"一共有"<<c<<"个虚函数\n";

}

void testRunMethorThroughVTable() {
    Base b;

    Fun pFun = NULL;
    cout << "虚函数表地址：" << (int*)(&b) << endl;
    cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

    // Invoke the first virtual function

//使用函数指针访问私有虚函数
    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();
    //(Fun)*((int*)*(int*)(&b)+0);  // Base::f()

    pFun=(Fun)*((int*)*(int*)(&b)+1);  // Base::g()
    pFun();

    pFun=(Fun)*((int*)*(int*)(&b)+2);  // Base::h()
    pFun();
}
class Base1 {

    public:

    virtual void f() {
        cout << "Base1::f" << endl;
    }

    virtual void g() {
        cout << "Base1::g" << endl;
    }

    virtual void h() {
        cout << "Base1::h" << endl;
    }



};



class Base2 {

    public:

    virtual void f() {
        cout << "Base2::f" << endl;
    }

    virtual void g() {
        cout << "Base2::g" << endl;
    }

    virtual void h() {
        cout << "Base2::h" << endl;
    }

};



class Base3 {

    public:

    virtual void f() {
        cout << "Base3::f" << endl;
    }

    virtual void g() {
        cout << "Base3::g" << endl;
    }

    virtual void h() {
        cout << "Base3::h" << endl;
    }

};





class Derive : public Base1, public Base2, public Base3 {

    public:

    virtual void f() {
        cout << "Derive::f" << endl;
    }

    virtual void g1() {
        cout << "Derive::g1" << endl;
    }

};
void testMultiDerive() {
    Fun pFun = NULL;
    Derive d;
    int** pVtab = (int**)&d;

//    cout<<*(&d)<<endl;
    cout << "虚函数表地址：" << (int*)(&d) << endl;
    int* vTable=(int*)(&d);
    cout<<vTable<<endl;
    cout<<vTable+1<<endl;
    cout<<vTable+2<<endl;
    //多重继承时，二维虚表的行结束符也是0
    cout<<*(vTable+3)<<endl;
    //Base1's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);

//因为继承自三个父类，所以有三张虚函数表
//二维数组
    pFun = (Fun)pVtab[0][0];
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);
    pFun = (Fun)pVtab[0][1];
    pFun();
    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);

    pFun = (Fun)pVtab[0][2];
    pFun();
    //Derive's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);

    pFun = (Fun)pVtab[0][3];
    pFun();
    //The tail of the vtable

    pFun = (Fun)pVtab[0][4];

    cout<<pFun<<endl;





    //Base2's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

    pFun = (Fun)pVtab[1][0];

    pFun();



    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

    pFun = (Fun)pVtab[1][1];

    pFun();



    pFun = (Fun)pVtab[1][2];

    pFun();



    //The tail of the vtable

    pFun = (Fun)pVtab[1][3];

    cout<<pFun<<endl;







    //Base3's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

    pFun = (Fun)pVtab[2][0];

    pFun();



    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

    pFun = (Fun)pVtab[2][1];

    pFun();



    pFun = (Fun)pVtab[2][2];

    pFun();



    //The tail of the vtable

    pFun = (Fun)pVtab[2][3];

    cout<<pFun<<endl;

}
/**
注意：在上面这个图中，我在虚函数表的最后多加了一个结点，这是虚函数表的结束结点，
就像字符串的结束符“\0”一样，其标志了虚函数表的结束。这个结束标志的值在不同的编译器
下是不同的。在WinXP+VS2003下，这个值是NULL。而在Ubuntu 7.10 + Linux 2.6.22 + GCC 4.1.3
下，这个值是如果1，表示还有下一个虚函数表，如果值是0，表示是最后一个虚函数表。
**/
void testPrintVTable() {
    Base b;
    Fun pFun = NULL;
    cout << "虚函数表地址：" << (int*)(&b) << endl;
    cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
//    pFun=(int*)*(int*)(&b);
    int* address=(int*)*(int*)(&b);
//*address为0时，到达虚函数表的末尾
    int c=0;
    while (*address!=0) {
        //每找到一个虚函数，就执行s
        pFun=(Fun)*address;
        pFun();
        cout<<address<<endl;

        address++;
        c++;
    }
    cout<<"一共有"<<c<<"个虚函数\n";
}
void testPrintVTableEx() {
    //一个继承自三个父类的实例
    Derive d;
//Base d;
    cout << "虚函数表地址：" << (int*)(&d) << endl;

//    int* vTable=(int*)(&d);
//int* vTable=&d;
//        cout<<vTable<<endl;
//    cout<<vTable+1<<endl;
//    cout<<vTable+2<<endl;
    //多重继承时，二维虚表的行结束符也是0
//    cout<<*(vTable+3)<<endl;
    int** pVtab = (int**)&d;
    //pVtab[0]==pVtab[0][0]
    cout<<pVtab[0][0]<<endl;
//    cout<<pVtab[1][0]<<endl;
//    cout<<pVtab[2][0]<<endl;
//    cout<<pVtab[3][0]<<endl;
//    cout<<pVtab[4][0]<<endl;
//    cout<<*pVtab[3]<<endl;
    //
//    int c=0;
//    while (*pVtab[c]!=-1) {
//        cout<<pVtab[c]<<": ";
//        int i=0;
//        int* address=(int *)pVtab[c][i];
////*address为0时，到达虚函数表的末尾
//        while (*address!=0) {
//            //每找到一个虚函数，就执行s
////            pFun=(Fun)*address;
////            pFun();
//            cout<<"->"<<address;
//            i++;
//            address=(int *)pVtab[c][i];
//        }
//        cout<<endl;
//        c++;
//    }
//    cout<<"一共有"<<c<<"个虚函数\n";
    //多重继承时，二维虚表的行结束符也是0
//    int c=0;
//    while (*vTable!=0) {
//        cout<<vTable<<": ";
//        int* address=(int*)vTable;
////*address为0时，到达虚函数表的末尾
//
//        while (*address!=0) {
//            //每找到一个虚函数，就执行s
////            pFun=(Fun)*address;
////            pFun();
//            cout<<"->"<<address;
//
//            address++;
//            c++;
//        }
//        cout<<endl;
//        vTable++;
//    }
//    cout<<"一共有"<<c<<"个虚函数\n";
}
//
//
class CBase {
    public:
    virtual void fun1() {
        cout<<"CBase::fun1"<<endl;
    }
    virtual void fun2() {
        cout<<"CBase::fun2"<<endl;
    }
};
//typedef void (*fun)();

int GetLengthofVTable() {
    int iLength = 0;
    CBase b;
    //也可
//    Fun* pAddr = (Fun*)*(int*)(&b);
    int* pAddr = (int*)*(int*)(&b);
//    Fun* pAddr = (Fun*)*(int*)(&b);
    while (*pAddr != NULL) {
//        (*pAddr)();
        cout<<iLength<<endl;
        ++iLength;
        pAddr++;
    }
    return iLength;
}
int testViewVTableMain() {
    cout<<"长度"<<GetLengthofVTable()<<endl;
//    testPrintVTableEx();
//    testFatherAndSonVTable();
//    testMultiDerive();
//    testPrintVTable();

    //cout << "Hello world!" << endl;
    return 0;
}
