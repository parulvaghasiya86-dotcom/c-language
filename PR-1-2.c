#include<stdio.h>

int main()
{
	int salary, hra, da, ta, g_salary;
	
	printf("Enter salary: ");
	scanf("%d", &salary);
	
	hra = (salary * 10) / 100;
	da = (salary * 5) / 100;
	ta = (salary * 8) / 100;
	
	g_salary = salary + hra + da + ta;
	
	printf("Gross Salary is: %d", g_salary);

}