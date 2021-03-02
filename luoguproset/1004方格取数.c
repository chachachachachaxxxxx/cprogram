#include <stdio.h>
#include <stdlib.h>
#define MAXN 10

int da[MAXN][MAXN][MAXN][MAXN];

int max(int x, int y, int i, int j)
{
    if (x >= y && x >= i && x >= j)
        return x;
    else if (y >= x && y >= i && y >= j)
        return y;
    else if (i >= x && i >= y && i >= j)
        return i;
    else
        return j;
}

int maxda(int *a, int N, int x, int y, int i, int j)
{
    if(x == 0 || y == 0 || i == 0 || j == 0)
        return 0;
    if (x == 1)
    {
        if (x==i)
            return da[i][j][x][y] = max(maxda(a, N, x, y-1, i-1, j),maxda(a, N, x, y-1, i-1, j),maxda(a, N, x, y-1, i, j-1),maxda(a, N, x, y-1, i, j-1)) + a[x*N+y];
        else
            return da[i][j][x][y] = max(maxda(a, N, x, y-1, i-1, j),maxda(a, N, x, y-1, i-1, j),maxda(a, N, x, y-1, i, j-1),maxda(a, N, x, y-1, i, j-1)) + a[x*N+y]+a[i*N+j];
    }
    if (y == 1)
    {
        if (x==i)
        return da[i][j][x][y] = max(maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1)) + a[x*N+y];
    else
        return da[i][j][x][y] = max(maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1)) + a[x*N+y]+a[i*N+j];
    }
    if (i == 1)
    {
        if (x==i)
        return da[i][j][x][y] = max(maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1)) + a[x*N+y];
    else
        return da[i][j][x][y] = max(maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x-1, y, i, j-1)) + a[x*N+y]+a[i*N+j];
    }
    if (j == 1)
    {
        if (x==i)
        return da[i][j][x][y] = max(maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j)) + a[x*N+y];
    else
        return da[i][j][x][y] = max(maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i-1, j)) + a[x*N+y]+a[i*N+j];
    }
    if (x==i)
        return da[i][j][x][y] = max(maxda(a, N, x, y-1, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x, y-1, i, j-1)) + a[x*N+y];
    else
        return da[i][j][x][y] = max(maxda(a, N, x, y-1, i-1, j),maxda(a, N, x-1, y, i-1, j),maxda(a, N, x-1, y, i, j-1),maxda(a, N, x, y-1, i, j-1)) + a[x*N+y]+a[i*N+j];
}

int main()
{
    int N;
    int *wz;
    scanf("%d",&N);
    wz = (int*)malloc(sizeof(int)*(N+1)*(N+1));
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
        {
            wz[i*N+j] = 0;
        }
    int x,y,v;
    do{
        scanf("%d %d %d",&x,&y,&v);
        wz[x*N+y] = v;
    } while (x);
    /* for(x = 1; x <= N; x++)
        for (y = 1; y <= N; y++)
            if(wz[(x-1)*N+y-1])
                printf("v[%d][%d]:%d\n",x, y, wz[(x-1)*N+y-1]); */
    /*for (int x = 1; x <= N; x++)
        for (int y = 1; y <= N; y++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                {
                    da[i][j][x][y] = max(da[i-1][j][x-1][y], da[i-1][j][x][y-1], da[i][j-1][x-1][y], da[i][j-1][x][y-1]) + wz[x*N+y] + wz[i*N+j];
                    if (i == x)
                    da[i][j][x][y] -= wz[x*N+y];
                }*/
    printf("%d\n", maxda(wz, N, N, N, N, N));
    return 0;
}
