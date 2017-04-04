#ifndef MIANSHI_H_INCLUDED
#define MIANSHI_H_INCLUDED
//extern const TEST_SIZE;
namespace Interview {
    //宏定义的函数 函数名（参数）（返回类型）（函数体）
    #define FIND(struc,e)(size_t)&(((struc*)0)->e)
    using namespace std;

    /**
    布尔表达式的打印值是0 1
    **/
    void testPrintBool() {
        std::cout<<(1>0)<<" "<<(1<0)<<std::endl;
    }
    /**
    参数的传递由右向左
    **/
    void testParameterOrder() {
        int arr[]={6,7,8,9,10};
        int *ptr=arr;
        *(ptr++)+=123;

        printf("%d,%d\n",*ptr,*(++ptr));
    }
    /**
    编程风格
    把常量写在前面好
    当把==误写成=时，编译器会报错

    **/
    void testProgramStyle() {
        char a='A';
        if ('A'==a) {
            a++;
        }
    }
    /**
    浮点数和整型的表示不同
    !!!区别int强制转换和int&!!!!
    int&是直接将内存内容按整数格式解析，不是值的转换！！！
    **/
    void test1() {

        float a=1.0f;
        cout<<(int)a<<endl;
        cout<<&a<<endl;
        cout<<(int&)a<<endl;
        //!boolalpha将1 0表示的布尔值转换为true false
        cout<<boolalpha<<((int)a==(int&)a)<<endl;
        //
        //
        //浮点数0的表示与整数相同，所以转换成引用后相同

        float b=0.0f;
        cout<<(int)b<<endl;
        cout<<&b<<endl;
        cout<<(int&)b<<endl;
        cout<<boolalpha<<((int)b==(int&)b)<<endl;


    }
    void test2() {
        unsigned int a=0xfffffff7;
        unsigned char i=(unsigned char)a;
        //指针类型的转换，本质都一样，指向内容！！
        char* b=(char*)&a;
        printf("%08x,%08x",i,*b);
    }
    /**
    最宽的类型
    12字节
    **/
    void testWidestType() {
        cout<<sizeof(long double)<<endl;

    }
    /**
    整值提升
    wchar_t和枚举类型被提升为能够表示其底层类型所有值的最小整数类型
    **/
    void testIntegralPromotion() {
        enum status {bad,ok};
        cout<<sizeof(ok)<<endl;
        cout<<sizeof(status)<<endl;
    }
    /**
    不使用循环判断是否是2的n次方
    **/
    bool is2PowerN(const int& x) {
        return !(x&(x-1));
    }
    /**
    不使用临时变量交换两个变量
    **/
    void swapWithoutVar(int& a,int& b) {
        a=a^b;
        b=a^b;
        a=a^b;

    }
    /**
    使用宏计算结构体中变量相对结构体的偏移量
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
    在C++中可以用常量作为数组的大小参数
    **/
    void testConstAsArraySize() {
        const int size=10;
        char a[size];
        //C中可以不写类型名称！！！在gcc中正常编译，结果正确
        //C++中不能通过编译
//        const bufsize=100;
//        char buf[bufsize];
//        printf("%d\n",sizeof(buf));
    }
    /**
    类成员变量被mutable修饰后，修饰为const的成员函数就可以修改
    该变量
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
        //!如果是变量则可以不加括号
        cout<<sizeof ss1<<endl;
    }
    /**
    数据对齐
    0x0023ff54
    0x0023ff53
    0x0023ff4c
    **/
    class A1 {
        int a;
        //必须是全局定义时才能有静态成员！！！
        //在函数中定义则不允许
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
    数组作为参数传给函数时传的是指针而不是数组
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
//数组的元素是float数组????
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
        //即*b为数组array5
        //打印第一个元素指向的内容
        cout<<*((*b)[0])<<endl;
        //
        //指向一个返回函数指针，具有两个int参数的函数
        //这个函数指针指向一个具有一个int参数，返回int型 函数
        int(*(*F)(int,int))(int);
        //即int(* ((*F)(int,int)) )(int);
        F=funcFuncIntInt;
        cout<<(F(1,2))(123)<<endl;


    }
    /**
    scanf的参数要以引用作为输入！！
    The scanf function reads data from the standard input stream stdin and writes the data into the location given by argument. Each argument must be a pointer to a variable of a type that corresponds to a type specifier in format. If copying takes place between strings that overlap, the behavior is undefined.

    scanf的每个参数必须是指针！！
    **/
    void testScanfVar() {
        int a=0,b=0,c=0;
        cout<<a<<" "<<b<<" "<<c<<endl;
        //不能传普通变量，必须传指针
//        scanf("%d%d%d",a,b,c);
//        cout<<a<<" "<<b<<" "<<c<<endl;
        scanf("%d%d%d",&a,&b,&c);
        cout<<a<<" "<<b<<" "<<c<<endl;

    }
    /**
    结构体和指针的考察
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
        //出错
//        s.p[0]=2;
    }
    /**
    地址差
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
    数组和指针的存储区别
    栈  堆
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
    对指针指向的“地址”的修改
    1 通过指针的指针
    2 通过返回指针
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
        餈 0x23ff50
        餈 0x23ff4c
        餈 0x23ff48
        **/
    }
    /**
    考察对地址大小的判断
    **/
    void testAddressSize() {
        long a=1;
        long *p=&a;
        *p=0;
        cout<<sizeof(long*)<<endl;
        cout<<p<<endl;
        cout<<a<<endl;
    }
    //c++下不可以！！
//    inline fac(float i) {
//        return i*i;
//    };
//    void testInline() {
//        printf("%d\n",fac(8));
//    }
//inline fac(float i){return i*i};
    /**
    关于空类
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
        （空类同样可以被实例化），每个实例在内存中都有一个独一无二的地址，为了达到这个目的，编译器往往会给一个空类隐含的加一个字节，这样空类在实例化后在内存得到了独一无二的地址．
        **/
        class a {};
        class b {};
        /**
        而类c是由类a派生而来，它里面有一个纯虚函数，由于有虚函数的原因，有一个指向虚函数的指针（vptr），在３２位的系统分配给指针的大小为４个字节，所以最后得到c类的大小为４．
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
        类b的静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员．但是它不影响类的大小，不管这个类实际产生　了多少实例，还是派生了多少新的类，静态成员数据在类中永远只有一个实体存在，而类的非静态数据成员只有被实例化的时候，他们才存在．但是类的静态数据成员一旦被声明，无论类是否被实例化，它都已存在．可以这么说，类的静态数据成员是一种特殊的全局变量．
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
    测试a<b<C陷阱
    **/
    void testTrap() {
        int a=0,b=1,c=2;
        /**
         (a<b<c) 按照从左到右的方式开始运算
        1.( (a<b) < c )
        2.a<b ?  TRUE : FALSE;
        3.所以, 最终表达式运算的是 (1<c) 或者 (0<c)
        **/
        if (a<b<c) {
            cout<<"trap a<b<c\n"<<endl;
        } else {
            cout<<"trap\n"<<endl;
        }
        //正解
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
