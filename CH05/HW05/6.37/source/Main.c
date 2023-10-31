#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void recursiveMaximum(char b[], int n);
int a[SIZE] = { 2,6,4,8,10,12,89,68,45,37 };

int main(void)
{
	printf("Data items in original order:\n");
	for (size_t i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n\n");
	recursiveMaximum(a, 10);
	printf("Data items in ascending order:\n");
	for (size_t i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n\n");
	printf("Maximum number is : %d\n", a[SIZE - 1]);
	system("pause");
	return 0;
}

void recursiveMaximum(char b[], int n)
{
	if (n == 1)
	{
		return;
	}
	else
	{
		for (int j = 0; j < n-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
		recursiveMaximum(a, n - 1);
	}
}