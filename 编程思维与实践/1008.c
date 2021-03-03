#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    if(b % a == 0)
        return a;
    else
        return gcd(b % a , a);  
}

int onenum(char *s)
{
    int onum = 0;
    char c;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        c = s[i];
        int d = 1;
        for(int j = 0 ; j < 8; j++)
        {
            if(d&c)
                onum++;
            d <<= 1;
        }
    }
    return onum;
}

int main()
{
    int n;
    char s[130];
    scanf("%d", &n);
    char enter;
    enter = getchar();
    int fz, fm;
    int g;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        while((s[j++] = getchar())!= '\n');
        s[j-1] = '\0';
        fm = (j-1) * 8;
        fz = onenum(s);
        g = gcd(fz, fm);
        fm = fm / g;
        fz = fz / g;
        printf("%d/%d\n",fz, fm);
    }
    return 0;
}