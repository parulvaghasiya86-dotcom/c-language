#include <stdio.h>

void cubeArray(int rows, int cols, int a[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = a[i][j] * a[i][j] * a[i][j];
        }
    }
}

int main() {
    int a[10][10];
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter %d elements:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    cubeArray(rows, cols, a);

    printf("Cubed elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/*
	Output:
	Enter number of rows: 2
	Enter number of columns: 3
	Enter 6 elements:
	Enter element a[0][0]: 78
	Enter element a[0][1]: 58
	Enter element a[0][2]: 78
	Enter element a[1][0]: 45
	Enter element a[1][1]: 557
	Enter element a[1][2]: 789
	Cubed elements:
	474552 195112 474552
	91125 172808693 49116906
*/