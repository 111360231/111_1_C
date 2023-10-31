#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float a;
	printf("Total kilometers driven per day:");
	scanf_s("%f", &a);

	float b;
	printf("Cost per liter of gasoline:");
	scanf_s("%f", &b);

	float c;
	printf("Average kilometers per liter:");
	scanf_s("%f", &c);

	float d;
	printf("Parking fees per day:");
	scanf_s("%f", &d);

	float e;
	printf("Tolls per day:");
	scanf_s("%f", &e);

	float m;
	printf("\n");
	m = ((a / c)*b) + d + e;

	int m1;
	m1 = m;
	if (m - m1 < 0.5)
	{
		m = m + 1;
	}

	printf("Total cost:");
	printf("NT");
	printf(("%1.0f\n"), m);
	
	return 0;
}