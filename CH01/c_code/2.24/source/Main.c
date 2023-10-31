#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	printf("INPUT A NUMBER,\n");
	printf("I WILL TELL YOU IS ODD OR EVEN.\n");
	scanf_s("%d", &a);

	if (a % 2 == 0)
	{
		printf("%d", a);
		printf(" is EVEN.\n");
	}
	else
	{
		printf("%d", a);
		printf(" is ODD.\n");
	}
	
	return 0;

}