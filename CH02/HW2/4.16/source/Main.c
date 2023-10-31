#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j,k;

	printf("(A)\n");
	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%s", "*");
		}
		printf("\n");
	}

	printf("(B)\n");
	for (i = 10; i >=1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%s", "*");
		}
		printf("\n");
	}

	printf("(C)\n");
	for (i = 10; i >= 1; i--)
	{
		for (k = 10 - i; k > 0; k--)
		{
			printf("%s"," ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("%s", "*");
		}
		printf("\n");
	}

	printf("(D)\n");
	for (i = 1; i <= 10; i++)
	{
		for (k = 10 - i; k > 0; k--)
		{
			printf("%s", " ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("%s", "*");
		}
		printf("\n");
	}

	return 0;
}