#include <iostream>
using namespace std;
class C {
    private:
        int x;
    public:
        C(int idemo) {x=idemo;}
        void show(void) {cout<<x<<endl;}
};
struct S {
    private:
        int x;
    public:
        S(int idemo) {x=idemo;}
        void show(void) {cout<<x<<endl;}
};
int testDirectAssignForSingleMemberClass(int argc, char *argv[]){
    C oc=1000;//������ͼ�ӻ�����
    oc.show();
    S os=2000;//������ͼ�ӻ�����
    os.show();
    return 0;
}
