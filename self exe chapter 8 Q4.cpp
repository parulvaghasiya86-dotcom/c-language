#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEven numbers are: ");
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }

    printf("\nSum of even numbers: %d\n", sum);
}
