#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>  /* for  atof() */

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
#define MAXVAL  100  /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push:  push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
#define BUFSIZE 100
//!����
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void) { /* get a (possibly pushed-back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getop:  get next character or numeric operand */
/**
һԪ�����硰-��������֮��û�пո�
Bob goes on to say: "Deal with unary minus when retrieving tokens. This is based on the fact that a unary minus will have no intervening space between it and its operand."

**/
int getop(char s[]) {
    int i, c,next;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    //!�����������
    //��Ԫ������
    if (!isdigit(c) && c != '.'&&c!='-')
        return c;      /* not a number */
    //
    //
    //
    if (c == '-') {
        next = getch();
        //��������ķ����ֻ�.����˵���Ƕ�Ԫ�ļ�
        if (!isdigit(next) && next != '.') {
            return c;
        }

        c = next;
    } else {
        c = getch();
    }
// while(isdigit(s[++i] = c))
//            c = getch();
//    if(c == '.')                     /* Collect fraction part. */
//        while(isdigit(s[++i] = c = getch()))
//                        ;
//    s[i] = '\0';
//    if(c != EOF)
//        ungetch(c);
//    return NUMBER;

    i = 0;
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    //��������֣��򷵻�һ�����ֱ�ţ�ʵ��ֵ�ӻ������ȡ
    return NUMBER;
}

/* reverse Polish calculator */
//!�ӿ���̨���룬��������Ҫ�����ɿո�������������Ͳ�����֮�䲻��Ҫ
//!������ʽΪ��׺���ʽ
void polishCalculator() {
    int type;
    double op2;
    //���棬��ʱ�洢ÿ�εõ��Ĳ������������
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            //!���������
        case NUMBER:
        //??
            push(atof(s));
            break;
            //!+��*���㽻���ɣ�����Ҫ����λ��
            //
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
            //
            //!��Ҫ����λ��,�ȳ����ǵڶ���������
        case '-':
            //op2��ʾһ��������
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
            //!���ȡģ����
        case '%':
            op2=pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
//����
//                push((int)pop() % (int)op2);
            else
                printf("\nError: Division by zero!");

            break;
            //!����������յ��س��ͽ���
        case '\n':
            printf("\t%.8g\n", pop());
//            break;
            return;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
//    return 0;
}



#endif // CALCULATE_H_INCLUDED
