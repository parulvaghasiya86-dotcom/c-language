#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns:\n");
    scanf("%d %d", &r, &c);
    int a[r][c];
    printf("Enter %d elements:\n", r*c);
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Transpose of the matrix:\n");
    for(j = 0; j < c; j++) {
        for(i = 0; i < r; i++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

/*
	output:
	Enter rows and columns:
	3
	3
	Enter 9 elements:
	45
	69
	86
	321
	753
	85
	96
	741
	3214
	Transpose of the matrix:
	45      321     96
	69      753     741
	86      85      3214
*/