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
    int max = a[0][0];
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            if(a[i][j] > max)
                max = a[i][j];
    printf("Largest number is: %d", max);
}

/*
	output:
	Enter rows and columns:
	2 3
	Enter 6 elements:
	45
	789
	65
	159
	357
	45
*/