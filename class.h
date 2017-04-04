#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <iostream>
using namespace std;

int year;
class Data {
    public:
    int month;
    int year;
    Data(int):a(10),b(month) {
        return;
    }
    Data():a(10),b(month) {};
    void set(int year) {
//        ::year=year;
        switch (year) {
        default:
            break;

        }
    }
    const int a;
    int& b;
    ~Data() {
        cout<<"deallocating...\n";
    }
};
void testAutoDeallocate() {
    Data d;
    Data* d2=new Data;
    delete d2;//如果不加，则不会在程序执行前调用析构

}
/**
基本类型的变量名与某类的类名相同（不是该类的变量的名字，而是类的名字），在类名前加class来声明该类型变量
**/
void func(int Data) {
    class Data data;
    Data++;
    cout<<Data<<endl;
}
/**
类名隐藏了基本类型的变量名，用一般作用域规则即可
**/
int s=0;
void func2() {
    class s {};
    s a;
    ::s=3;
}
Data data;
void Data(Data* data) {
}
void func3() {
    /**
    **类型与非类型不在同一名空间。即在一个作用域中，一个名字可以声明为类型，又可声明为一个非类型，同时出现时，类型名前加前缀，区别非类型名
    **/
    class Data data2;
    Data(0);
}
void testNewAndMalloc() {
    class Data* d=new class Data;
    //需要手动初始化
    class Data* d2=(class Data *)malloc(sizeof(class Data));
    cout<<d2->month<<endl;
}

void testClass() {
    testAutoDeallocate();
//    testNewAndMalloc();u
//    class Data data3(0);
//    cout<<data3.month<<endl;
//    Data data4();
    //
//    cout<<sizeof(Data)<<endl;

    //
//    func(10);
//    func2();
//    func3();

}
class A {
    public:
    A(int j):age(j),num(age+1) {
        cout <<"age:" <<age <<",num:" <<num <<endl;
    }
    protected:
    int num;
    int age;
};

void testCh12_15() {
    A sa(15);
}


class B {
public:
    B() {
        printf("B ctor\n");
    }
    int a;
    //ok
    volatile void func1() {
    }
    //ok
    volatile static void func2() {
    }
    //error
//     static void func3() volatile{
//    }
//ok
    const static void func4() {
    }
    //error
//    static void func4() const {
//    }
    ~B() {
        printf("~B\n");
    }
};


////////////////////////////////////////////
namespace virtual_dtor{
class B {
public:
    B() {
        printf("ctor b\n");
    }
    virtual ~B() {
        printf("dtor b\n");
    }
};
class D :public B {
public:
    D() {
        printf("ctor d\n");
    }
    ~D() {
        printf("dtor d\n");
    }

};
void test() {

    B* d=new D;
    delete d;
}
}
////////////////////////////////////////////

///////////////////////////
namespace how_to_use_static_member{
class C {
public:
    static int a;
    C* GetInstance() {
        printf("GetInstance\n");
        return this;
    }
};
//1. Use "::"
int C::a=0;
void test() {
    C b;
    printf("%d\n",b.a);
//    printf("%d\n",b.GetInstance()->a);
}
}
///////////////////////////

#endif // CLASS_H_INCLUDED
