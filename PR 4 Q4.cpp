#include <stdio.h>

int main() {
    int i, j, s, x;

    for (i = 0; i < 5; i++) {

        for (s = 0; s < i * 2; s++) {
            printf(" ");
        }

        if (i % 2 == 0)
            x = 1;
        else
            x = 0;

        for (j = 0; j < 5 - i; j++) {
            printf("%d ", x);
            if (x == 1)
                x = 0;
            else
                x = 1;
        }

        printf("\n");
    }
}
/*
	output:
	1 0 1 0 1
      0 1 0 1
        1 0 1
          0 1
            1
*/