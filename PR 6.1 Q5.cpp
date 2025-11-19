#include<stdio.h>

int main()
{
    int start , end ;
    printf("Enter the starting leap year:");
    scanf("%d" , &start);

    printf("Enter the ending leap year:");
    scanf("%d" , &end);

    while(start <= end) {
        printf("%d ", start);
        start++;
    }
}