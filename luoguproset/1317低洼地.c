#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    a = 0;
    int t1;         
    t1 = 0;
    int di = 0;
    for(int i = 0 ; i < n;i++)
    {
        scanf("%d",&b);
        if (t1)
        {
            if(a < b)
            {
                di++;
                t1 = 0;
            }
        }
        if (a > b)
            t1 = 1;
        a = b;
    }
    printf("%d\n",di);
    return 0;
}