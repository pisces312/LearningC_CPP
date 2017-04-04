#ifndef TUTILITY_H_INCLUDED
#define TUTILITY_H_INCLUDED
#include<assert.h>
#include<iostream>
#include<utility>
using namespace std;
//用于测试rel_ops的类
class Int{
    public:
    Int(int v):val(v){}
    //!这里只需自己实现两种重载即可，剩下的由rel_ops默认实现
    bool operator==(Int x) const{
        return (val==x.val);
    }
    bool operator<(Int x) const{
        return (val<x.val);
    }
    private:
    int val;
};
void testUtility(){
    pair<int,char> p0;
    pair<int,char> p1=p0,p2(3,'a');
    assert(p1.first==0);
    assert(p1.second==0);
    assert(p2.first==3);
    assert(p2.second=='a');
    assert(p2==make_pair((pair<int,char>::first_type)3,(pair<int,char>::second_type)'a'));

    //!测试rel_ops
    using namespace std::rel_ops;
    Int a(2),b(3);
    //!先测试自己实现的操作
    assert(a==a);
    assert(a<b);
    //由rel_ops实现的四种操作
    assert(a!=b);
    assert(b>a);
    assert(a<=b);
    assert(b>=a);
    cout<<"success\n";
}



#endif // TUTILITY_H_INCLUDED
