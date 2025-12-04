#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // s= string
    int f[26] = {0}; //f = frequency

    printf("Enter a string: ");
    gets(s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            f[s[i] - 'a']++;
        }
    }

    puts("\nLetter Frequencies:");
    for (int i = 0; i < 26; i++) {
        if (f[i] > 0) {
            printf("%c : %d\n", i + 'a', f[i]);
        }
    }
}

/*
	output:
	Enter a string: civic

	Letter Frequencies:
	c : 2
	i : 2
	v : 1
*/