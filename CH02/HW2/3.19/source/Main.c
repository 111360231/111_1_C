#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float principal;
	float rate;
	int days;
	float charge;

	printf("Enter loan principal (-1 to end): ");
	scanf_s("%f", &principal);

	while (principal != -1)
	{
		printf("Enter interest rate: ");
		scanf_s("%f", &rate);

		printf("Enter term of the loan days: ");
		scanf_s("%d", &days);

		charge = (principal*rate*days) / 365;

		printf("The interest charge is $%.2f", charge);

		printf("\n\nEnter loan principal (-1 to end): ");
		scanf_s("%f", &principal);
	}
	return 0;
}