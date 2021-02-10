#include <stdio.h>
int main()
{
    int a,b,c;
    int a1,b1,c1;
    int p;
    int n[10];
    for (a = 123; a <= 329;a++)
    {
        for(int i = 0 ; i < 10; i++)
        {
            n[i] = 0;
        }
        p = 1;
        a1 = a;
        b = a*2;
        c = a*3;
        b1 = b;
        c1 = c;
        for(int i = 1; i <= 3; i++)
        {
            n[a1%10]++;
            n[b1%10]++;
            n[c1%10]++;
            a1 /= 10;
            b1 /= 10;
            c1 /= 10; 
        }
        for (int i = 1; i < 10;i++)
            p *= n[i];
        if (p == 1)
            printf("%d %d %d\n", a, b, c);
    }
    return 0; 
}