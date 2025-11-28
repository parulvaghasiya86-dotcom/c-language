#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Negative numbers are:\n");
    for(i = 0; i < n; i++)
        if(arr[i] < 0)
            printf("%d ", arr[i]);
}

/*
	output:
	Enter the size of the array:
	5
	Enter 5 numbers:
	12
	-85
	-7594
	45
	9562
	Negative numbers are:
	-85 -7594
*/