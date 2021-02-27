#include <stdio.h>

typedef struct point{int x; int y;} P;

unsigned long long nums[21][21];

unsigned long long tj(P ma, P di)
{
    if (di.x == 0 && di.y == 0)
        return 1;
    else if (di.x < 0 || di.y < 0)
        return 0;
    if (nums[di.x][di.y]!= -1)
        return nums[di.x][di.y];
    if ((di.x == ma.x - 2 && di.y == ma.y - 1)
      ||(di.x == ma.x - 1 && di.y == ma.y - 2)
      ||(di.x == ma.x + 1 && di.y == ma.y + 2)
      ||(di.x == ma.x + 2 && di.y == ma.y + 1)
      ||(di.x == ma.x - 1 && di.y == ma.y + 2)
      ||(di.x == ma.x + 1 && di.y == ma.y - 2)
      ||(di.x == ma.x - 2 && di.y == ma.y + 1)
      ||(di.x == ma.x + 2 && di.y == ma.y - 1)
      ||(di.x == ma.x && di.y == ma.y))
        return 0;
    P di1, di2;
    di1.x = di.x-1;
    di2.x = di.x;
    di1.y = di.y;
    di2.y = di.y-1;
    return nums[di.x][di.y] = tj(ma, di1)+tj(ma, di2);
}

int main()
{
    P di, ma;
    for (int i = 0 ; i < 21;i++)
        for (int k = 0; k < 21; k++)
            nums[i][k] = -1;
    scanf("%d %d", &di.x, &di.y);
    scanf("%d %d", &ma.x, &ma.y);
    printf("%llu\n", tj(ma, di));
    return 0;
}