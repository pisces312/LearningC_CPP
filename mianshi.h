#ifndef MIANSHI_H_INCLUDED
#define MIANSHI_H_INCLUDED
//extern const TEST_SIZE;
namespace Interview {
    //�궨��ĺ��� �����������������������ͣ��������壩
    #define FIND(struc,e)(size_t)&(((struc*)0)->e)
    using namespace std;

    /**
    �������ʽ�Ĵ�ӡֵ��0 1
    **/
    void testPrintBool() {
        std::cout<<(1>0)<<" "<<(1<0)<<std::endl;
    }
    /**
    �����Ĵ�����������
    **/
    void testParameterOrder() {
        int arr[]={6,7,8,9,10};
        int *ptr=arr;
        *(ptr++)+=123;

        printf("%d,%d\n",*ptr,*(++ptr));
    }
    /**
    ��̷��
    �ѳ���д��ǰ���
    ����==��д��=ʱ���������ᱨ��

    **/
    void testProgramStyle() {
        char a='A';
        if ('A'==a) {
            a++;
        }
    }
    /**
    �����������͵ı�ʾ��ͬ
    !!!����intǿ��ת����int&!!!!
    int&��ֱ�ӽ��ڴ����ݰ�������ʽ����������ֵ��ת��������
    **/
    void test1() {

        float a=1.0f;
        cout<<(int)a<<endl;
        cout<<&a<<endl;
        cout<<(int&)a<<endl;
        //!boolalpha��1 0��ʾ�Ĳ���ֵת��Ϊtrue false
        cout<<boolalpha<<((int)a==(int&)a)<<endl;
        //
        //
        //������0�ı�ʾ��������ͬ������ת�������ú���ͬ

        float b=0.0f;
        cout<<(int)b<<endl;
        cout<<&b<<endl;
        cout<<(int&)b<<endl;
        cout<<boolalpha<<((int)b==(int&)b)<<endl;


    }
    void test2() {
        unsigned int a=0xfffffff7;
        unsigned char i=(unsigned char)a;
        //ָ�����͵�ת�������ʶ�һ����ָ�����ݣ���
        char* b=(char*)&a;
        printf("%08x,%08x",i,*b);
    }
    /**
    ��������
    12�ֽ�
    **/
    void testWidestType() {
        cout<<sizeof(long double)<<endl;

    }
    /**
    ��ֵ����
    wchar_t��ö�����ͱ�����Ϊ�ܹ���ʾ��ײ���������ֵ����С��������
    **/
    void testIntegralPromotion() {
        enum status {bad,ok};
        cout<<sizeof(ok)<<endl;
        cout<<sizeof(status)<<endl;
    }
    /**
    ��ʹ��ѭ���ж��Ƿ���2��n�η�
    **/
    bool is2PowerN(const int& x) {
        return !(x&(x-1));
    }
    /**
    ��ʹ����ʱ����������������
    **/
    void swapWithoutVar(int& a,int& b) {
        a=a^b;
        b=a^b;
        a=a^b;

    }
    /**
    ʹ�ú����ṹ���б�����Խṹ���ƫ����
    **/
    void testMacro() {

        struct student {
            int a;
            char b[20];
            double ccc;
        };
        cout<<FIND(student,a)<<endl;
        cout<<FIND(student,b)<<endl;
        cout<<FIND(student,ccc)<<endl;
    }
    /**
    ��C++�п����ó�����Ϊ����Ĵ�С����
    **/
    void testConstAsArraySize() {
        const int size=10;
        char a[size];
        //C�п��Բ�д�������ƣ�������gcc���������룬�����ȷ
        //C++�в���ͨ������
//        const bufsize=100;
//        char buf[bufsize];
//        printf("%d\n",sizeof(buf));
    }
    /**
    ���Ա������mutable���κ�����Ϊconst�ĳ�Ա�����Ϳ����޸�
    �ñ���
    **/
    void testMutable() {
        class A {
            public:
            mutable int count;
            int inc() const {
                return ++count;
            }
        };
        A a;
        a.inc();
    }
    /**
    sizeof
    **/
    void testSizeof() {
        struct {
            short a1;
            short a2;
            short a3;
        }A;
        struct {
            long a1;
            short a2;
        }B;
        char* ss1="0123456789";
        char ss2[]="0123456789";
        char ss3[100]="0123456789";
        int ss4[100];
        char q1[]="abc";
        char q2[]="a\n";
        char* q3="a\n";
        char *str1=(char *)malloc(100);
        void* str2=(void *)malloc(100);
        cout<<sizeof(ss1)<<endl;
        cout<<sizeof(ss2)<<endl;
        cout<<sizeof(ss3)<<endl;
        cout<<sizeof(ss4)<<endl;
        cout<<sizeof(q1)<<endl;
        cout<<sizeof(q2)<<endl;
        cout<<sizeof(q3)<<endl;
        cout<<sizeof(A)<<endl;
        cout<<sizeof(B)<<endl;
        cout<<sizeof(str1)<<endl;
        cout<<sizeof(str2)<<endl;
        //
        //!����Ǳ�������Բ�������
        cout<<sizeof ss1<<endl;
    }
    /**
    ���ݶ���
    0x0023ff54
    0x0023ff53
    0x0023ff4c
    **/
    class A1 {
        int a;
        //������ȫ�ֶ���ʱ�����о�̬��Ա������
        //�ں����ж���������
        static int b;
    };
    void testDataAlign() {
        int a;
        char b;
        int c;
        printf("0x%08x\n",&a);
        printf("0x%08x\n",&b);
        printf("0x%08x\n",&c);
        //
        //

        class A2 {
            int a;
            char c;
        };
        class A3 {
            float a;
            char c;
        };
        class A4 {
            float a;
            int b;
            char c;
        };
        class A5 {
            public:
            double d;
            float a;
            int b;
            char c;
        };
        cout<<sizeof(A1)<<endl;
        cout<<sizeof(A2)<<endl;
        cout<<sizeof(A3)<<endl;
        cout<<sizeof(A4)<<endl;
        cout<<sizeof(A5)<<endl<<endl;
        cout<<FIND(A5,d)<<endl;
        cout<<FIND(A5,a)<<endl;
        cout<<FIND(A5,b)<<endl;
        cout<<FIND(A5,c)<<endl;
    }
    void func1(char a[8]) {
        cout<<sizeof(a)<<endl;
    }
    void func2(char a[]) {
        cout<<sizeof(a)<<endl;
    }
    /**
    ������Ϊ������������ʱ������ָ�����������
    **/
    void testArrayAsParameter() {
        char a[8]="0123456";
        func1(a);
        func2(a);
    }
    double funcDouble() {
        return 0;
    }

