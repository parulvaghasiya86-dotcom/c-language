#include <stdio.h>

int main()
{
    char n[50];
    int i, j;

    printf("Enter your name: ");
    scanf("%s", n); 

   
    j = 0;
    while(n[j] != '\0')
        j = j + 1;
    j = j - 1;

    for(i = 0; i < j; i = i + 1, j = j - 1)
    {
        if(n[i] != n[j])
        {
            printf("Not a palindrome\n");
            return 0;  
        }
    }

    printf("Palindrome\n");
    return 0;  
}

/*
	output:
	Enter your name: shyam
	Not a palindrome
*/