#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char change(char A);

int main(void)
{
	char S;
	printf("輸入大寫英文字母，會回傳小字母：");
	scanf_s("%c", &S);
	
	printf("小寫字母為:%c\n", change(S));

	system("pause");
	return 0;
}

char change(char A)
{
	return A+32;
}