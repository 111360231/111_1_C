#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf(" BMI VALUES\n");
	printf(" Underweight:\tless than 18.5\n");
	printf(" Normal:\tbetween 18.5 and 24.9\n");
	printf(" Overweight:\tbetween 25 and 29.9\n");
	printf(" Obese:\t\t30 or greater\n");
	printf("\n");

	float h;
	float w;
	float b;
	printf("INPUT YOUR HEIGHT(IN METERS):");
	scanf_s("%f", &h);
	printf("INPUT YOUR WEIGHT(IN KILORGRAMS):");
	scanf_s("%f", &w);

	b = w / (h*h);
	printf("\n");
	printf("YOUR BMI:");
	printf("%f\n", b);

	return 0;
}