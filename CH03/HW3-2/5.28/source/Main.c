#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char change(char A);

int main(void)
{
	char S;
	printf("��J�j�g�^��r���A�|�^�Ǥp�r���G");
	scanf_s("%c", &S);
	
	printf("�p�g�r����:%c\n", change(S));

	system("pause");
	return 0;
}

char change(char A)
{
	return A+32;
}