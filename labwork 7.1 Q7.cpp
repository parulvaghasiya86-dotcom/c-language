#include <stdio.h>

int main()
{
    int r, c;

    for(r = 0; r < 5; r++)
    {
        for(c = r; c >= 0; c--)
        {
            printf("%c ", 'A' + c);
        }
        printf("\n");
    }
}
