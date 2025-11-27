#include <stdio.h>

int main() {
    int m[5], s[5], so[5], total[5];
    float percent[5];
    int i;

    for(i = 0; i < 5; i++) {
        printf("Enter marks for Student %d (Math Science Social): ", i+1);
        scanf("%d %d %d", &m[i], &s[i], &so[i]);
        total[i] = m[i] + s[i] + so[i];
        percent[i] = total[i] / 3.0;
    }

    for(i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Maths: %d\n", m[i]);
        printf("Science: %d\n", s[i]);
        printf("Social: %d\n", so[i]);
        printf("Total: %d\n", total[i]);
        printf("Percentage: %.2f\n", percent[i]);
    }
}
