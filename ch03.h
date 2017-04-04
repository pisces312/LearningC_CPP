#ifndef CH03_H_INCLUDED
#define CH03_H_INCLUDED
#include <ctype.h>
#include <limits.h>
#include <string.h>

/* atoi:  convert s to integer; version 2 */
int atoiEx(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')  /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
/* shellsort:  sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
/* reverse:  reverse string s in place */
void reverse(char s[]) {
    int c, i, j;
//j不考虑\0
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        //swap前后交换，c为临时变量
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void reverse2(char s[]) {
    int i,j,c;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        //使用”,“
        c = s[i], s[i] = s[j], s[j] = c;
}
//将整型转换为字符串
/* itoa:  convert n to characters in s */
void itoa2(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {      /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';//!保证字符串的最后始终为\0，翻转时不考虑\0
    reverse(s);
}
//将整型转换为字符串
/* itoa:  convert n to characters in s */
void itoa3(int n, char s[]) {
    int i, sign;


    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {      /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while (n /= 10);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';//!保证字符串的最后始终为\0，翻转时不考虑\0
    reverse(s);
}
/*  Stores a string representation of integer n
    in s[], using a numerical base of b. Will handle
    up to base-36 before we run out of digits to use.  */

void itob(int n, char s[], int b) {
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, sign;

    if ( b < 2 || b > 36 ) {
        fprintf(stderr, "EX3_5: Cannot support base %d\n", b);
        exit(EXIT_FAILURE);
    }

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
/*
  EX3_6.C
  =======
  Suggested solution to Exercise 3-6
*/
void itoaWidth(int n, char s[], int width) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
//        printf("%d %% %d + '0' = %d\n", n, 10, s[i-1]);
    } while (n /= 10);
    if (sign < 0)
        s[i++] = '-';

    while (i < width )    /*  Only addition to original function  */
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}
/* trim:  remove trailing blanks, tabs, newlines */
int trim(char s[]) {
    int n;

    for (n = strlen(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}

void testCh03() {
//    printf("%d\n",atoiEx("-123"));
    char* s=(char*)malloc(sizeof(char)*20);
//    printf("%s\n",-1234%10+'0');
//    printf("%d\n",-1234%10);
//最大的4字节整数
//    itoa3(-32768,s);
//itoaBase(
//    itoa2(12345,s);
//    itob(255,s,16);
//    printf("%s\n",s);
//        char buffer[20];

    itoaWidth(INT_MIN, s, 7);
    printf("Buffer:%s\n", s);
}



#endif // CH03_H_INCLUDED
