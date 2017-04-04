#ifndef TUTILITY_H_INCLUDED
#define TUTILITY_H_INCLUDED
#include<assert.h>
#include<iostream>
#include<utility>
using namespace std;
//���ڲ���rel_ops����
class Int{
    public:
    Int(int v):val(v){}
    //!����ֻ���Լ�ʵ���������ؼ��ɣ�ʣ�µ���rel_opsĬ��ʵ��
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

    //!����rel_ops
    using namespace std::rel_ops;
    Int a(2),b(3);
    //!�Ȳ����Լ�ʵ�ֵĲ���
    assert(a==a);
    assert(a<b);
    //��rel_opsʵ�ֵ����ֲ���
    assert(a!=b);
    assert(b>a);
    assert(a<=b);
    assert(b>=a);
    cout<<"success\n";
}



#endif // TUTILITY_H_INCLUDED
