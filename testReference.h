#ifndef TESTREFERENCE_H_INCLUDED
#define TESTREFERENCE_H_INCLUDED
void testReference() {
    double d=1;
    double &rr=d;
    //����
//    double &rr=1;
    //�൱������
    double temp;
    temp=double(1);
    double &rr2=temp;
    //
    cout<<rr<<endl;
    cout<<rr2<<endl;

    //ָ�����������
    int *a;
    int*&p=a;
    int b=8;
    p=&b;
    //����aָ����b
    cout<<*a<<endl;
    //����������Ӧ�����
    cout<<a<<endl;
    cout<<&b<<endl;
    //�޷�������oid������
//    void &c=3;

//���ܽ������õ�����
//int a[10];
//int &ra[10]=a;

//���������ʹ�ó���ָ�������
    int e[10];
    int *const &re=e;
    re[0]=6;
    cout<<e[0]<<endl;

//!���ñ�����һ���������ͣ�û�����õ����ã�Ҳû�����õ�ָ��
//int aa;
//int &raa=aa;
//int& *pa=&aa;
//!���ò������ͣ������ϲ������ڴ�ռ䣬��������ϵ����ò�����
    int cc=2;
    int& rc=cc;
//�õ�����cc�ĵ�ַ
    cout<<&rc<<endl;
    cout<<&cc<<endl;

//!�п�ָ�룬�޿�����




}
void fn(int s) {
    cout<<"value\n";
}
void fn(int &r) {
    cout<<"reference\n";
}
void testAmbiguousOverload() {
    fn(1);//��ȷ
//    int a=2;
//    fn(a);//����
}
float temp;
float fn1(float r) {
    temp=r;
    return temp;
}
//������������ֱ�ӽ�����temp���ظ�������
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
//���� ���ܽ�����Ϊ��float&���ķ� const ���ó�ʼ��Ϊ����Ϊ��float������ʱ����
//float& b=fn1(5.0);
    float c=fn2(5.0);//!һ��������Խ��շ��ص�����
    float& d=fn2(5.0);//!���ص�temp��ȫ�ֱ���
    float& e=fn3(5.0);
    float f=fn3(5.0);
    cout<<f<<endl;
    cout<<e<<endl;
    float& g=fn4(5.0);//!��gcc����ȷ
    cout<<g<<endl;

    fn2(5.0)=4;
    cout<<temp<<endl;
//    testReference();
//    cout << "Hello world!" << endl;
}
//���ض��б���������
void test1() {
    double* pd=new double(10);
    double& rd=*pd;
    cout<<*pd<<endl;
    cout<<rd<<endl;
    //�����ѿռ�����ַ�ʽ
    delete &rd;
    //delete pd
}
/**
�����ݲ���������Ϊָ�������ʱ��������ָ��������޸�
����ʵ�α��޸ĵİ취�Ǵ���constָ�������
**/
void fn5(){
    double* a=new double(2.0);
    const double *pd=a;
    double ad=32;
    ad+=*pd;//ֻ�ܶ�ȡ��
//    *pd=0;//����
    cout<<ad<<endl;
    //
    double b=3.0;
    const double &pb=b;
    //Ҳ��д��
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
