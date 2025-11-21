#include <stdio.h>

int main() {
    int number;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number == 0) {
        count = 1;
    }

    if (number < 0) {
        number = -number;
    }

    while (number != 0) {
        number = number / 10;
        count = count + 1;
    }

    printf("Total digits: %d", count);
}
