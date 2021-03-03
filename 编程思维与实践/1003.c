#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 62

char st[MAXN];

char qz[MAXN];

long long shibie(char *a)
{
    char *p;
    p = a;
    qz[0] = *p;
    int i = 0;
    int l = 1;
    int len = strlen(a);
    while (*p)
    {
        for(i =0; i < l && *p != qz[i]; i++)
            ;
        if (qz[i] == 0)
        {
            qz[i] = *p;
            l++;
        }
        p++;
    }
    long long sum = 0;
    int shu = 0;
    if (l < 2)
        l = 2;
    for(int j = 0; j < len; j++)
    {
        for(int k = 0; k < l; k++)
        {
            if (st[j] == qz[k])
            {
                shu = k;
                break;
            }
        }
        if (shu == 1)
            shu = 0;
        else if (shu == 0)
            shu = 1;
        sum = sum * l + shu;
    }
    return sum;
}

int main()
{
    int pnum;
    scanf("%d", &pnum);
    /*printf("%d %d\n", qz[0], '0');*/
    for(int i = 0; i < pnum; i++)
    {
        for(int j = 0; j < MAXN; j++)
            qz[j] = 0;
        scanf("%s", st);
        if (strlen(st) == 1)
            printf("case #%d:\n%d\n", i, 1);
        else
            printf("case #%d:\n%lld\n", i, shibie(st));
    }
    return 0;
}