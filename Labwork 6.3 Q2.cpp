#include <stdio.h>

int main() {
    int N, i, s, factorial = 1, temp;

    printf("Enter a number N: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        temp = 0;
        for(s = 0; s < factorial; s++)
            temp += i;
        factorial = temp;
    }

    printf("Factorial of %d is: %d\n", N, factorial);
}
