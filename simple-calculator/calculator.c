#include <stdio.h>

/**
 * main - simple calculator with menu loop
 *
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;
	int a, b, result;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	while (choice != 0)
	{
		printf("Choice: ");
		scanf("%d", &choice);

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}
		else if (choice == 1)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			result = a + b;
			printf("Result: %d\n", result);
		}
		else if (choice == 2)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			result = a - b;
			printf("Result: %d\n", result);
		}
		else if (choice == 3)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			result = a * b;
			printf("Result: %d\n", result);
		}
		else if (choice == 0)
		{
			printf("Bye!\n");
		}
	}

	return (0);
}
