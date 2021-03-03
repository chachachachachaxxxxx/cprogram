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
    printf("\n");
    return;
}

void a2d2(double d)
{
    int c = sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
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
		for(int i = 0; i < 8; i++)
			cc[i] = 0;
        if (t == 0)
            a2d2(atof(shu));
        else if (t == 1)
            a2i2(shu);
		t = 1;
    }
    return 0;
}