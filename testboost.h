#ifndef TESTBOOST_H_INCLUDED
#define TESTBOOST_H_INCLUDED
//!boost库的使用
#include <boost/token_iterator.hpp>
//
#include <boost/lambda/lambda.hpp>
//
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
//
#include <string>
//
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
using namespace boost;
namespace BoostTest {
    void testBoost() {
        std::string s("12252001");
        int offsets[] = {2,2,4};
        offset_separator f(offsets, offsets+3);
        typedef token_iterator_generator<offset_separator>::type Iter;
        Iter beg = make_token_iterator<std::string>(s.begin(),s.end(),f);
        Iter end = make_token_iterator<std::string>(s.end(),s.end(),f);
        for (;beg!=end;++beg) {
            std::cout << *beg << "\n";
        }
        //
        //
        //

    }

    void test1() {
        //以下程序的功能是从终端接受一个整数序列，然后乘以3再输出到终端
        using namespace boost::lambda;
        typedef std::istream_iterator<int> in;
// TODO (Administrator#1#): _1??

//        std::for_each(
//            in(std::cin),
//            in(),
//            std::cout << (_1 * 3) << " ");
    }
    void test2() {
        //以下程序在终端输出[2](2,8)
        //必须使用int
        using namespace boost::numeric::ublas;
        boost::numeric::ublas::vector<int> x (2);
        x(0) = 1;
        x(1) = 2;
        boost::numeric::ublas::matrix<int> A(2, 2);
        A(0, 0) = 0;
        A(0, 1) = 1;
        A(1, 0) = 2;
        A(1, 1) = 3;
        boost::numeric::ublas::vector<int> y = prod(A, x);
        std::cout << y << std::endl;

    }
    /**
    测试线程
    **/
    void hello() {
        std::cout << "Hello world, I'm a thread!" << std::endl;
    }
    //使用了一个互斥变量，使得按顺序计数
    boost::mutex io_mutex;

    struct count    {
        count(int id) : id(id) { }
        void operator()() {
            for (int i = 0; i < 10; ++i) {
                boost::mutex::scoped_lock
                lock(io_mutex);
                std::cout << id << ": " << i << std::endl;
            }
        }
        int id;
    };
    struct count2    {
        count2(int id) : id(id) { }
        void operator()() {
            for (int i = 0; i < 10; ++i) {
                std::cout << id << ": " << i << std::endl;
            }
        }
        int id;
    };
    void testThread() {
        //法一 传函数
        boost::thread thrd(&hello);
        thrd.join();
        //!private方法,不能直接调用
//        thrd.start_thread();
//
//法二，使用复杂对象,operator
        boost::thread thrd1(count2(1));
        boost::thread thrd2(count2(2));
//                boost::thread thrd1(count(1));
//        boost::thread thrd2(count(2));
        thrd1.join();
        thrd2.join();
        //
        //
        //法三，在类内部创建对象
        class HelloWorld        {
            public:
            static void hello() {
                std::cout << "Hello world, I''m a thread!" << std::endl;
            }
            //使用静态方法
            static void start() {
                boost::thread thrd( hello );
                thrd.join();
            }
        };
        HelloWorld::start();
    }
    void testSuite() {
        test2();
        testThread();

    }
};

#endif // TESTBOOST_H_INCLUDED
