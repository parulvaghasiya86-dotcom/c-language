#include <stdio.h>

int main() {
    char s1, s2, s3;
    char letters;

    printf("Enter first alphabet to skip: ");
    scanf(" %c", &s1);

    printf("Enter second alphabet to skip: ");
    scanf(" %c", &s2);

    printf("Enter third alphabet to skip: ");
    scanf(" %c", &s3);

    for (letters = 'a'; letters <= 'z'; letters++) {
        if (letters == s1 || letters == s2 || letters == s3) {
            continue;
        }
        printf("%c ", letters);
    }
}
