#include <iostream>

using namespace std;
class A {
public:
    int a;
//    private:
    //四个C++默认创建的函数
    //无参构造函数
    A(void) {
        cout<<"no parameter construction\n";
    }
//    A(const A &a) {
//        cout<<"copy construction\n";    // 缺省的拷贝构造函数
//    }
    ~A(void) {
        cout<<"destruction\n";    // 缺省的析构函数
    }
//    A& operate=(const A &a) {
//        cout<<"assign function\n";
//        return
//    } // 缺省的赋值函数

};
int testDefaultCtor() {
    A a;
    A b(a);
//    cout << "Hello world!" << endl;
    return 0;
}
