#include <stdio.h>

int main() {
    int i, j, n = 5, space;

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= i; j++)
            printf("%d", j);

        if (i == 1)
            space = 8;
        else
            space = 2*(n-i);

        for (j = 1; j <= space; j++)
            printf(" ");

        for (j = i; j >= 1; j--)
            printf("%d", j);

        printf("\n");
    }
}
/*
	output:
	1        1
    12      21
    123    321
    1234  4321
    1234554321
*/