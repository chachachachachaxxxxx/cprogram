#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100

char shu[MAXN];

char tochar[]={'0','1','2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

char cc[16];

char xs[65];
char jm[11];
char wm[1025];

void a2i2(char *a)
{
    int s = 0;
    char *a1;
    a1 = a;
    int sign = 1;
    if (*a1 == '-')
    {
        sign = -1;
        a1++;
    }
    else if(*a1 == '+')
        a1++;
    while (*a1)
    {
        s = s * 10 + *a1 - '0';
        a1++;
    }
    s *= sign;
    int d = 15;
    int ch = 0;
    for (int i = 0; i < 8; i++)
    {
        ch = d & s;
        s = (unsigned)s >> 4;
        if (i % 2 == 0)
            cc[i+1] = tochar[ch];
        else
            cc[i-1] = tochar[ch];
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%c", cc[i]);
        if(i % 2)
            printf(" ");
    }
    return;
}

void a2d2(char *a)
{
    char *a1;
    a1 = a;
    int sign = 1;
    int i1 = 0;
    int ip = 0;
    int ip2 = 0;
    if (*a1 == '-')
    {
        sign = -1;
        a1++;
    }
    else if(*a1 == '+')
        a1++;
    while(*a1)
    {
        if(*a1 == '.')
        {
            ip = i1;
            xs[i1] = *a1;
        }
        else
            xs[i1] = *a1 - '0';
        i1++;
        a1++;
    }
    long long s1 = 0;
    for(int i = 0; i < ip; i++)
    {
        s1 = s1 * 10 + xs[i];
    }
    if(s1 == 0)
    {
        wm[0] = 0;
        wm[1] = '.';
        ip2 = 1;
    }
    else
    {
        char zc[64];
        int k = 0;
        while(s1)
        {
            zc[k] = s1 % 2;
            k++;
            s1 /= 2;
        }
        for (int i = 0; i < k; i++)
        {
            wm[i] = zc[k-i];
            wm[i+1] = '.';
            ip2 = i+1;
        }
    }
    long long s2 = 0;
    long long count = 1;
    for(int i = ip+1; i < i1; i++)
    {
        s2 = s2 * 10 + xs[i];
        count *= 10;
    }
    int w = ip2+1;
    while(s2 && w < 1025)
    {
        s2 *= 2;
        if(s2 >= count)
        {
            s2 -= count;
            wm[w] = 1;
        }
        else
            wm[w] = 0;
        w++;
    }
    int one1 = -1;
    for(int i =0; i < w; i++)
        if (wm[i] == 1)
        {
            one1 = i;
            break;
        }
    int jms = ip2 - one1 + 1;
    if (one1 == -1)
        jms = 0;
    int d = 1;
    for(int i = 11; i >=0 ; i--)
    {
        jm[i] = d & jms;
        jms >>= 1;
    }
    i1 = 0;
    w = 0;
    for(int i = 0; i < 64; i++, w++)
    {
        if (i == 0)
        {
            if (sign == -1)
                xs[i] = 1;
            else
                xs[i] = 0;
        }
        else if( i < 12)
            xs[i] = jm[i-1];
        else 
        {
            if(wm[w] == '.')
                w++;
            xs[i] = wm[w];
        }
    }
    int s = 0;
    int wz = 0;
    for(int i = 0; i < 64; i++)
    {
        s += s*2 + xs[i];
        if(i%4 == 3)
        {
            if(wz%2)
                cc[wz-1] = tochar[s];
            else
                cc[wz+1] = tochar[s];
            wz++;
            s = 0;
        }
    }
    /*while(*(a1++) != '.')
    {
        s = s * 10.0  + (*a1 - '0');
    }
    a1++;
    printf("%lf\n",s);
    while(*a1++)
        s = (s * 10 + *a1 - '0') / 10;
    printf("%lf\n", s);
    s *= sign;*/
    
    for (int i = 7; i >= 0; i--)
    {
        printf("%c%c ", cc[2*i], cc[2*i+1]);
    }
    return;
}

int main()
{
    int t = 1;
    double xs = 0;
    int su = 0;
    while (scanf("%s", shu) != EOF)
    {
        int len = strlen(shu);
        for (int i = 0; i < len ; i++)
            if (shu[i] == '.')
            {
                t = 0;
                break;
            }
        if (t == 0)
            a2d2(shu);
        else if (t == 1)
            a2i2(shu);
    }
    return 0;
}