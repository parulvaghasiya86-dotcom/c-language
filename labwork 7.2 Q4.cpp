#include<stdio.h>

int main()
{
    int r, c, sp;
    for(r=1; r<=5; r++)
    {
        for(sp=1; sp<r; sp++) printf(" ");
        for(c=r; c<=5; c++) printf("%d",(c+r)%2);
        printf("\n");
    }
}
