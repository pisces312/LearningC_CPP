#ifndef TESTBOOST_H_INCLUDED
#define TESTBOOST_H_INCLUDED
//!boost���ʹ��
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
        //���³���Ĺ����Ǵ��ն˽���һ���������У�Ȼ�����3��������ն�
        using namespace boost::lambda;
        typedef std::istream_iterator<int> in;
// TODO (Administrator#1#): _1??

//        std::for_each(
//            in(std::cin),
//            in(),
//            std::cout << (_1 * 3) << " ");
    }
    void test2() {
        //���³������ն����[2](2,8)
        //����ʹ��int
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
    �����߳�
    **/
    void hello() {
        std::cout << "Hello world, I'm a thread!" << std::endl;
    }
    //ʹ����һ�����������ʹ�ð�˳�����
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
        //��һ ������
        boost::thread thrd(&hello);
        thrd.join();
        //!private����,����ֱ�ӵ���
//        thrd.start_thread();
//
//������ʹ�ø��Ӷ���,operator
        boost::thread thrd1(count2(1));
        boost::thread thrd2(count2(2));
//                boost::thread thrd1(count(1));
//        boost::thread thrd2(count(2));
        thrd1.join();
        thrd2.join();
        //
        //
        //�����������ڲ���������
        class HelloWorld        {
            public:
            static void hello() {
                std::cout << "Hello world, I''m a thread!" << std::endl;
            }
            //ʹ�þ�̬����
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
