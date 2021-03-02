#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

int narcissistic(int number)
{
    int a[20];
    int w = 0;
    int n1 = number;
    int sum = 0;
    while (n1)
    {
        a[w] = n1 % 10;
        w++;
        n1 /= 10;
    }
    for (int i = 0; i < w; i++)
    {
        int y = 1;
        for (int j = 0; j < w; j++)
            y *= a[i];
        sum += y;
    }
    if (sum == number)
        return 1;
    else 
        return 0;
}

void PrintN(int m, int n)
{
    for(int i = m+1; i < n; i++)
        if(narcissistic(i))
            printf("%d\n", i);
}