#ifndef TESTIO_H_INCLUDED
#define TESTIO_H_INCLUDED
#include <stdarg.h>
/**
����ԭ��������������Ҫһ��ȷ���Ĳ�����ע�������ڵ�ʡ�Ժ�
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
        //ֱ������������ǰ����%�Ž��������ƥ�䣬����ֱ���������Ļ
        switch (*++p) {
        case 'd':
        case 'i'://!��һ��������va_list���ͱ������ڶ���������ָ����������
//!va_arg��Ϊ����Ĳ��������޸ı�������
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
//!�����س���������
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

//!fmt�Ǳ䳤�������ǰһ�����������ǰ��û�в�����

    va_start(ap, fmt);    /* make ap point to the first unnamed arg */
    for (p = fmt; *p; p++) {

        if (*p != '%') {
            putchar(*p);
            continue;
        }
        //ֱ������������ǰ����%�Ž��������ƥ�䣬����ֱ���������Ļ
        switch (*++p) {
        case 'd':
        case 'i'://!��һ��������va_list���ͱ������ڶ���������ָ����������
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
    //!�������һ���ַ��������к�%������ʾ����
    char *s3="ab%cef\n";
    printf(s3);
    //
    //����������ַ�����
    char *output=(char *)malloc(100);
    sprintf(output,"%s",s2);
    printf("%s\n",output);
    //

}


#endif // TESTIO_H_INCLUDED
