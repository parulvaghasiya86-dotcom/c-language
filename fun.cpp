#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    double prize;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 200
    number = rand() % 200 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 200.\n");
    printf("Try to guess it!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        // Check if the guess is higher than the number
        if (guess > number) {
            printf("Too high! Don't give up, try a smaller number.\n\n");
        } 
        // Check if the guess is lower than the number
        else if (guess < number) {
            printf("Too low! Keep going, try a bigger number.\n\n");
        } 
        // Correct guess
        else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

            // Calculate prize (bigger prize for fewer attempts)
            prize = 5000.0 / attempts; 
            printf("You have won $%.2f!\n", prize);

            // Extra encouragement
            if (attempts <= 5) {
                printf("Amazing! You guessed it very quickly!\n");
            } else if (attempts <= 10) {
                printf("Great job! You figured it out with some effort.\n");
            } else {
                printf("Good perseverance! You got it in the end!\n");
            }
        }

    } while (guess != number);

    return 0;
}
