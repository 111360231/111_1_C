#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

int main(void)
{
	unsigned int dice[SIZE] = { 0 };
	int face1,face2,sum;
	srand(time(NULL));

	for (unsigned int roll = 1; roll <= 36000; roll++)
	{
		face1 = 1 + rand() % 6;
		face2 = 1 + rand() % 6;
		++dice[face1+face2];
	}

	printf("Sum%17s\n", "Frequncy");
	for (sum = 2; sum <= 12; sum++)
	{
		printf("%3d%17d\n", sum, dice[sum]);
	}
	system("pause");
	return 0;
}