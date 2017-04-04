#ifndef TESTSTLSET_H_INCLUDED
#define TESTSTLSET_H_INCLUDED
#include   <iostream>
#include   <set>
#include<map>
#include<stdio.h>
//#include<ext/hash_set>
using   namespace   std;
namespace testset{
    void testHashSet(){
        map<int,int> m;
        m.insert(map<int,int>::value_type(1,2));
        //不能第二次向相同key中添加元素！！
        pair<map<int, int>::iterator, bool> Insert_Pair=m.insert(map<int,int>::value_type(1,3));
        if(Insert_Pair.second){
        }else{
            printf("failed\n");
        }



        map<int,int>::iterator itr=m.begin();
        while(itr!=m.end()){
            cout<<(*itr).second<<endl;
            itr++;
        }
//        std::
//        hash_set<int> hashSet;


    }
void testSet() {
    //定义
    set<int>   myset;
    //插入
    for (int   i=1;i<=10;i++)
        myset.insert(i);
    //遍历
    set<int>::iterator   it;
    for (it=myset.begin();it!=myset.end();++it)
        cout<<*it<<" ";
    cout<<endl;
    //删除
//    myset.clear();
    //
//    for (it=myset.begin();it!=myset.end();++it)
//        cout<<*it<<" ";
//    cout<<endl;
    //查找
    set<int>::iterator r=myset.find(2);
    cout<<*r<<endl;
    r=myset.find(15);
    //!结果和end相比！
    if (r==myset.end())
        cout<<"没有找到\n";

    else {
        cout<<*r<<endl;
    }
    //
    //
    set <int> s1;
    set <int> :: const_iterator s1_AcIter, s1_RcIter;

    s1.insert( 10 );
    s1.insert( 20 );
    s1.insert( 30 );

    s1_RcIter = s1.find( 20 );
    cout << "The element of set s1 with a key of 20 is: "
         << *s1_RcIter << "." << endl;

    s1_RcIter = s1.find( 40 );

    // If no match is found for the key, end( ) is returned
    if ( s1_RcIter == s1.end( ) ) {
        cout << "The set s1 doesn't have an element "
             << "with a key of 40." << endl;
//             cout<<*s1_RcIter<<endl;
    } else
        cout << "The element of set s1 with a key of 40 is: "
             << *s1_RcIter << "." << endl;

    // The element at a specific location in the set can be found
    // by using a dereferenced iterator addressing the location
    s1_AcIter = s1.end( );
    s1_AcIter--;
    s1_RcIter = s1.find( *s1_AcIter );
    cout << "The element of s1 with a key matching "
         << "that of the last element is: "
         << *s1_RcIter << "." << endl;



}

};
#endif // TESTSTLSET_H_INCLUDED
