#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf(" number\tsquare\tcube\n");

	int i1;
	int i2;
	int i3;
	for (i1 = 0; i1 <= 10; i1++)
	{
		printf(" ");
		printf("%d\t",i1);
		i2 = i1 * i1;
		printf("%d\t", i2);
		i3 = i2 * i1;
		printf("%d\n", i3);
	}
	return 0;
}