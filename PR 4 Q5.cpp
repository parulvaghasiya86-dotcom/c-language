#include <stdio.h>

int main() {
    int i, j, n = 5;

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (j = n - i + 1; j <= n; j++) {
            printf("%d", j);
        }

        for (j = n - 1; j >= n - i + 1; j--) {
            printf("%d", j);
        }

        printf("\n");
    }
}
/*
	output:
	5
   454
  34543
 2345432
123454321

*/