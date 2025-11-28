#include <stdio.h>

int main() {
    int a[5][5], i, j, sum=0;

    printf("Enter 25 elements for 5x5 array:\n");
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&a[i][j]);

    printf("Array with boundary elements marked (*):\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==0 || i==4 || j==0 || j==4){
                printf("*%d*\t", a[i][j]);
                sum += a[i][j];
            } else {
                printf("%d\t", a[i][j]);
            }
        }
        printf("\n");
    }

    printf("Sum of boundary elements: %d", sum);
}
