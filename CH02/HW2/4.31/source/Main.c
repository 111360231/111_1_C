#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k;
	for (i = 4; i >= 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 9 - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 9 - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}