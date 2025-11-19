#include<stdio.h>

int main()
{
	int marks;
	char grade;
	printf("Enter your marks:");
	scanf("%d" , &marks);
 	grade = (marks > 90) ?  'A' : 
			(marks > 75) ? 'B' :
			(marks > 60) ? 'C' :
			(marks > 35) ? 'D' : 'F';
		
	switch (grade){
		case 'A':
			printf("Your grade is A\nExcellent work");
			break;
		case 'B':
			printf("Your grade is B\nWell done");
			break;
		case 'C':
			printf("Your grade is C\nGood job");
			break;	
		case 'D':
			printf("Your grade is D\nYou passed , you could do better");
			break;
		default:
			printf("Your grade is F\nSorry , you failed");
			break;									
	}		
}


