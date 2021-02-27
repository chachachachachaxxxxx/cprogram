#include <stdio.h>
#include <stdlib.h>

typedef struct ditan{
    int x;
    int y;
    int w;
    int l;
} DT;

int ifin(int a, int b, DT* d)
{
    if (a >= d->x && a <= d->x+d->w && b >= d->y && b <= d->y+d->l)
        return 1;
    return 0;
}

int main()
{
    int dnum;
    scanf("%d", &dnum);
    DT *d;
    d = (DT*)malloc(dnum*sizeof(DT));
    for (int i = 0 ; i < dnum; i++)
    {
        scanf("%d %d %d %d", &(d+i)->x, &(d+i)->y, &(d+i)->w, &(d+i)->l);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    int wz = -1;
    for (int i = dnum; i >= 1; i--)
    {
        if (ifin(a, b, d+i-1))
        {
            wz = i;
            break;
        }
    }
    free(d);
    printf("%d\n", wz);
    return 0;
}