#include<stdio.h>

int main()
{
    int r, c, sp;
    for(r=5; r>=1; r--)
    {
        for(c=1; c<=r; c++){printf("%d", c);}
        for(sp=1; sp<=2*(5-r); sp++){printf(" ");}
        for(c=r; c>=1; c--){printf("%d", c);}
        printf("\n");
    }
}
