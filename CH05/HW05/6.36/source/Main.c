#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void stringReverse(char a[], int i, int k);
char string[SIZE];

int main(void)
{
	printf("Enter a string (no longer than 19 characters): ");
	scanf_s("%19s", string, 20);
	stringReverse(string, SIZE, 0);
	printf("\n");
	system("pause");
	return 0;
}

void stringReverse(char a[], int i, int k)
{
	if (a[k] != '\0')
	{
		stringReverse(a, SIZE, k + 1);
		printf("%c", a[k]);
	}
}