    int func1(int a) {
//        int *c=new int[1];
//        *c=a+b;
//        return c;
        return a;
    }
    typedef int (*funcIntInt)(int);
    funcIntInt funcFuncIntInt(int,int) {
        return func1;

    }
    void testArrayPointer() {
//        float array[10];
//        float array2[10][10];
//float array3[10][10][10];
//????
//�����Ԫ����float����????
        float (*array4[10])[10];

        float (**def)[10]=array4;
        cout<<sizeof(def[0])<<endl;
        cout<<sizeof(def)<<endl;
        cout<<sizeof(*def[0])<<endl;
        cout<<sizeof(**def)<<endl;
        //
        //
        double(*f[10])();
        f[0]=funcDouble;
        cout<<f[0]()<<endl;
        //
        int a=1,c=2;
        int* array5[10]={&a,&c};
        int*((*b)[10])=&array5;
        //��*bΪ����array5
        //��ӡ��һ��Ԫ��ָ�������
        cout<<*((*b)[0])<<endl;
        //
        //ָ��һ�����غ���ָ�룬��������int�����ĺ���
        //�������ָ��ָ��һ������һ��int����������int�� ����
        int(*(*F)(int,int))(int);
        //��int(* ((*F)(int,int)) )(int);
        F=funcFuncIntInt;
        cout<<(F(1,2))(123)<<endl;


    }
    /**
    scanf�Ĳ���Ҫ��������Ϊ���룡��
    The scanf function reads data from the standard input stream stdin and writes the data into the location given by argument. Each argument must be a pointer to a variable of a type that corresponds to a type specifier in format. If copying takes place between strings that overlap, the behavior is undefined.

    scanf��ÿ������������ָ�룡��
    **/
    void testScanfVar() {
        int a=0,b=0,c=0;
        cout<<a<<" "<<b<<" "<<c<<endl;
        //���ܴ���ͨ���������봫ָ��
//        scanf("%d%d%d",a,b,c);
//        cout<<a<<" "<<b<<" "<<c<<endl;
        scanf("%d%d%d",&a,&b,&c);
        cout<<a<<" "<<b<<" "<<c<<endl;

    }
    /**
    �ṹ���ָ��Ŀ���
    **/
    void test3() {
        struct S {
            int i;
            int *p;
        };
        S s;
        int *p=&s.i;
        p[0]=4;
        p[1]=3;
        s.p=p;
        s.p[1]=1;
        cout<<&s<<endl;
        cout<<p<<endl;
        cout<<p[0]<<endl;
        cout<<p[1]<<endl;
//        cout<<s.p<<endl;
        cout<<s.p[1]<<endl;
        //����
//        s.p[0]=2;
    }
    /**
    ��ַ��
    **/
    void test4() {
        int a[3]={0,1,2};
        int *p,*q;
        p=a;
        cout<<p<<endl;
        cout<<*p<<endl;
        q=&a[2];
        cout<<q<<endl;
        cout<<*q<<endl;
        cout<<q-p<<endl;
        cout<<a[q-p]<<endl;
        cout<<*q-*p<<endl;
        cout<<a[*q-*p]<<endl;
        /**
        0x23ff40
        0
        0x23ff48
        2
        2
        2
        2
        2
        **/
    }
    /**
    �����ָ��Ĵ洢����
    ջ  ��
    0x23ff40
    0x443013
    **/
    void test5() {
        char c[]="hello";
        char *pc="hello";
        void *p1=c;
        void *p2=pc;
        cout<<p1<<endl;
        cout<<p2<<endl;
    }
    /**
    ��ָ��ָ��ġ���ַ�����޸�
    1 ͨ��ָ���ָ��
    2 ͨ������ָ��
    **/
    void modifyPointer1(char** p,int size) {
        *p=(char *)malloc(sizeof(char)*size);
    }
    char *modifyPointer2(int size) {
        return (char *)malloc(sizeof(char)*size);
    }
    char *modifyPointer3(char *p,int size) {
        p=(char *)malloc(sizeof(char)*size);
        return p;
    }
    void testModifyPointer() {
        char *p1,*p2,*p3;
        modifyPointer1(&p1,10);
        p2=modifyPointer2(10);
        p3=modifyPointer3(p3,10);
        cout<<p1<<" "<<&p1<<endl;
        cout<<p2<<" "<<&p2<<endl;
        cout<<p3<<" "<<&p3<<endl;
        /**
        �@ 0x23ff50
        �@ 0x23ff4c
        �@ 0x23ff48
        **/
    }
    /**
    ����Ե�ַ��С���ж�
    **/
    void testAddressSize() {
        long a=1;
        long *p=&a;
        *p=0;
        cout<<sizeof(long*)<<endl;
        cout<<p<<endl;
        cout<<a<<endl;
    }
    //c++�²����ԣ���
//    inline fac(float i) {
//        return i*i;
//    };
//    void testInline() {
//        printf("%d\n",fac(8));
//    }
//inline fac(float i){return i*i};
    /**
    ���ڿ���
    **/
    class f {
        private:
        int data;
        static int data1;
    };
    void testEmptyClass() {
//    class A{};
//    cout<<sizeof(A)<<endl;
        /**
        ������ͬ�����Ա�ʵ��������ÿ��ʵ�����ڴ��ж���һ����һ�޶��ĵ�ַ��Ϊ�˴ﵽ���Ŀ�ģ��������������һ�����������ļ�һ���ֽڣ�����������ʵ���������ڴ�õ��˶�һ�޶��ĵ�ַ��
        **/
        class a {};
        class b {};
        /**
        ����c������a������������������һ�����麯�����������麯����ԭ����һ��ָ���麯����ָ�루vptr�����ڣ���λ��ϵͳ�����ָ��Ĵ�СΪ�����ֽڣ��������õ�c��Ĵ�СΪ����
        **/
        class c:public a {
            virtual void fun()=0;
        };
        class d:public b,public c {};
        cout<<"sizeof(a)"<<sizeof(a)<<endl;
        cout<<"sizeof(b)"<<sizeof(b)<<endl;
        cout<<"sizeof(c)"<<sizeof(c)<<endl;
        cout<<"sizeof(d)"<<sizeof(d)<<endl;
        /**
        windows g++
        sizeof(a)1
        sizeof(b)1
        sizeof(c)4
        sizeof(d)4
        **/
        class e {
            private:
            int data;
        };

        /**
        ��b�ľ�̬���ݳ�Ա�����������ڳ����һ��global data members�У��������һ�����ݳ�Ա����������Ӱ����Ĵ�С�����������ʵ�ʲ������˶���ʵ�������������˶����µ��࣬��̬��Ա������������Զֻ��һ��ʵ����ڣ�����ķǾ�̬���ݳ�Աֻ�б�ʵ������ʱ�����ǲŴ��ڣ�������ľ�̬���ݳ�Աһ�����������������Ƿ�ʵ�����������Ѵ��ڣ�������ô˵����ľ�̬���ݳ�Ա��һ�������ȫ�ֱ�����
        **/

        cout<<"sizeof(e)="<<sizeof(e)<<endl;
        cout<<"sizeof(f)="<<sizeof(f)<<endl;
        //
        //
        //
        struct A {};
        cout<<sizeof(A)<<endl;
    }
    /**
    ����a<b<C����
    **/
    void testTrap() {
        int a=0,b=1,c=2;
        /**
         (a<b<c) ���մ����ҵķ�ʽ��ʼ����
        1.( (a<b) < c )
        2.a<b ?  TRUE : FALSE;
        3.����, ���ձ��ʽ������� (1<c) ���� (0<c)
        **/
        if (a<b<c) {
            cout<<"trap a<b<c\n"<<endl;
        } else {
            cout<<"trap\n"<<endl;
        }
        //����
        if (a<b&&b<c) {
            cout<<"a is min.\n";
        }
    }

    void test() {
        testTrap();
//        testEmptyClass();
//        testInline();
//        testAddressSize();
//        testModifyPointer();
//        test5();
//        test3();
//        testScanfVar();
//        testArrayPointer();
//        testArrayAsParameter();
//        testDataAlign();
//        testSizeof();
//        testMutable();
//        testConstAsArraySize();
//        testMacro();
        //
        //
        //
//        int a=1,b=2;
//        cout<<a<<" "<<b<<endl;
//        swapWithoutVar(a,b);
//        cout<<a<<" "<<b<<endl;
        //
        //
//        cout<<boolalpha<<is2PowerN(16)<<endl;
//        testIntegralPromotion();
//        testWidestType();
//        test2();
//        test1();

//        unsigned char a=0xa5;
//        std::cout<<(a>>4)<<std::endl;
//        std::cout<<(~a>>4)<<std::endl;
//        testPar ameterOrder();
//        testPrintBool();
    }
};


#endif // MIANSHI_H_INCLUDED
