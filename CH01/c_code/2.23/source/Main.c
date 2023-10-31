#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	int c;
	int temp;

	printf("INPUT 3 NUMBERS,\n");
	printf("I WILL TELL YOU THE LARGEST AND THE SMALLEST.\n");
	scanf_s("%d%d%d", &a, &b, &c);

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	printf("LARGEST NUMBER:");
	printf("%d\n", c);
	printf("SMALLEST NUMBER:");
	printf("%d\n", a);

	return 0;
}