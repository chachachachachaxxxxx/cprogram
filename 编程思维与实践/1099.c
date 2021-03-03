#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXL 100

char pattern[MAXL];

int main()
{
    scanf("%s", pattern);
    int xs = 0;
    int con = 0;
    char *a;
    a = pattern;
    char qw;
    qw = -1;
    char cs;
    int shu = 0;
    int sign = 1;
    while (*a != '=')
    {
        if (isalpha(*a))
        {
            cs = *a;
            if (a - pattern)
            {
                if (qw == '-')
                    sign = -1;
                else if (qw == '+' || qw == -1)
                    sign = 1;
            }
            else
                sign = 1;
            if (!shu)
                shu = 1;
            shu *= sign;
            xs += shu;
        }
        if (isdigit(*a))
        {
            shu = 0;
            while (isdigit(*a))
            {
                shu = shu*10 + *a - '0';
                a++;
            }
            if (isalpha(*a))
                continue;
            if (a - pattern)
            {
                if (qw == '-')
                    con += shu;
                else if (qw == '+' || qw == -1)
                    con -= shu;
            }
            else
                con -= shu;
            continue;
        }
        qw = *a;
        a++;
    }
    a++;
    char *a1;
    a1 = a;
    qw = -1;
    while (*a != '\0')
    {
        int shu = 0;
        if (isalpha(*a))
        {
            cs = *a;
            if (a - pattern)
            {
                if (qw == '-')
                    sign = 1;
                else if (qw == '+' || qw == -1)
                    sign = -1;
            }
            else
                sign = -1;
            if (!shu)
                shu = 1;
            shu *= sign;
            xs += shu;
        }
        if (isdigit(*a))
        {
            while (isdigit(*a))
            {
                shu = shu*10 + *a - '0';
                a++;
            }
            if (isalpha(*a))
                continue;
            if (a - a1)
            {
                if (qw == '-')
                    con -= shu;
                else if (qw == '+' || qw == -1)
                    con += shu;
            }
            else
                con += shu;
            continue;
        }
        qw = *a;
        a++;  
    }
    printf("%c=%.3f\n", cs, 1.0*con/xs);
    return 0;
}