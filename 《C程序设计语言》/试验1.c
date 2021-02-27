#include <stdio.h>
#define printpn(ws, xs) printf("%."#ws"f\n", xs)

int main()
{
    printpn(2, 1.234);
    return 0;
}