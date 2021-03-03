#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char eight[55];
char deci[170];
char tochar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char *chu8(char *d)
{
    int y = -1;
    int s;
    int h;
    int l = 0;
    int len = strlen(d);
    while (y || l < len)
    {
        if(l == 0)
        {
            y = d[l] - '0';
            s = 0;
            d[l] = tochar[s];
        }
        else
        {
            if (isdigit(d[l]))
                h = (d[l] - '0') + y * 10;
            else
                h = y * 10;
            s = h / 8;
            y = h % 8;
            d[l] = tochar[s];
        }
        l++;
    }
    d[l] = '\0';
    return d;
}

void e2d(char *e)
{
    char *deci2;
    deci2 = (char*)malloc(170);
    deci[0] = '.';
    int len = strlen(e);
    int l = len -1;
    deci2[1] = '\0';
    while (e[l] != '.')
    {
        deci2[0] = eight[l];
        deci2 = chu8(deci2);
        l--;
        printf("%s\n", deci2);
    }
    int len2 = strlen(deci2);
    for(int i = 1; i < len2; i++)
    {
        deci[i] = deci2[i];
    }
    deci[len2] = '\0';
}

int main()
{
    
    int pnum;
    scanf("%d", &pnum);
    for(int i = 0; i < pnum; i++)
    {
        scanf("%s", eight);
        e2d(eight);
        printf("case #%d:\n0%s\n", i, deci);
    }
    return 0;
}