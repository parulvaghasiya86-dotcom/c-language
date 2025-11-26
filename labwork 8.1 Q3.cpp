#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    int A[n], B[n], C[n];

    printf("Enter elements of first array:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter elements of second array:\n");
    for (i = 0; i < n; i++) {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    for (i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }

    printf("\nArray C = ");
    for (i = 0; i < n; i++) {
        printf("%d ", C[i]);
    }
}
