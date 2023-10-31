#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	printf("INPUT 2 NUMBERS,\n");
	printf("I WILL TELL YOU IF THE FIRST NUMBER IS A MULTIPLE OF THE SECOND.\n");
	scanf_s("%d%d", &a, &b);

	if (a%b == 0)
	{
		printf("%d", a);
		printf(" IS A MULTIPLE OF ");
		printf("%d\n", b);
	}
	else
	{
		printf("%d", a);
		printf(" IS NOT A MULTIPLE OF ");
		printf("%d\n", b);
	}
	return 0;
}