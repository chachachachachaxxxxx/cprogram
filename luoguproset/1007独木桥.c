#include <stdio.h>
int main()
{
    int len;
    scanf("%d",&len);
    int n;
    scanf("%d",&n);
    int min, max;
    max = min = 0;
    int r, l, m;
    for (int i = 0 ; i < n; i++)
    {
        scanf("%d",&r);
        l = len+1-r;
        if (r > l)
        {
            m = r;
            r = l;
            l = m;
        }
        if (r > min)
        {
            min = r;
        }
        if (l > max)
        {
            max = l;
        }
    }
    printf("%d %d\n",min,max);
    return 0;
}