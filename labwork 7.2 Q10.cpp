#include<stdio.h>

int main()
{
    int r, c, sp;
    for(r=1; r<=5; r++)
    {
        for(sp=1; sp<=5-r; sp++)
        {
            printf(" ");
        }
        for(c=1; c<=r; c++)
        {
            printf("%d", c);
        }
        for(c=r-1; c>=1; c--)
        {
            printf("%d", c);
        }
        printf("\n");
    }
}
