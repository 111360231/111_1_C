#include <stdio.h>
#include <stdlib.h>

int exponent(int a, int c);
int main(void)
{
	int b, e;
	printf("�Dx��n����\n");
	printf("��J����:");
	scanf_s("%d", &b);
	printf("��J����:");
	scanf_s("%d", &e);
	
	printf("x��n���謰:%d\n", exponent(b, e));

	system("pause");
	return 0;
}

int exponent(int a, int c)
{
	int t;
	int h = 1;
	for (t = 1; t <= c; t++)
	{
		h=h*a;
	}
	return h;
}