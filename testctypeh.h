#ifndef TESTCTYPEH_H_INCLUDED
#define TESTCTYPEH_H_INCLUDED
#include<ctype.h>
/**
    The header <ctype.h> declares functions for testing characters. For each function, the argument list is an int, whose value must be EOF or representable as an unsigned char, and the return value is an int. The functions return non-zero (true) if the argument c satisfies the condition described, and zero if not.
**/
void testCtypeHeader() {
    char c='a';
//判断字母或数字
    printf("%d\n",isalnum(c));// isalpha(c) or isdigit(c) is true
    printf("%d\n",isalpha(c));// isupper(c) or islower(c) is true
//判断是否为控制字符，如回车。。。
    printf("%d\n",iscntrl(c));// control character
    printf("%d\n",isdigit(c));// decimal digit
//是否是空格外可打印字符
    printf("%d\n",isgraph(c));// printing character except space
    printf("%d\n",islower(c));// lower-case letter
//是否是包括空格在内的可打印字符
    printf("%d\n",isprint(c));// printing character including space
//是否是除空格、字母、数字外的可打印字符
    printf("%d\n",ispunct(c));// printing character except space or letter or digit
    printf("%d\n",isspace(c));// space, formfeed, newline, carriage return, tab, vertical tab
    printf("%d\n",isupper(c));// upper-case letter
    printf("%d\n",isxdigit(c));// hexadecimal digit
//In the seven-bit ASCII character set, the printing characters are 0x20 (' ') to 0x7E ('-'); the control characters are 0 NUL to 0x1F (US), and 0x7F (DEL).
//
//In addition, there are two functions that convert the case of letters:

    printf("%d\n",tolower(c));// convert c to lower case
    printf("%d\n",toupper(c));// convert c to upper case


//If c is an upper-case letter, tolower(c) returns the corresponding lower-case letter, toupper(c) returns the corresponding upper-case letter; otherwise it returns c.


}


#endif // TESTCTYPEH_H_INCLUDED
