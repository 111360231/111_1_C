#include <stdio.h>
#include <stdlib.h>

int function(int m, int n);
int a, b;
int main(void)
{
	printf("��J��ӥ���ơA�|��X��̤p������:");
	scanf_s("%d%d", &a, &b);
	printf("�̤p�����Ƭ�:%d\n", function(a, b));
	system("pause");
	return 0;
}

int function(int m, int n)
{
	int r;
	while (n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	m = (a*b) / m;
	return m;
}