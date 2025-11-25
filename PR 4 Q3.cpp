#include<stdio.h>

int main()
{
    int r , c , sp;
    for(r=5; r>=1; r--)
    {
        for(sp=1; sp<r; sp++)
        {
            printf(" ");
        }
        for(c=r; c<=5; c++)
        {
            printf("%d", c);
        }
        printf("\n");
    }
}
/*
	output:
    	5
   	   45
  	  345
     2345
	12345
*/