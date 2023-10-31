#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("     *\n");
	printf("    ***\n");
	printf("   *****\n");
	printf("  *******\n");
	printf(" *********\n");
	printf("\n");

	int i;
	int j;
	int k;
	
	for (j = 4; j >= 0; j--)
	{
		for (k = 0; k <= j; k++)
		{
			printf(" ");
		}
		for (i = 1; i <= 9 - 2 * j; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}