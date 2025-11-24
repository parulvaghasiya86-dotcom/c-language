#include <stdio.h>
#include <conio.h>  // Windows-only: for kbhit() and getch()
#include <stdlib.h>
#include <windows.h> // for Sleep()
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_SNAKE 100

typedef struct {
    int x, y;
} Point;

void printBoard(Point snake[], int length, Point food) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int printed = 0;
            if (food.x == x && food.y == y) {
                printf("*");
                printed = 1;
            }
            for (int i = 0; i < length; i++) {
                if (snake[i].x == x && snake[i].y == y) {
                    printf(i == 0 ? "O" : "o");
                    printed = 1;
                    break;
                }
            }
            if (!printed) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Point snake[MAX_SNAKE];
    int snakeLength = 3;
    int dir = 1; // 0=up,1=right,2=down,3=left
    int gameOver = 0;
    int score = 0;

    Point food;

    srand(time(0));

    // Initialize snake in middle
    for (int i = 0; i < snakeLength; i++) {
        snake[i].x = WIDTH / 2 - i;
        snake[i].y = HEIGHT / 2;
    }

    // Place first food
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;

    while (!gameOver) {
        system("cls"); // clear screen (Windows)

        printBoard(snake, snakeLength, food);
        printf("Score: %d\n", score);
        printf("Use W/A/S/D to move\n");

        // Input
        if (kbhit()) {
            char key = getch();
            if ((key == 'w' || key == 'W') && dir != 2) dir = 0;
            if ((key == 'd' || key == 'D') && dir != 3) dir = 1;
            if ((key == 's' || key == 'S') && dir != 0) dir = 2;
            if ((key == 'a' || key == 'A') && dir != 1) dir = 3;
        }

        // Move snake
        Point next = snake[0];
        if (dir == 0) next.y--;
        if (dir == 1) next.x++;
        if (dir == 2) next.y++;
        if (dir == 3) next.x--;

        // Check collisions
        if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT) gameOver = 1;
        for (int i = 0; i < snakeLength; i++)
            if (snake[i].x == next.x && snake[i].y == next.y) gameOver = 1;

        if (gameOver) break;

        // Move body
        for (int i = snakeLength; i > 0; i--) snake[i] = snake[i - 1];
        snake[0] = next;

        // Check food
        if (snake[0].x == food.x && snake[0].y == food.y) {
            snakeLength++;
            score++;
            food.x = rand() % WIDTH;
            food.y = rand() % HEIGHT;
        }

        Sleep(200); // wait 0.2 sec
    }

    printf("Game Over! Final Score: %d\n", score);
    return 0;
}
