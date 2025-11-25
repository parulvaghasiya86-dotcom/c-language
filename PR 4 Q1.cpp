#include <stdio.h>

int main() {
    int s = 41;

    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", s + j);
        }
        printf("\n");
    }
}

/*
	output:
	41
	41 42
	41 42 43
	41 42 43 44
	41 42 43 44 45
*/