#ifndef TESTCIN_H_INCLUDED
#define TESTCIN_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
void testCin() {
    char   c;
    string   str;

    cin>>c;
    cin.putback(c);

    while (true) {
        c   =   cin.peek();

        if (   c   ==   '\n'   )
            break;
        cin   >>   c;
        if (   c   >=   '0'   &&   c   <=   '9'   )
            str+=c;
        else {
            cin.sync();
            str.erase();
            cout   <<   "reinput   "     <<   endl;
            cin   >>   c;
            cin.putback(c);
        }
    }

//    stringstream   ss;
//    int   i;
//
//    ss.str(str);
//    ss   >>   i;
//
//    cout   <<   i;
}


#endif // TESTCIN_H_INCLUDED
