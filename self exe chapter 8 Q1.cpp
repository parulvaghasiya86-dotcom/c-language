#include <stdio.h>

int main() {
    int n, i;

    printf("Enter array size: ");
    scanf("%d", &n);

    int A[n], B[n];

    printf("Enter %d values for A:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter %d values for B:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &B[i]);

    printf("\nA  B\n");
    for(i = 0; i < n; i++)
        printf("%d  %d\n", A[i], B[i]);
}
