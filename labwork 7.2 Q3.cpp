#include<stdio.h>

int main()
{
    int r, c, sp;
    for(r=5; r>=1; r--)
    {
        for(sp=1; sp<r; sp++)
        {
            printf(" ");
        }
        for(c=1; c<=6-r; c++)
        {
            printf("%d", r);
        }
        printf("\n");
    }
}
