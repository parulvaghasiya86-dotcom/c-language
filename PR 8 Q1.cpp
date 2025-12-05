#include <stdio.h>

int main() {
    char s[100];
    char *p;
    int length = 0;

    printf("Enter string: ");
    gets(s);

    p = s;
    for (; *p; p++) {
        length++;
    }

    printf("Length = %d\n", length);
}

/*
	Output:
	Enter string: hello world
	Length = 11
*/