#include <stdio.h>
#include <stdlib.h>
#define MAXN 11
#define MAXC 1001

int weights[MAXN];

char chu[MAXC];

void f(int n, int *a, int k, int s)
{
    if (n == k)
    {
        if (s >= 1)
            chu[s-1] = '1';
        return;
    }
    f(n, a, k+1, s+a[k+1]);
    f(n, a, k+1, s);
    f(n, a, k+1, s-a[k+1]);
}

int main()
{
    int wnum;
    scanf("%d", &wnum);
    int sum = 0;
    for (int i = 0; i < wnum; i++)
    {
        scanf("%d", &weights[i]);
        sum += weights[i];
    }
    chu[sum] = '\0';
    for (int i = 0; i < sum; i++)
        chu[i] = '0';
    f(wnum-1, weights, -1, 0);
    printf("%s\n", chu);
    return 0;
}