#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int hours;
	float rate;
	float salary;

	printf("Enter # of hours worked (-1 to end): ");
	scanf_s("%d", &hours);

	while (hours != -1)
	{
		printf("Enter hourly rate of the worker ($00.00): ");
		scanf_s("%f", &rate);

		if (hours > 40)
		{
			hours = hours - 40 ;
			salary = (40 * rate) + (hours*rate*1.5);
		}
		else
		{
			salary = hours * rate;
		}
		printf("Salary is $%.2f", salary);

		printf("\n\nEnter # of hours worked (-1 to end): ");
		scanf_s("%d", &hours);
	}
	return 0;
}