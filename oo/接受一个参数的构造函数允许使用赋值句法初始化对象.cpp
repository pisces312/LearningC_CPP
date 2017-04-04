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
    C oc=1000;//不能企图加花括号
    oc.show();
    S os=2000;//不能企图加花括号
    os.show();
    return 0;
}
