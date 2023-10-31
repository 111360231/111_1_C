#include <stdio.h>
#include <stdlib.h>

void staticArrayInit(void);
void automaticArrayInit(void);

int main(void)
{
	printf("First call to each function:\n");
	staticArrayInit();
	automaticArrayInit();

	printf("\n\nSecond call to each function:\n");
	staticArrayInit();
	automaticArrayInit();
	printf("\n");
	system("pause");
	return 0;
}

void staticArrayInit(void)
{
	static int array1[3];
	int i;

	printf("\nValue on emtering staticArrayInit:\n");

	for (i = 0; i <= 2; i++)
		printf("array1[%d] = %d ", i, array1[i]);

	printf("\nValue on entering staricArrayInit:\n");

	for (i = 0; i <= 2; i++)
		printf("array1[%d] = %d ", i, array1[i] += 5);
}

void automaticArrayInit(void)
{
	int array2[3] = { 1,2,3 };
	int i;

	printf("\n\nValue on entering automaticArrayInit:\n");

	for (i = 0; i <= 2; i++)
		printf("array2[%d] = %d ", i, array2[i]);

	printf("\nValue on rntering automaticArrayInit:\n");

	for (i = 0; i <= 2; i++)
		printf("array2[%d] = %d ", i, array2[i] += 5);
}