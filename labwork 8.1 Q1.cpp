#include <stdio.h>

int main() {
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the array elements :\n");
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    printf("Length of the array : %d\n", n);
}
