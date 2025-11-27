#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("\nArray elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nSum: %d", sum);
    printf("\nNumber of elements: %d\n", n);
}
