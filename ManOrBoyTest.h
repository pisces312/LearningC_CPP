#ifndef MANORBOYTEST_H_INCLUDED
#define MANORBOYTEST_H_INCLUDED
/**
begin
  real procedure A (k, x1, x2, x3, x4, x5);
  value k; integer k;
  begin
    real procedure B;
    begin k:= k - 1;
          B:= A := A (k, B, x1, x2, x3, x4);
    end;
    if k <= 0 then A:= x4 + x5 else B;
  end;
  outreal (A (10, 1, -1, -1, 1, 0));
end;

**/
//!在boost包中
//可用
#include <iostream>
#include <boost/tr1/memory.hpp>
using namespace boost;
//using std::tr1::shared_ptr;
//using std::tr1::enable_shared_from_this;

struct Arg {
    virtual int run() = 0;
    virtual ~Arg() { };
};

int A(int, shared_ptr<Arg>, shared_ptr<Arg>, shared_ptr<Arg>,
      shared_ptr<Arg>, shared_ptr<Arg>);

class B : public Arg, public enable_shared_from_this<B> {
    private:
    int k;
    const shared_ptr<Arg> x1, x2, x3, x4;

    public:
    B(int _k, shared_ptr<Arg> _x1, shared_ptr<Arg> _x2, shared_ptr<Arg> _x3,
      shared_ptr<Arg> _x4)
    : k(_k), x1(_x1), x2(_x2), x3(_x3), x4(_x4) { }
    int run() {
        return A(--k, shared_from_this(), x1, x2, x3, x4);
    }
};

class Const : public Arg {
    private:
    const int x;
    public:
    Const(int _x) : x(_x) { }
    int run () {
        return x;
    }
};

int A(int k, shared_ptr<Arg> x1, shared_ptr<Arg> x2, shared_ptr<Arg> x3,
      shared_ptr<Arg> x4, shared_ptr<Arg> x5) {
    if (k <= 0)
        return x4->run() + x5->run();
    else {
        shared_ptr<Arg> b(new B(k, x1, x2, x3, x4));
        return b->run();
    }
}

void testManOrBoy() {
    std::cout << A(10, shared_ptr<Arg>(new Const(1)),
                   shared_ptr<Arg>(new Const(-1)),
                   shared_ptr<Arg>(new Const(-1)),
                   shared_ptr<Arg>(new Const(1)),
                   shared_ptr<Arg>(new Const(0))) << std::endl;
}

//
//
/* man-or-boy.c */
#include <stdio.h>
#include <stdlib.h>

// --- thunks
//typedef struct arg {
//    int       (*fn)(struct arg*);
//    int        *k;
//    struct arg *x1, *x2, *x3, *x4, *x5;
//} ARG;
//
//// --- lambdas
//int f_1 (ARG* _) {
//    return -1;
//}
//int f0  (ARG* _) {
//    return  0;
//}
//int f1  (ARG* _) {
//    return  1;
//}
//
//// --- helper
//int eval(ARG* a) {
//    return a->fn(a);
//}
//#define ARG(...) (&(ARG){ __VA_ARGS__ })
////
//#define FUN(...) ARG(B,&k,__VA_ARGS__)
//
//// --- functions
//int A(ARG*);//声明
//int B(ARG* a) {
//    int k = (*a->k -= 1);
//    return A(FUN(a,a->x1,a->x2,a->x3,a->x4));
//}
//
//int A(ARG* a) {
//    return *a->k <= 0 ? eval(a->x4)+eval(a->x5) : B(a);
//}
//
//void testManOrBoy() {
//    int k = 10;//argc == 2 ? strtol(argv[1],0,0) : 10;
//
//    printf("%d\n", A( FUN(ARG(f1),ARG(f_1),ARG(f_1),ARG(f1),ARG(f0)) ));
//}


//
//
//#include <stdio.h>
//#define INT(body) ( { int lambda() {    body;}; lambda; })
//int testManOrBoy(){
//    int a(int k, int xl(), int x2(), int x3(), int x4(), int x5()) {
//        int b() {
//            return a(--k, b, xl, x2, x3, x4);
//        }
//        return k<=0 ? x4() + x5() : b();
//    }
//    printf(" %d\n",a(10, INT(return 1), INT(return -1), INT(return -1), INT(return 1), INT(return 0)));
//}
//int A(int k,int x1,int x2,int x3,int x4,int x5){
//    k--;
//    int
//    int B=A(k,B
//}

#endif // MANORBOYTEST_H_INCLUDED
