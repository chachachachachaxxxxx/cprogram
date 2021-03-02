#include <stdio.h>
#include <stdlib.h>
#define MAXN 11

int matrix[MAXN][MAXN];

int main()
{
    int pnum;
    scanf("%d", &pnum);
    int r,c,n,k;
    for (int i = 0; i < pnum; i++)
    {
        scanf("%d %d %d %d", &r, &c, &n, &k);
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                matrix[i][j] = 0;
        for(int j = 0; j < n; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            matrix[x][y] = 1;
        }
        int num = 0;
        for (int x = 1; x <= r; x++)
            for (int y = 1; y <= c; y++)
                for (int x1 = x; x1<= r; x1++)
                    for (int y1 = y; y1 <= c; y1++)
                    {
                        int onenum = 0;
                        for (int i = x; i <= x1; i++)
                            for(int j = y; j <= y1; j++)
                            {
                                if (matrix[i][j])
                                    onenum++;
                            }
                        if (onenum >= k)
                            num++;
                    }
        printf("case #%d:\n%d\n", i, num);
    }
    return 0;
}