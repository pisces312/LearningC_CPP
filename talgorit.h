#ifndef TALGORIT_H_INCLUDED
#define TALGORIT_H_INCLUDED
#include<list>
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<functional>
using namespace std;
//
//
equal_to<char> equf;
//!默认的谓词，小于谓词
less<char> lessf;
//less_equal

//

//函数对象
//f(x,y)会调用在smaller_int中所定义的成员函数
struct smaller_int {
    bool operator()(int x,int y) const {
        return (x<y);
    }
}f;
//用于函数指针
bool is_smaller_int(int x,int y) {
    return (x<y);
}
//法一
template<class FwdIt>
FwdIt smallest(FwdIt first, FwdIt last) {
    return smallest(first,last,smaller_int());
}
//
//template<class FwdIt>
//FwdIt smallest2(FwdIt first, FwdIt last){
//    return smallest(first,last,f());
//}
//
//Pred表示谓词类，即它将提供一个表达式
template<class FwdIt,class Pred>
FwdIt smallest(FwdIt first, FwdIt last,Pred pr) {
    //存储最小值结果的位置
    FwdIt r=first;
    FwdIt t=r;
    for (t++;t!=last;t++) {
        if (pr(*t,*r)) {
            r=t;
        }
    }
    return r;
}
//法二
int get_smallest(int *first,int *last) {
    return (*smallest(first,last,smaller_int()));
}
//法三
//is_smaller_int前的&可选
int get_smallest2(int *first,int *last) {
    return (*smallest(first,last,&is_smaller_int));
}
int get_smallest3(int *first,int *last) {
    return (*smallest(first,last,is_smaller_int));
}
//
namespace mystll {
    template<class FwdIt> inline
    //返回第一个相邻的拥有同样元素的前一个元素的位置
    FwdIt adjacent_find(FwdIt F,FwdIt L) {
        //Fb，F分别保存迭代器中相邻的两个位置
        for (FwdIt Fb;(Fb=F)!=L&&++F!=L;)
            if (*Fb==*F)
                return (Fb);
        return (L);
    }
    //
    template<class BidIt,class Pr>inline
    //左闭右开区间
    bool next_permutation(BidIt F,BidIt L,Pr P) {
        //L不变
        //
        //保证迭代器中至少有两个元素
        BidIt I=L;
        //F==L将排除和终止位置相等，即无元素的情况
        //F==-I将排除有一个元素，即第一个元素位置和最后一个元素位置相等的情况
        if (F==L||F==-I)
            return false;
        //
        //
        for (;;) {
            BidIt Ip=I;
            //相邻两元素比较
            if (P(*--I,*Ip)) {
                //相当于进行一次排序
                BidIt J=L;
                for (;!P(*I,*--J););
                std::iter_swap(I,J);
                //
                std::reverse(Ip,L);
                return true;
            }
            if (I==F) {
                std::reverse(F,L);
                return false;
            }
        }
    }

};
void testAlgorithm2() {
    list<int> intList;
    intList.push_back(10);
    intList.push_back(2);
    intList.push_back(2);
    intList.push_back(1);
    intList.push_back(5);
    list<int>::iterator a=smallest(intList.begin(),intList.end());
    cout<<(*a)<<endl;
    //
    //
    int *first=new int[5];
    first[0]=39;
    first[1]=4;
    first[2]=9;
    first[3]=6;
    first[4]=2;
    int *last=first+5;
    int result=get_smallest(first,last);
    cout<<result<<endl;
    result=get_smallest2(first,last);
    cout<<result<<endl;
    result=get_smallest3(first,last);
    cout<<result<<endl;
    //
    list<int>::iterator b=mystll::adjacent_find(intList.begin(),intList.end());
    cout<<(*b)<<endl;
}
//测试结果为一个元素的函数
void test_single(char *first,char *last) {
    //!比较的是两个元素
    assert(max('0','2')=='2');
    assert(max('0','2',lessf)=='2');
    //
    //
    assert(min('0','2')=='0');
    assert(min('0','2',lessf)=='0');
    //
//    strcpy(first,"abcdefg");
//传入值
    swap(first[0],first[1]);
    assert(strcmp(first,"bacdefg")==0);
    //传入位置
    iter_swap(&first[0],&first[1]);
    assert(strcmp(first,"abcdefg")==0);
}
//
//测试查找
void test_find(char *first,char *last) {
    //cc
    strcpy(first,"abccefg");
    //
    //取序列中的极值
    assert(*max_element(first,last)=='g');
    assert(*max_element(first,last,lessf)=='g');
    //
    assert(*min_element(first,last)=='a');
    assert(*min_element(first,last,lessf)=='a');
    //前两个参数为第一个迭代器的起始和结束，最后一个为第二个迭代器的开始
    //!比较序列的相等，如果一个序列作为另一个的前缀也判断为相等
    //即比较的个数为last-first个

    assert(equal(first,last,first));
    assert(equal(first,last,first,equf));
    //
    char *t=new char[12];
    strcpy(t,"abccefghijkl");
    assert(equal(first,last,t));
    //
    //前两个参数为第一个迭代器的起始和结束，后两个为第二个的
    //比较的个数由两迭代器中元素个数少的决定
    //!比较一个序列是否排在另一个序列前面
    //!即排在后面序列，一定存在某个位置，上面元素大于前面序列中的所有元素
    //!对于一个序列是另一个序列前缀且不完全相等的情况，显然前缀序列排在另一个序列前
    assert(lexicographical_compare(first,last-1,first,last));
    assert(lexicographical_compare(first,last-2,first,last,lessf));
    //!两个序列完全相等，且比较的起止均相等，则不能分出前后，返回false
    assert(!lexicographical_compare(first,last,first,last));
//
//返回两序列中第一个不匹配的位置，这里用两个完全相等的序列比较，显然返回的是终止位置
    assert(mismatch(first,last,first).second==last);
    assert(mismatch(first,last,first,equf).second==last);
//

//!在序列中查找一个元素
//返回第一个匹配的元素的位置
    assert(find(first,last,'c')==first+2);
//!bind2nd为一个谓词，其中的第一个参数也是一个谓词
    assert(find_if(first,last,bind2nd(equf,'c'))==first+2);
//
//找相邻相等的元素的第一个位置
    assert(adjacent_find(first,last)==first+2);
    assert(adjacent_find(first,last,equf)==first+2);
//
    assert(count(first,last,'c')==2);
    assert(count_if(first,last,bind2nd(equf,'c'))==2);
    //
    //
//在另一个序列中检测一个序列第一次出现的地方
//!前两个参数确定”另一个序列“，后两个参数确定的序列相当于被查找的子序列
//这里"abccefg"中从位置2包含了"ccefg"
//!相当于求子序列的位置indexOf
    assert(search(first,last,first+2,last)==first+2);
    assert(search(first,last,first+2,last,equf)==first+2);
//!查找第一个连续出现n次某元素的位置
//这里2表示c要出现两次
    assert(search_n(first,last,2,'c')==first+2);
    assert(search_n(first,last,2,'c',equf)==first+2);
    //
    //检测一个子序列最后出现的地方
    //!与search相对应
    assert(find_end(first,last,first+2,last)==first+2);
    assert(find_end(first,last,first+2,last,equf)==first+2);
    //!检测另一个序列中的任意元素在前一个序列中第一次出现的位置
    //
    assert(find_first_of(first,last,first+2,last)==first+2);
    assert(find_first_of(first,last,first+2,last,equf)==first+2);
    //
    //!find_first_of与search区别
    char c1[]="abcdefg";
    char c2[]="udio";
    assert(find_first_of(c1,c1+7,c2,c2+4)==c1+3);
    assert(find_first_of(c1,c1+7,c2,c2+4,equf)==c1+3);
    //
    //



}
//
//测试生成类函数
size_t gen_count=0;
void count_c(char ch){
    if(ch=='c')
    ++gen_count;
}
char gen_x(){
    return 'x';
}
void test_generate(char *first,char* last,char * dest){
}
void testAlgorithm() {
    char buf[]="abcdefg";
    char dest[]="1234567";
    char *first=buf,*last=buf+7;
    test_single(first,last);
    test_find(first,last);

}


#endif // TALGORIT_H_INCLUDED
