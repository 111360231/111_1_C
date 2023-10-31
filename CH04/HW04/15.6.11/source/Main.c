#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void)
{
	int a[SIZE] = { 2,6,4,8,10,12,89,68,45,37 };
	int counter1 = SIZE, counter2 = 0;

	printf("Data items in original order\n");
	for (size_t i = 0; i < SIZE; ++i)
	{
		printf("%4d", a[i]);
	}

	for (unsigned int pass = 1; pass < SIZE; ++pass)
	{
		counter2 = 0;
		for (size_t i = 0; i < counter1 - 1; ++i)
		{
			if (a[i] > a[i + 1])
			{
				int hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
				counter2++;
			}
		}
		counter1--;
		if(counter2==0)
		{
			break;
		}
	}
	printf("\nData items ascending order\n");

	for (size_t i = 0; i < SIZE; ++i)
	{
		printf("%4d", a[i]);
	}
	printf(" ");
	system("pause");
	return 0;
}