#ifndef TMEMORY_H_INCLUDED
#define TMEMORY_H_INCLUDED
#include<assert.h>
#include<iostream>
#include<memory>
#include<new>
using namespace std;

//自定义类型，方便阅读
typedef allocator<float> Myal;
//获得一个分配器
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
    //取地址
    float *pfl=al0.address(fl);
    assert(pfl==&fl);
    //分配空间，赋值初始化（构造）
    //分配三个float的空间
    pfl=al.allocate(3,0);
    al.construct(&pfl[2],2.0f);
    assert(pfl[2]==2.0F);
    //
    al.destroy(pfl);
    al.deallocate(pfl,1);
    assert(0<al0.max_size());
    //每个类型只有一个分配器？？
    assert(al0==al);
    assert(!(al0!=al));
    //多次销毁不会出错
    al.destroy(pfl);
    al.deallocate(pfl,1);


}
//
//
//size_t表示无符号整型，这里统计创建的对象的个数
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
//测试uninitialized copy and fill
void test_uninit() {
    cnt=0;
    //??
//    Myint *p=new Myint[6];
//!operator new是操作符，而new是关键字！！
//!前者只分配内存空间，不执行构造函数
    Myint *p=(Myint*)operator new(6*sizeof(Myint));
    //从p到p+2的位置之间的元素被填充3，即左闭右开[ )
    uninitialized_fill(p,p+2,3);
    //判断填充的值为3，且填充了两个
    assert(p[1].get_val()==3&&cnt==2);
    //从p+2的位置开始，将两个元素赋值为5，加上前面填充的2个，这时为4个
    uninitialized_fill_n(p+2,2,5);
    assert(p[3].get_val()==5&&cnt==4);
    //uninitialized_copy返回的是目的元素的最后一个元素的后一个位置
    assert(uninitialized_copy(p+1,p+3,p+4)==p+6);
    cout<<(p+5)->get_val()<<endl;
    //这里p+6是一个未定义的位置
    cout<<(p+6)->get_val()<<endl;
    assert(p[4].get_val()==3&&cnt==6);
    assert(p[5].get_val()==5);
    operator delete(p);
//    delete(p);
}
//测试临时缓存
void test_tempbuf() {
    //返回的pair的第一个参数是内存空间的指针，第二个是申请到的大小
//    ptrdiff_t len=5;
//    pair<short*,ptrdiff_t> tbuf=get_temporary_buffer(ptrdiff_t(5));
//!get_temporary_buffer的使用需要加参数<short>，和pair的第一个参数
    pair<short*,ptrdiff_t> tbuf=get_temporary_buffer<short>(5);
//???ptrdiff_t
//pair<short*,int> tbuf=get_temporary_buffer(5);
    assert(tbuf.first!=0&&tbuf.second==5);
    //
    typedef raw_storage_iterator<short*,short> Rit;
    //指定类型，和实际值无关，要的只是类型
    //!???无iter_type和element_type
    Rit::pointer *p_iter=(short **)0;
    Rit::value_type *p_elem=(short *)0;
//    Rit::iter_type *p_iter=(short **)0;
//    Rit::element_type *p_elem=(short *)0;
    //
    Rit it(tbuf.first);
    //使用输出迭代器为缓存赋值
    for (int i=0;i<5;++i) {
        *it++=i;
        assert(tbuf.first[i]==i);
    }
    //通过指针释放缓存
    return_temporary_buffer<short>(tbuf.first);

}
void test_autoptr() {
    //清零，重新开始统计
    cnt=0;
    typedef auto_ptr<Myint> Myptr;
    //定义元素类型
    Myptr::element_type *p_elem=(Myint*)0;
    //
    Myptr p0;
    //还未用一个对象指针对auto_ptr初始化时，其内部指针为空
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
    //!由于作用域不同，p2在{}外无定义，被销毁
    assert(cnt==0);
    {
        //!只会创建一个Myint对象
        //!区别auto_ptr<Myint>和Myint
        Myptr p3(new Myint(7)),p4(p3);

        assert(cnt==1);
        //!p3先获得指针，然后由于p3作为p4的引用，p3将对Myint的指针传递给
        //!p4，然后放弃对p3指针的持有，因此这时p3.get()==0
        assert(p3.get()==0&&p4.get()->get_val()==7);
        //p4又将其对一个Myint对象的指针的持有权传递给p3
        p3=p4;
        assert(p4.get()==0&&p3.get()->get_val()==7);
        //!清空
        p3.reset();
        assert(p3.get()==0&&cnt==0);
        //
        p4.reset();
        assert(p4.get()==0);
    }
    assert(cnt==0);
}
//测试所有
void testMemory() {
    test_alloc();
    test_uninit();
    test_tempbuf();
    test_autoptr();
}

#endif // TMEMORY_H_INCLUDED
