#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double rate = 0.1;
	double principal = 5000;

	for (rate; rate < 0.125; rate = rate + 0.005)
	{
		printf("rate:");
		printf("%2.1f\n", rate * 100);
		printf("%4s%21s\n", "Year", "Amount in deposit");
		for (unsigned int year = 1; year <= 15; year++)
		{
			double amount = principal * pow(1.0 + rate, year);
			printf("%4u%21.2f\n", year, amount);
		}
		printf("\n");
	}
	return 0;
}