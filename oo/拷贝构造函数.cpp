#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
//1. 对于一个类X,如果一个构造函数的第一个参数是下列之一:
//a) X&
//b) const X&
//c) volatile X&
//d) const volatile X&
//且没有其他参数或其他参数都有默认值,那么这个函数是拷贝构造函数.
class X {
    public:
    //手工声明了拷贝构造函数，则无参
    X() {}
    //类中可以存在超过一个拷贝构造函数,
    X(X&) {
    }
    X(const X&) {
    }
    X(volatile X&) {
    }
    X(const volatile X&) {
    }
};
struct Test1 {
    Test1() { }
    Test1(int i) {
        id = i;
    }
    Test1(const Test1& test) {
        id = test.id;
    }
    Test1& operator = (const Test1& test) {
        if (this == &test)
            return *this;
        id = test.id;
        return *this;
    }
    int id;
};

class Test2 {
    public:
    Test2() {
        m_pChar = NULL;
    }
    Test2(char *pChar) {
        cout<<"Test2(char *pChar)\n";
        m_pChar = pChar;
    }
    Test2(int num) {
        cout<<"Test2(int num)\n";
        m_pChar = new char[num];
        for (int i = 0; i< num; ++i)
            m_pChar[i] = 'a';
        m_pChar[num-1] = '\0';
    }
    Test2(const Test2& test) {
        cout<<"Test2(const Test2& test)\n";
        char *pCharT = m_pChar;

        m_pChar = new char[strlen(test.m_pChar)];
        strcpy(m_pChar, test.m_pChar);

        if (!pCharT)
            delete []pCharT;
    }
    Test2& operator = (const Test2& test) {
        cout<<"Test2& operator = (const Test2& test)\n";
        if (this == &test)
            return *this;

        char *pCharT = m_pChar;
        m_pChar = new char[strlen(test.m_pChar)];
        strcpy(m_pChar, test.m_pChar);

        if (!pCharT)
            delete []pCharT;

        return *this;
    }
    private:
    char *m_pChar;
};

int tesetCopyCtor(int argc, char* argv[]) {
    const Test1 ts(1); // Test1()
    const Test1* p_ts = &ts;
    const Test1 ts2(ts); //Test(const Test1& test)
    const Test1 ts3 = ts; //Test(const Test1& test)
    Test1 ts4;
    ts4 = ts; //Test1& operator = (const Test1& test)

    Test2 t(5);
    Test2 t2(t);
    Test2 t3 = t2;
    Test2 t4;
    t4 = t;
    return 0;
}

