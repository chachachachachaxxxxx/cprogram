#include <stdio.h>
#include <stdlib.h>
#define MAXN 1001

typedef struct clom{
    long long r;
    long long h;
    long long xs;
}  CLOM;

CLOM cloms[MAXN];

int cmp(const void*a, const void*b)
{
    CLOM *a1, *b1;
    a1 = (CLOM *)a;
    b1 = (CLOM *)b;
    if (b1->xs < a1->xs)
        return -1;
    return 1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &cloms[i].r, &cloms[i].h);
        cloms[i].xs = 2 * cloms[i].r * cloms[i].h;
    }
    qsort(cloms, n, sizeof(CLOM), cmp);
    long long s = 0;
    long long s1 = 0;
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        s += cloms[i].xs+cloms[i].r*cloms[i].r;
        num++;
        for(int j = 0; j < n && num < m; j++)
        {
            if (cloms[j].r <= cloms[i].r && i != j)
            {
                s += cloms[j].xs;
                num++;
            }
        }
        if (s > s1)
            s1 = s;
        s = 0;
        num = 0;
    }
    printf("%lld\n", s1);
    return 0;
}