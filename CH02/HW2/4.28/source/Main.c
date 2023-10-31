#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	printf("Enter Account Number(-1 to end): ");
	scanf_s("%d", &a);

	while (a != -1)
	{
		switch (a)
		{
		case 1:
			float one;
			printf("Enter Weekly Salary: ");
			scanf_s("%f", &one);
			printf("Total Salary: %.2f\n", one);
			break;


		case 2:
			float two1;
			printf("Enter How Many Hours of Work: ");
			scanf_s("%f", &two1);
			int two2;
			printf("Enter Hourly Salary: ");
			scanf_s("%d", &two2);

			float two3;
			if (two1 > 40)
			{
				two3 = (40 * two2) + ((two1 - 40)*1.5*two2);
			}
			else
			{
				two3 = two1 * two2;
			}
			printf("Total Salary: %.2f\n", two3);
			break;


		case 3:
			float three1;
			printf("Enter Sales Dollars: ");
			scanf_s("%f", &three1);

			float three2;
			three2 = 250 + (three1*0.057);
			printf("Total Salary: %.2f\n", three2);
			break;


		case 4:
			int four1;
			printf("Enter How Many Item Did You Finished: ");
			scanf_s("%d", &four1);
			float four2;
			printf("Enter How Much Does An Item Worth: ");
			scanf_s("%f", &four2);

			float four3;
			four3 = four1 * four2;
			printf("Total Salary: %.2f\n", four3);
			break;

		default:
			printf("\nOnly Enter 1~4.");
			break;
		}
		printf("\nEnter Account Number(-1 to end): ");
		scanf_s("%d", &a);
	}
	return 0;
}