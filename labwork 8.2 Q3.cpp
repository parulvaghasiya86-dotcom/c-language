#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &r, &c);
    
    int a[r][c];
    printf("Enter %d elements:\n", r*c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    int sum = 0;
    for(i=0;i<r;i++)
        sum += a[i][c-1-i];

    printf("Sum of anti-diagonal elements: %d", sum);
}
