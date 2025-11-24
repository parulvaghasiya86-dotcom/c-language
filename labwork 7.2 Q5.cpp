#include<stdio.h>

int main()
{
    int r, c, sp;
    for(r=5; r>=1; r--)
    {
        for(sp=5; sp>r; sp--)
        {
            printf(" ");
        }
        for(c=r; c>=1; c--)
        {
            printf("%d", c);
        }
        printf("\n");
    }
}
