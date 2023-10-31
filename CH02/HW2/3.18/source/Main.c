#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float sdollars;
	printf("Enter sales in dollars (-1 to end): ");
	scanf_s("%f", &sdollars);

	float salary;

	while (sdollars != -1)
	{
		salary = 200 + (sdollars*0.09);
		printf("Salary is: $%.2f", salary);

		printf("\n\nEnter sales in dollars (-1 to end): ");
		scanf_s("%f", &sdollars);
	}
	return 0;
}