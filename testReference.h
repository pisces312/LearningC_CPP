#ifndef TESTREFERENCE_H_INCLUDED
#define TESTREFERENCE_H_INCLUDED
void testReference() {
    double d=1;
    double &rr=d;
    //错误
//    double &rr=1;
    //相当于如下
    double temp;
    temp=double(1);
    double &rr2=temp;
    //
    cout<<rr<<endl;
    cout<<rr2<<endl;

    //指针变量的引用
    int *a;
    int*&p=a;
    int b=8;
    p=&b;
    //这里a指向了b
    cout<<*a<<endl;
    //下面两个量应该相等
    cout<<a<<endl;
    cout<<&b<<endl;
    //无法声明对oid的引用
//    void &c=3;

//不能建立引用的数组
//int a[10];
//int &ra[10]=a;

//对数组可以使用常量指针的引用
    int e[10];
    int *const &re=e;
    re[0]=6;
    cout<<e[0]<<endl;

//!引用本身不是一种数据类型，没有引用的引用，也没有引用的指针
//int aa;
//int &raa=aa;
//int& *pa=&aa;
//!引用不是类型，概念上不产生内存空间，因此引用上的引用不存在
    int cc=2;
    int& rc=cc;
//得到的是cc的地址
    cout<<&rc<<endl;
    cout<<&cc<<endl;

//!有空指针，无空引用




}
void fn(int s) {
    cout<<"value\n";
}
void fn(int &r) {
    cout<<"reference\n";
}
void testAmbiguousOverload() {
    fn(1);//正确
//    int a=2;
//    fn(a);//歧义
}
float temp;
float fn1(float r) {
    temp=r;
    return temp;
}
//不产生副本，直接将变量temp返回给主函数
float& fn2(float r) {
    temp=r;
    return temp;
}
float& fn3(float r) {
    float tt=r;
    float& t=tt;
    return t;
}
float& fn4(float r) {
    float tem=r;
    return tem;
}
void testReference2() {
    float a=fn1(5.0);
//错误： 不能将类型为‘float&’的非 const 引用初始化为类型为‘float’的临时变量
//float& b=fn1(5.0);
    float c=fn2(5.0);//!一般变量可以接收返回的引用
    float& d=fn2(5.0);//!返回的temp是全局变量
    float& e=fn3(5.0);
    float f=fn3(5.0);
    cout<<f<<endl;
    cout<<e<<endl;
    float& g=fn4(5.0);//!在gcc下正确
    cout<<g<<endl;

    fn2(5.0)=4;
    cout<<temp<<endl;
//    testReference();
//    cout << "Hello world!" << endl;
}
//返回堆中变量的引用
void test1() {
    double* pd=new double(10);
    double& rd=*pd;
    cout<<*pd<<endl;
    cout<<rd<<endl;
    //返还堆空间的两种方式
    delete &rd;
    //delete pd
}
/**
当传递参数的类型为指针或引用时，可能所指向的内容修改
保护实参被修改的办法是传递const指针和引用
**/
void fn5(){
    double* a=new double(2.0);
    const double *pd=a;
    double ad=32;
    ad+=*pd;//只能读取！
//    *pd=0;//错误
    cout<<ad<<endl;
    //
    double b=3.0;
    const double &pb=b;
    //也可写成
    //double const &pb=b;
    double sum=0;
    sum+=pb;
//    pb+=2;
    cout<<pb<<endl;

    double const &pc=b;
    cout<<pc<<endl;
//    const double const &d=1;
    double const &d=1;


//const double const &d=b;


}


#endif // TESTREFERENCE_H_INCLUDED
