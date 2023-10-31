#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;

	for (a = 1; a < 500;a++)
	{
		for (b = a; b < 500; b++)
		{
			for (c = b; c <= 500; c++)
			{
				if (c*c == (a*a) + (b*b))
				{
					printf("%d\t%d\t%d\n", a, b, c);
				}
			}
		}
	}
	return 0;
}