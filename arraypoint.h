#ifndef ARRAYPOINT_H_INCLUDED
#define ARRAYPOINT_H_INCLUDED
namespace ArrayPointer {
    void arrayTest(char str[]) {
        cout << sizeof(str) << endl;
    }
    void test() {
        /**
        1、数组名不是指针

        　　我们先来推翻"数组名就是指针"的说法，用反证法。

        　　证明　数组名不是指针

        　　假设：数组名是指针；

        　　则：pStr和str都是指针；

        　　因为：在WIN32平台下，指针长度为4；

        　　所以：第6行和第7行的输出都应该为4；

        　　实际情况是：第6行输出10，第7行输出4；

        　　所以：假设不成立，数组名不是指针
        **/
        char str[10];
        char *pStr = str;
        cout << sizeof(str) << endl;
        cout << sizeof(pStr) << endl;
        //
        /**
        2、数组名神似指针        　　上面我们已经证明了数组名的确不是指针，但是我们再看看程序的第5行。该行程序将数组名直接赋值给指针，这显得数组名又的确是个指针！
        　　标准C库函数strcpy的函数原形中能接纳的两个参数都为char型指针，而我们在调用中传给它的却是两个数组名！函数输出：

        string array 1: I Love U
        string array 2: I Love U
        **/
        char str1[10] = "I Love U";
        char str2[10];
        strcpy(str2,str1);
        cout << "string array 1: " << str1 << endl;
        cout << "string array 2: " << str2 << endl;
        //
        //
        int intArray[10];
        cout << sizeof(intArray)<<endl ;
//
//
//!错误
//        intArray++;
//
//
        /**
        　　程序的输出结果为4。不可能吧？
        　　一个可怕的数字，前面已经提到其为指针的长度!        　　结论1指出，数据名内涵为数组这种数据结构，在arrayTest函数体内，str是数组名，那为什么sizeof的结果却是指针的长度？这是因为：
        　　(1)数组名作为函数形参时，在函数体内，其失去了本身的内涵，仅仅只是一个指针；        　　(2)很遗憾，在失去其内涵的同时，它还失去了其常量特性，可以作自增、自减等操作，可以被修改。        　　所以，数据名作为函数形参时，其全面沦落为一个普通指针！它的贵族身份被剥夺，成了一个地地道道的只拥有4个字节的平民。
        　　以上就是结论4。
        **/
        arrayTest(str1);
    }
};


#endif // ARRAYPOINT_H_INCLUDED
