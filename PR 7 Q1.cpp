#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int remainder_func(int a, int b) {
    return a % b;
}

int main() {
    int choice, num1, num2;

    while(1) {
        printf("PRESS 1 TO EXECUTE THE +\n");
        printf("PRESS 2 TO EXECUTE THE -\n");
        printf("PRESS 3 TO EXECUTE THE *\n");
        printf("PRESS 4 TO EXECUTE THE /\n");
        printf("PRESS 5 TO EXECUTE THE %%\n");
        printf("PRESS 0 TO EXECUTE THE EXIT\n\n");

        printf("CHOOSEN CHOICE: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("WELCOME\n");
            break;
        }

        printf("ENTER THE FIRST NUMBER : ");
        scanf("%d", &num1);
        printf("ENTER THE SECOND NUMBER : ");
        scanf("%d", &num2);

        switch(choice) {
            case 1:
                printf("ADDITION OF THE %d AND THE %d IS %d\n\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("SUBTRACTION OF THE %d AND THE %d IS %d\n\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("MULTIPLICATION OF THE %d AND THE %d IS %d\n\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                if(num2 != 0)
                    printf("DIVISION OF THE %d AND THE %d IS %d\n\n", num1, num2, divide(num1, num2));
                else
                    printf("DIVISION BY ZERO NOT ALLOWED\n\n");
                break;
            case 5:
                if(num2 != 0)
                    printf("REMAINDER OF THE %d AND THE %d IS %d\n\n", num1, num2, remainder_func(num1, num2));
                else
                    printf("DIVISION BY ZERO NOT ALLOWED\n\n");
                break;
            default:
                printf("INVALID CHOICE! TRY AGAIN.\n\n");
        }
    }

    return 0;
}

/*
	output:
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT

	CHOOSEN CHOICE: 1
	ENTER THE FIRST NUMBER : 10
	ENTER THE SECOND NUMBER : 5
	ADDITION OF THE 10 AND THE 5 IS 15


	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT
	
	CHOOSEN CHOICE: 2
	ENTER THE FIRST NUMBER : 10
	ENTER THE SECOND NUMBER : 5
	SUBTRACTION OF THE 10 AND THE 5 IS 5
	
	
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT

	CHOOSEN CHOICE: 3
	ENTER THE FIRST NUMBER : 10
	ENTER THE SECOND NUMBER : 5
	MULTIPLICATION OF THE 10 AND THE 5 IS 50
		
	
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT
	
	CHOOSEN CHOICE: 4
	ENTER THE FIRST NUMBER : 10
	ENTER THE SECOND NUMBER : 5
	DIVISION OF THE 10 AND THE 5 IS 2
	
	
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT
	
	CHOOSEN CHOICE: 5
	ENTER THE FIRST NUMBER : 10
	ENTER THE SECOND NUMBER : 5
	REMAINDER OF THE 10 AND THE 5 IS 0
	
	
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT

	CHOOSEN CHOICE: 6
	INVALID CHOICE! TRY AGAIN.
	
	
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT
	
	CHOOSEN CHOICE: 4
	ENTER THE FIRST NUMBER : 10
	ENTER THE SECOND NUMBER : 0
	DIVISION BY ZERO NOT ALLOWED
	
	
	PRESS 1 TO EXECUTE THE +
	PRESS 2 TO EXECUTE THE -
	PRESS 3 TO EXECUTE THE *
	PRESS 4 TO EXECUTE THE /
	PRESS 5 TO EXECUTE THE %
	PRESS 0 TO EXECUTE THE EXIT
	
	CHOOSEN CHOICE: 0
	WELCOME

*/