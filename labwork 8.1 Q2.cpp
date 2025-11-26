#include <stdio.h>

int main() {
    int n, i, sum = 0;
    float average;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
        sum = sum + A[i];
    }

    printf("\nArray elements are:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    average = (float)sum / n;

    printf("Length of the array: %d\n", n);
    printf("Average of the array elements: %f\n", average);
}
