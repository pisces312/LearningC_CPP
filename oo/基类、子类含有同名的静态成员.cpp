//基类、子类含有同名的静态成员
class B {
public:
    static int a;
};
class D:public B {
public:
    static int a;
};
