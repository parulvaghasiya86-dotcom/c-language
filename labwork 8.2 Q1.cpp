#include <stdio.h>

int main() {
    int r, c, i, j, sum=0;
    printf("Enter rows and columns:\n");
    scanf("%d %d", &r, &c);
    int a[r][c];

    printf("Enter elements:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            sum += a[i][j];
        }

    float avg = sum*1.0/(r*c);
    printf("Average of elements is: %f", avg);
}
