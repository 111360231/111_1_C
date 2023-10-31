#include <stdio.h>
#include <stdlib.h>

int exponent(int a, int c);
int main(void)
{
	int b, e;
	printf("求x的n次方\n");
	printf("輸入底數:");
	scanf_s("%d", &b);
	printf("輸入次方:");
	scanf_s("%d", &e);
	
	printf("x的n次方為:%d\n", exponent(b, e));

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