#include <stdio.h>
#include <stdlib.h>
#define MAXN 10001

typedef struct shu{
    long long n;
    int onen;
} SHU;

SHU snums[MAXN];

int onenum(long long n)
{
    long long d = 1;
    int on = 0;
    for(int i = 0; i < 64; i++)
    {
        if (d&n)
            on++;
        d = d<<1;
    }
    return on;
}

int cmp(const void*a, const void*b)
{
    SHU *a1, *b1;
    a1 = (SHU*)a;
    b1 = (SHU*)b;
    if (a1->onen == b1->onen)
    {
        if (a1->n < b1->n)
            return -1;
        else
            return 1;
    }
    else
        return b1->onen - a1->onen;
}

int main()
{
    int pnum;
    scanf("%d", &pnum);
    int snum;
    for(int i = 0; i < pnum; i++)
    {
        scanf("%d", &snum);
        for(int j = 0; j < snum; j++)
        {
            scanf("%lld", &(snums+j)->n);
            (snums+j)->onen = onenum((snums+j)->n);
        }
        qsort(snums, snum, sizeof(SHU), cmp);
        printf("case #%d:\n", i);
        for(int j = 0; j < snum; j++)
            printf("%lld ", (snums+j)->n);
        printf("\n");
    }
    return 0;
}