#include <stdio.h>
#define MAXNUM 100

char s[MAXNUM];

void itoa(int n)
{
    static int i = 0;
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10);
    s[i++] = n % 10 + '0';
}

int main()
{
    int a;
    scanf("%d", &a);
    itoa(a);
    printf("%s\n", s);
    return 0;
}