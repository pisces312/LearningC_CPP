#include <iostream>

using namespace std;
class A {
public:
    int a;
//    private:
    //�ĸ�C++Ĭ�ϴ����ĺ���
    //�޲ι��캯��
    A(void) {
        cout<<"no parameter construction\n";
    }
//    A(const A &a) {
//        cout<<"copy construction\n";    // ȱʡ�Ŀ������캯��
//    }
    ~A(void) {
        cout<<"destruction\n";    // ȱʡ����������
    }
//    A& operate=(const A &a) {
//        cout<<"assign function\n";
//        return
//    } // ȱʡ�ĸ�ֵ����

};
int testDefaultCtor() {
    A a;
    A b(a);
//    cout << "Hello world!" << endl;
    return 0;
}
