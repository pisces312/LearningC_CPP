#include <iostream>

namespace inheritance_visibility {

using namespace std;

class A {
    void Adefault() {}
public:
    void Apublic() {}
private:
    void Aprivate() {}
protected:
    void Aprotected() {}

};
class BPublicInherit:public A {
public:
    void Bpublic() {}
private:
    void Bprivate() {}
protected:
    void Bprotected() {}
public:
    void test() {
//        Adefault();
        Apublic();
//        Aprivate();
        Aprotected();
    }
};
class BProtectedInherit:protected A {
public:
    void Bpublic() {}
private:
    void Bprivate() {}
protected:
    void Bprotected() {}
public:
    void test() {
//        Adefault();
        Apublic();
//        Aprivate();
        Aprotected();
    }
};
class BPrivateInherit:private A {
public:
    void Bpublic() {}
private:
    void Bprivate() {}
protected:
    void Bprotected() {}
public:
    void test() {
//        Adefault();
        Apublic();
//        Aprivate();
        Aprotected();
    }
};
void test1() {
    BPublicInherit bPublic;
    bPublic.Apublic();
    bPublic.Bpublic();

//    bPublic.Bprivate();
//    bPublic.Bprotected();
//    bPublic.Aprotected();
//
//
    BProtectedInherit bProtected;
//    bProtected.Apublic();
    bProtected.Bpublic();
//
//
    BPrivateInherit bPrivate;
    bPrivate.Bpublic();
}
void test2() {
    class A {
    public:
        int a;
        A():a(1) {}
        void testA() {
            cout<<"a\n";
        }
    };
    class B: A {
    public:
        void test() {
            testA();
            cout<<"B\n";
            cout<<a<<endl;
        }
    };
    B b;
    b.test();
//    b.testA();
}
int testInheritVisibility() {
    test2();
    return 0;
}
}
