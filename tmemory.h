#ifndef TMEMORY_H_INCLUDED
#define TMEMORY_H_INCLUDED
#include<assert.h>
#include<iostream>
#include<memory>
#include<new>
using namespace std;

//�Զ������ͣ������Ķ�
typedef allocator<float> Myal;
//���һ��������
Myal get_al() {
    return (Myal());
}
//
void test_alloc() {
    float fl;
    Myal::size_type *p_size=(size_t *)0;
    Myal::difference_type *p_val=(ptrdiff_t *)0;
    Myal::pointer *p_ptr=(float **)0;
    Myal::const_pointer *p_cptr=(const float **)0;
    Myal::reference p_ref=fl;
    Myal::const_reference p_cref=(const float&)fl;
    Myal::value_type *p_dist=(float *)0;
    //???
    Myal::rebind<int>::other::pointer *p_iptr=(int **)0;
    Myal al0=get_al(),al(al0);
    //
    allocator<void>::pointer *pv_ptr=(void **)0;
    allocator<void>::const_pointer *pv_cptr=(const void **)0;
    allocator<void>::value_type *pv_dist=(int **)0;
    //
    Myal::rebind<int>::other::pointer *pv_iptr=(int **)0;

    allocator<void> alv0,alv(alv0);
    alv=alv0;
    //ȡ��ַ
    float *pfl=al0.address(fl);
    assert(pfl==&fl);
    //����ռ䣬��ֵ��ʼ�������죩
    //��������float�Ŀռ�
    pfl=al.allocate(3,0);
    al.construct(&pfl[2],2.0f);
    assert(pfl[2]==2.0F);
    //
    al.destroy(pfl);
    al.deallocate(pfl,1);
    assert(0<al0.max_size());
    //ÿ������ֻ��һ������������
    assert(al0==al);
    assert(!(al0!=al));
    //������ٲ������
    al.destroy(pfl);
    al.deallocate(pfl,1);


}
//
//
//size_t��ʾ�޷������ͣ�����ͳ�ƴ����Ķ���ĸ���
static size_t cnt;
class Myint {
    public:
    Myint(int x):val(x) {
        printf("cnt++\n");
        ++cnt;
    }
    Myint(const Myint& x):val(x.val) {
        printf("cnt++\n");
        ++cnt;
    }
    ~Myint() {
        --cnt;
    }
    int get_val() const {
        return (val);
    }
    private:
    int val;
};
//����uninitialized copy and fill
void test_uninit() {
    cnt=0;
    //??
//    Myint *p=new Myint[6];
//!operator new�ǲ���������new�ǹؼ��֣���
//!ǰ��ֻ�����ڴ�ռ䣬��ִ�й��캯��
    Myint *p=(Myint*)operator new(6*sizeof(Myint));
    //��p��p+2��λ��֮���Ԫ�ر����3��������ҿ�[ )
    uninitialized_fill(p,p+2,3);
    //�ж�����ֵΪ3�������������
    assert(p[1].get_val()==3&&cnt==2);
    //��p+2��λ�ÿ�ʼ��������Ԫ�ظ�ֵΪ5������ǰ������2������ʱΪ4��
    uninitialized_fill_n(p+2,2,5);
    assert(p[3].get_val()==5&&cnt==4);
    //uninitialized_copy���ص���Ŀ��Ԫ�ص����һ��Ԫ�صĺ�һ��λ��
    assert(uninitialized_copy(p+1,p+3,p+4)==p+6);
    cout<<(p+5)->get_val()<<endl;
    //����p+6��һ��δ�����λ��
    cout<<(p+6)->get_val()<<endl;
    assert(p[4].get_val()==3&&cnt==6);
    assert(p[5].get_val()==5);
    operator delete(p);
//    delete(p);
}
//������ʱ����
void test_tempbuf() {
    //���ص�pair�ĵ�һ���������ڴ�ռ��ָ�룬�ڶ��������뵽�Ĵ�С
//    ptrdiff_t len=5;
//    pair<short*,ptrdiff_t> tbuf=get_temporary_buffer(ptrdiff_t(5));
//!get_temporary_buffer��ʹ����Ҫ�Ӳ���<short>����pair�ĵ�һ������
    pair<short*,ptrdiff_t> tbuf=get_temporary_buffer<short>(5);
//???ptrdiff_t
//pair<short*,int> tbuf=get_temporary_buffer(5);
    assert(tbuf.first!=0&&tbuf.second==5);
    //
    typedef raw_storage_iterator<short*,short> Rit;
    //ָ�����ͣ���ʵ��ֵ�޹أ�Ҫ��ֻ������
    //!???��iter_type��element_type
    Rit::pointer *p_iter=(short **)0;
    Rit::value_type *p_elem=(short *)0;
//    Rit::iter_type *p_iter=(short **)0;
//    Rit::element_type *p_elem=(short *)0;
    //
    Rit it(tbuf.first);
    //ʹ�����������Ϊ���渳ֵ
    for (int i=0;i<5;++i) {
        *it++=i;
        assert(tbuf.first[i]==i);
    }
    //ͨ��ָ���ͷŻ���
    return_temporary_buffer<short>(tbuf.first);

}
void test_autoptr() {
    //���㣬���¿�ʼͳ��
    cnt=0;
    typedef auto_ptr<Myint> Myptr;
    //����Ԫ������
    Myptr::element_type *p_elem=(Myint*)0;
    //
    Myptr p0;
    //��δ��һ������ָ���auto_ptr��ʼ��ʱ�����ڲ�ָ��Ϊ��
    assert(p0.get()==0);
    //
    {
        Myptr p1(new Myint(3));
        Myint *p=p1.get();
        assert(cnt==1);
        assert(p->get_val()==3
               &&(*p1).get_val()==3
               &&p1.release()->get_val()==3
               &&p1.get()==0);
        delete(p);
        assert(cnt==0);
    }
    //
    assert(cnt==0);
    {
        Myptr p2(new Myint(5));
        assert(cnt==1);
    }
    //
    //!����������ͬ��p2��{}���޶��壬������
    assert(cnt==0);
    {
        //!ֻ�ᴴ��һ��Myint����
        //!����auto_ptr<Myint>��Myint
        Myptr p3(new Myint(7)),p4(p3);

        assert(cnt==1);
        //!p3�Ȼ��ָ�룬Ȼ������p3��Ϊp4�����ã�p3����Myint��ָ�봫�ݸ�
        //!p4��Ȼ�������p3ָ��ĳ��У������ʱp3.get()==0
        assert(p3.get()==0&&p4.get()->get_val()==7);
        //p4�ֽ����һ��Myint�����ָ��ĳ���Ȩ���ݸ�p3
        p3=p4;
        assert(p4.get()==0&&p3.get()->get_val()==7);
        //!���
        p3.reset();
        assert(p3.get()==0&&cnt==0);
        //
        p4.reset();
        assert(p4.get()==0);
    }
    assert(cnt==0);
}
//��������
void testMemory() {
    test_alloc();
    test_uninit();
    test_tempbuf();
    test_autoptr();
}

#endif // TMEMORY_H_INCLUDED
