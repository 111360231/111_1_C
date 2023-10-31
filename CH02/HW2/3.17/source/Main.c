#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int account;
		printf("Enter account number (-1 to end): ");
		scanf_s("%d", &account);

		float bblance;
		float tcharges;
		float tcredits;
		float climit;
		float money;

		while (account != -1)
		{
			printf("Enter beginning blance: ");
			scanf_s("%f", &bblance);

			printf("Enter total charges: ");
			scanf_s("%f", &tcharges);

			printf("Enter total credits: ");
			scanf_s("%f", &tcredits);

			printf("Enter credit limit: ");
			scanf_s("%f", &climit);

			money = bblance + tcharges - tcredits;

			if (money > climit)
			{
				printf("Account:\t%d\n", account);
				printf("Credit limit:\t%.2f\n", climit);
				printf("Blance:\t\t%.2f\n", money);
				printf("Credit Limit Exceeded.\n");
			}

			printf("\nEnter account number (-1 to end): ");
			scanf_s("%d", &account);
		}
		return 0;
}