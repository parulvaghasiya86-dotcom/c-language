#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &r, &c);

    int a[r][c], b[r][c], sum[r][c];

    printf("Enter elements of first array:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    printf("Enter elements of second array:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&b[i][j]);

    printf("Sum of the arrays:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}
