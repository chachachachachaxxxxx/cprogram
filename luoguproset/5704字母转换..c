#include <stdio.h>
int main()
{
    char a;
    scanf("%c",&a);
    if (a >= 'a' && a <= 'z')
        a -= 32;
    printf("%c\n",a);
    return 0;
}