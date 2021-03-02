#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

char shu[MAXN];

typedef struct zhiyu{
    int qz;
    int x;
    int s;
} ZY;

ZY shuwei[MAXN];

void f(int n, int k, int ik)
{
    int m = 0;
    if (k == 0)
    {
        m = n;
        if (m < 10)
            shu[ik] = '0'+m;
        else
            shu[ik] = 'A'-10+m;
        return ;
    }
    while (n < shuwei[k-1].x )
    {
        n -= shuwei[k].qz;
        m++;
    }
    while (n > shuwei[k-1].s)
    {
        n -= shuwei[k].qz;
        m++;
    }
    if (m < 10)
        shu[ik] = '0'+m;
    else
        shu[ik] = 'A'-10+m;
    f(n, k-1, ik+1);
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    /*for(int i = 0; i < MAXN; i++)
        shu[i] = '0';*/
    int k = 0;
    shuwei[0].qz = 1;
    shuwei[0].x = 0;
    shuwei[0].s = -r-1;
    while (n < shuwei[k].x || n > shuwei[k].s)
    {
        k++;
        shuwei[k].qz = shuwei[k-1].qz * r;
        if (k % 2)
        {
            shuwei[k].s = shuwei[k-1].s;
            shuwei[k].x = shuwei[k].s - abs(shuwei[k].qz * r) + 1;
        }
        else
        {
            shuwei[k].x =shuwei[k-1].x;
            shuwei[k].s = shuwei[k].x + abs(shuwei[k].qz * r) - 1;
        }
    }
    printf("%d %d %d\n",n, shuwei[k].x, shuwei[k].s);
    shu[k+1] = '\0';
    f(n, k, 0);
    printf("%s\n", shu);
    return 0;
}