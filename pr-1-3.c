#include <stdio.h>
int main()
{
    int f , s , t;
    printf("first angle:");
    scanf("%d" , &f);
    printf("second angle:");
    scanf("%d" , &s);
    t = 180 - (f + s);
    printf("third angle: %d", t);
}
