#include <stdio.h>
#include <stdlib.h>
int length;
int breadth;
int i, j;
int a;

int main(void)
{
	int length;
	int breadth;
	int i, j;
	int a;

	printf("breadth: ");
	scanf_s("%d", &breadth);
	printf("length: ");
	scanf_s("%d", &length);

	for (i = 1; i <= breadth; i++)
	{
		printf("+");
	}
	printf("\n");

	for (a = 1; a <= length - 2; a++)
	{
		printf("+");
		for (j = 1; j <= breadth - 2; j++)
		{
			printf(" ");
		}
		printf("+\n");
	}

	for (i = 1; i <= breadth; i++)
	{
		printf("+");
	}
	printf("\n");
	return 0;
}