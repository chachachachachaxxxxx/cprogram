#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i = 0;
    int s = 0;
    int fu = -1;
    int a, b;
    while (s < n)
    {
        i++;
        s += i;
        fu = -fu;
    }
    s -= i;
    if (fu == -1)
    {
        a = n-s;
        b = i-(n-s-1);
    }
    else
    {
        a = i-(n-s-1);
        b = n-s;
    }
    printf("%d/%d\n",a,b);
    return 0;
}