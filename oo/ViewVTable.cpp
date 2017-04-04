#include <iostream>

using namespace std;
typedef void(*Fun)(void);
void printVTable(int *address) {
    int c=0;
    while (*address!=0) {
        //ÿ�ҵ�һ���麯������ִ��s

        cout<<address<<endl;
        address++;
        c++;
    }
    cout<<"һ����"<<c<<"���麯��\n";
}
class Base {
    private:
    virtual void nonPublicMethod() {
        cout << "���ʷǹ����麯��" << endl;
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
//1��  ÿ�����඼���Լ������
//
//2��  ����ĳ�Ա�������ŵ��˵�һ������ı��С�����ν�ĵ�һ�������ǰ�������˳�����жϵģ�
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
//*addressΪ0ʱ�������麯�����ĩβ
    int c=0;
    while (*address!=0) {
        //ÿ�ҵ�һ���麯������ִ��s
        pFun=(Fun)*address;
        pFun();
        cout<<address<<endl;

        address++;
        c++;
    }
    cout<<"һ����"<<c<<"���麯��\n";

}

void testRunMethorThroughVTable() {
    Base b;

    Fun pFun = NULL;
    cout << "�麯�����ַ��" << (int*)(&b) << endl;
    cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) << endl;

    // Invoke the first virtual function

//ʹ�ú���ָ�����˽���麯��
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
    cout << "�麯�����ַ��" << (int*)(&d) << endl;
    int* vTable=(int*)(&d);
    cout<<vTable<<endl;
    cout<<vTable+1<<endl;
    cout<<vTable+2<<endl;
    //���ؼ̳�ʱ����ά�����н�����Ҳ��0
    cout<<*(vTable+3)<<endl;
    //Base1's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);

//��Ϊ�̳����������࣬�����������麯����
//��ά����
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
ע�⣺���������ͼ�У������麯������������һ����㣬�����麯����Ľ�����㣬
�����ַ����Ľ�������\0��һ�������־���麯����Ľ��������������־��ֵ�ڲ�ͬ�ı�����
���ǲ�ͬ�ġ���WinXP+VS2003�£����ֵ��NULL������Ubuntu 7.10 + Linux 2.6.22 + GCC 4.1.3
�£����ֵ�����1����ʾ������һ���麯�������ֵ��0����ʾ�����һ���麯����
**/
void testPrintVTable() {
    Base b;
    Fun pFun = NULL;
    cout << "�麯�����ַ��" << (int*)(&b) << endl;
    cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) << endl;
//    pFun=(int*)*(int*)(&b);
    int* address=(int*)*(int*)(&b);
//*addressΪ0ʱ�������麯�����ĩβ
    int c=0;
    while (*address!=0) {
        //ÿ�ҵ�һ���麯������ִ��s
        pFun=(Fun)*address;
        pFun();
        cout<<address<<endl;

        address++;
        c++;
    }
    cout<<"һ����"<<c<<"���麯��\n";
}
void testPrintVTableEx() {
    //һ���̳������������ʵ��
    Derive d;
//Base d;
    cout << "�麯�����ַ��" << (int*)(&d) << endl;

//    int* vTable=(int*)(&d);
//int* vTable=&d;
//        cout<<vTable<<endl;
//    cout<<vTable+1<<endl;
//    cout<<vTable+2<<endl;
    //���ؼ̳�ʱ����ά�����н�����Ҳ��0
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
////*addressΪ0ʱ�������麯�����ĩβ
//        while (*address!=0) {
//            //ÿ�ҵ�һ���麯������ִ��s
////            pFun=(Fun)*address;
////            pFun();
//            cout<<"->"<<address;
//            i++;
//            address=(int *)pVtab[c][i];
//        }
//        cout<<endl;
//        c++;
//    }
//    cout<<"һ����"<<c<<"���麯��\n";
    //���ؼ̳�ʱ����ά�����н�����Ҳ��0
//    int c=0;
//    while (*vTable!=0) {
//        cout<<vTable<<": ";
//        int* address=(int*)vTable;
////*addressΪ0ʱ�������麯�����ĩβ
//
//        while (*address!=0) {
//            //ÿ�ҵ�һ���麯������ִ��s
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
//    cout<<"һ����"<<c<<"���麯��\n";
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
    //Ҳ��
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
    cout<<"����"<<GetLengthofVTable()<<endl;
//    testPrintVTableEx();
//    testFatherAndSonVTable();
//    testMultiDerive();
//    testPrintVTable();

    //cout << "Hello world!" << endl;
    return 0;
}
