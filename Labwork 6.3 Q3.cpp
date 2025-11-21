#include <stdio.h>

int main() {
    int N, i, j, result;

    printf("Enter a number N: ");
    scanf("%d", &N);

    printf("Multiplication table of %d:\n", N);

    for(i = 1; i <= 10; i++) {
        result = 0;
        for(j = 0; j < i; j++)
            result += N;
        printf("%d x %d = %d\n", N, i, result);
    }
}
