#ifndef MYSTRCAT_H_INCLUDED
#define MYSTRCAT_H_INCLUDED
//#include <stdio.h>
#include <string>
namespace MyStringOpr {
    void strcpy(char *s, char *t) {
        while (*s++ = *t++);
    }

    void strcat(char *s, char *t) {
        //法一
        while (*s) {
            ++s;
        }
        //法二??
//        while(*(s++));
        strcpy(s, t);
    }
    int strlen(char *s) { /* added by RJH; source: K&R p99 */
        int n;

        for (n = 0; *s != '\0'; s++) {
            n++;
        }
        return n;
    }

    int strcmp(char *s, char *t) { /* added by RJH; source: K&R p106 */
        for (;*s == *t; s++, t++)
            if (*s == '\0')
                return 0;
        return *s - *t;
    }
    /**
    判断t是否在s的末尾
    **/
    int strend(char *s, char *t) {
        int Result = 0;
        int s_length = 0;
        int t_length = 0;

        /* get the lengths of the strings */
        s_length = strlen(s);
        t_length = strlen(t);

        /*
        t在s的末尾，则t的大小一定小于等于s
        check if the lengths mean that the string t could fit at the string s */
        if (t_length <= s_length) {
            /* advance the s pointer to where the string t would have to start in string s */
            s += s_length - t_length;

            /* and make the compare using strcmp */
            if (0 == strcmp(s, t)) {
                Result = 1;
            }
        }

        return Result;
    }
    //
    //
    //
    //5-5
    #define MAX_BUF 16
    /**
    赋值ct中的n个字符赋值到s所指向的字符数组中
    **/
    char *liw_strncpy(char *s, const char *ct, size_t n) {
        char *p;

        p = s;
        for (; n > 0 && *ct != '\0'; --n)
            *p++ = *ct++;
        for (; n > 0; --n)
            *p++ = '\0';
        return s;
    }
    /**
    连接ct中的n个字符
    **/
    char *liw_strncat(char *s, const char *ct, size_t n) {
        char *p;

        p = s;
        while (*p != '\0')
            ++p;
        for (; n > 0 && *ct != '\0'; --n)
            *p++ = *ct++;
        *p = '\0';
        return s;
    }

    int liw_strncmp(const char *cs, const char *ct, size_t n) {
        while (n > 0 && *cs == *ct && *cs != '\0') {
            ++cs;
            ++ct;
            --n;
        }
        if (n == 0 || *cs == *ct)
            return 0;
        if (*(unsigned char *) cs < *(unsigned char *) ct)
            return -1;
        return 1;
    }
    void test_ncpy(const char *str) {
        char std_buf[MAX_BUF];
        char liw_buf[MAX_BUF];

        memset(std_buf, 0x42, sizeof(std_buf));
        strncpy(std_buf, str, sizeof(std_buf));

        memset(liw_buf, 0x42, sizeof(liw_buf));
        liw_strncpy(liw_buf, str, sizeof(liw_buf));

        if (memcmp(std_buf, liw_buf, sizeof(std_buf)) != 0) {
            fprintf(stderr, "liw_strncpy failed for <%s>\n", str);
            exit(EXIT_FAILURE);
        }
    }

    void test_ncat(const char *first, const char *second) {
        char std_buf[MAX_BUF];
        char liw_buf[MAX_BUF];

        memset(std_buf, 0x69, sizeof(std_buf));
        std::strcpy(std_buf, first);
        strncat(std_buf, second, sizeof(std_buf) - strlen(std_buf) - 1);

        memset(liw_buf, 0x69, sizeof(liw_buf));
        std::strcpy(liw_buf, first);
        liw_strncat(liw_buf, second, sizeof(liw_buf) - strlen(liw_buf) - 1);

        if (memcmp(std_buf, liw_buf, sizeof(std_buf)) != 0) {
            fprintf(stderr, "liw_strncat failed, <%s> and <%s>\n",
                    first, second);
            exit(EXIT_FAILURE);
        }
    }

    void test_ncmp(const char *first, const char *second) {
        size_t len;
        int std_ret, liw_ret;

        if (std::strlen(first) < std::strlen(second))
            len = std::strlen(second);
        else
            len = std::strlen(first);
        std_ret = strncmp(first, second, len);
        liw_ret = liw_strncmp(first, second, len);
        if ((std_ret < 0 && liw_ret >= 0) || (std_ret > 0 && liw_ret <= 0) ||
                (std_ret == 0 && liw_ret != 0)) {
            fprintf(stderr, "liw_strncmp failed, <%s> and <%s>\n",
                    first, second);
            exit(EXIT_FAILURE);
        }
    }

    void testNStringOpr() {
        test_ncpy("");
        test_ncpy("a");
        test_ncpy("ab");
        test_ncpy("abcdefghijklmnopqrstuvwxyz");     /* longer than MAX_BUF */

        test_ncat("", "a");
        test_ncat("a", "bc");
        test_ncat("ab", "cde");
        test_ncat("ab", "cdefghijklmnopqrstuvwxyz"); /* longer than MAX_BUF */

        test_ncmp("", "");
        test_ncmp("", "a");
        test_ncmp("a", "a");
        test_ncmp("a", "ab");
        test_ncmp("abc", "ab");

        printf("All tests pass.\n");
    }
    void testStrcat() {
        char testbuff[128];

        char *test[] = {
            "",
            "1",
            "12",
            "123",
            "1234"
        };

        size_t numtests = sizeof test / sizeof test[0];
        size_t thistest;
        size_t inner;

        for (thistest = 0; thistest < numtests; thistest++) {
            for (inner = 0; inner < numtests; inner++) {
                strcpy(testbuff, test[thistest]);
                strcat(testbuff, test[inner]);

                printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
            }
        }

//  return 0;
    }
    void testStrend() {
        char *s1 = "some really long string.";
        char *s2 = "ng.";
        char *s3 = "ng";

        if (strend(s1, s2)) {
            printf("The string (%s) has (%s) at the end.\n", s1, s2);
        } else {
            printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
        }
        if (strend(s1, s3)) {
            printf("The string (%s) has (%s) at the end.\n", s1, s3);
        } else {
            printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
        }


    }
};



#endif // MYSTRCAT_H_INCLUDED
