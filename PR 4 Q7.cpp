#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 5; j++) {
            if (i == 2 && j > 1 && j < 5)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }

    for (i = 1; i <= 2; i++)
        printf("*\n");
}
/*
	output:
	*****
    *   *
	*****
	*
	*
*/