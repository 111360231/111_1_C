#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long long int  first = 0, second = 1, x;

	while (1)
	{
		x = first + second;
		first = second;
		second = x;
		if (first > second)
		{
			break;
		}
	}
	printf("unsigned long long int ��ƫ��A�O�B�����ƦC�̤j�Ȭ�: %llu\n\n", first);
	system("pause");
	return 0;
}
