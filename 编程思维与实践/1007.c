#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pnum;
    scanf("%d", &pnum);
    int len, len1;
    int d;
    int n;
    int t1;
    int t2;
    for(int i = 0; i < pnum; i++)
    {
        len1 = 0;
        len = 1;
        d = 1;
        scanf("%d", &n);
        if(n&d)
            t2 = 1;
        else
            t2 = 0;
        for(int j = 1; j < 32; j++, d <<= 1)
        {
            if(n&d)
                t1 = 1;
            else
                t1 = 0;
            while (t1 != t2)
            {
                len++;
                t2 = t1;
                d <<= 1;
                j++;
                if(n&d)
                    t1 = 1;
                else
                    t1 = 0;
            }
            if (t1 == 0)
                len--;
            t2 = t1;
            if (len > len1)
                len1 = len;
            len = 1;
        }
        printf("case #%d:\n%d\n", i, len1);
    }
    return 0;
}