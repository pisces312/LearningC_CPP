#ifndef TESTIO_H_INCLUDED
#define TESTIO_H_INCLUDED
#include <stdarg.h>
/**
函数原型声明，至少需要一个确定的参数，注意括号内的省略号
**/
//xxxx
//void vArgFunc1(...){
//}
void minscanf(char *fmt,...) {
    va_list ap;
    va_start(ap, fmt);
    char *p;
    char * sval;
    for (p = fmt; *p; p++) {

        if (*p != '%') {
            putchar(*p);
            continue;
        }
        //直到读到参数的前导符%才进行下面的匹配，否则直接输出到屏幕
        switch (*++p) {
        case 'd':
        case 'i'://!第一个参数是va_list类型变量，第二个参数是指定参数类型
//!va_arg作为输入的参数，可修改变量本身
            scanf("%d", va_arg(ap, int));
            break;
        case 'c':
            scanf("%c", va_arg(ap, int));
            break;
        case 'u':
            scanf("%u", va_arg(ap, unsigned int));
            break;
        case 'o':
            scanf("%o", va_arg(ap, unsigned int));
            break;
        case 'x':
            scanf("%x", va_arg(ap, unsigned int));
            break;
        case 'X':
            scanf("%X", va_arg(ap, unsigned int));
            break;
        case 'e':
            scanf("%e", va_arg(ap, double));
            break;
        case 'f':
            scanf("%f", va_arg(ap, double));
            break;
        case 'g':
            scanf("%g", va_arg(ap, double));
            break;
        case 's':
//!遇到回车结束输入
            for (sval = va_arg(ap, char *); *sval!='\n'; sval++)
//                scanf("%c",*sval);
                scanf("%c",sval);
//                getchar(*sval);
//                putchar(*sval);
            break;
        default:
            scanf("%c",sval);
//            getchar(*p);
            break;
        }
    }
    va_end(ap);
}
void minprintf(char *fmt, ...) {
    //!


    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;

//!fmt是变长参数表的前一个参数，如果前面没有参数？

    va_start(ap, fmt);    /* make ap point to the first unnamed arg */
    for (p = fmt; *p; p++) {

        if (*p != '%') {
            putchar(*p);
            continue;
        }
        //直到读到参数的前导符%才进行下面的匹配，否则直接输出到屏幕
        switch (*++p) {
        case 'd':
        case 'i'://!第一个参数是va_list类型变量，第二个参数是指定参数类型
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'c':
            ival = va_arg(ap, int);
            putchar(ival);
            break;
        case 'u':
            uval = va_arg(ap, unsigned int);
            printf("%u", uval);
            break;
        case 'o':
            uval = va_arg(ap, unsigned int);
            printf("%o", uval);
            break;
        case 'x':
            uval = va_arg(ap, unsigned int);
            printf("%x", uval);
            break;
        case 'X':
            uval = va_arg(ap, unsigned int);
            printf("%X", uval);
            break;
        case 'e':
            dval = va_arg(ap, double);
            printf("%e", dval);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 'g':
            dval = va_arg(ap, double);
            printf("%g", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);

}

void testVariableArgs() {
    minprintf("%s","abcdefg\n");
//    int i;
//    minscanf("%d",&i);
//    printf("%d",i);
    //
    char *s=(char*)malloc(100);//"efghijkl\n";
    minscanf("%s",s);
    printf("%s",s);

}
void testIO() {
    char *s="Hello World!";
    int max=5;
    printf("%.*s\n", max, s);
    printf("%s\n", s);
    printf("%10s\n", s);
    printf("%.10s\n", s);
    printf("%-10s\n", s);
    printf("%.15s\n", s);
    printf("%-15s\n", s);
    printf("%15.10s\n", s);
    printf("%-15.10s\n", s);
    //
    char *s2="abcef\n";
    printf(s2);
    //!如果单独一个字符串变量中含%，则显示乱码
    char *s3="ab%cef\n";
    printf(s3);
    //
    //把输出放在字符串中
    char *output=(char *)malloc(100);
    sprintf(output,"%s",s2);
    printf("%s\n",output);
    //

}


#endif // TESTIO_H_INCLUDED
