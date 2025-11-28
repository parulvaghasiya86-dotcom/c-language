#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns:\n");
    scanf("%d %d", &r, &c);
    int a[r][c];
    printf("Enter %d elements:\n", r*c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    printf("Matrix with row sums:\n");
    for(i=0;i<r;i++){
        int sum=0;
        for(j=0;j<c;j++){
            printf("%d\t",a[i][j]);
            sum+=a[i][j];
        }
        printf("| %d\n", sum);
    }

    printf("Column sums:\n");
    for(j=0;j<c;j++){
        int sum=0;
        for(i=0;i<r;i++)
            sum+=a[i][j];
        printf("%d\t",sum);
    }
}

/*
	output:
	Enter rows and columns:
	3 3
	Enter 9 elements:
	56
	85
	954
	-95
	685
	54
	85
	469
	95
	Matrix with row sums:
	56      85      954     | 1095
	-95     685     54      | 644
	85      469     95      | 649
	Column sums:
	46 	    1239    1103
*/