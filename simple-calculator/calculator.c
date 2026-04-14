#include <stdio.h>

/**
 * clear_input - clears stdin buffer
 */
void clear_input(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}

/**
 * main - simple calculator with input validation
 *
 * Return: Always 0
 */
int main(void)
{
	int choice = -1;
	int a, b;
	float result;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	while (choice != 0)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid choice\n");
			clear_input();
			continue;
		}

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}
		else if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
			{
				printf("Invalid number\n");
				clear_input();
				continue;
			}

			printf("B: ");
			if (scanf("%d", &b) != 1)
			{
				printf("Invalid number\n");
				clear_input();
				continue;
			}

			if (choice == 1)
				printf("Result: %d\n", a + b);
			else if (choice == 2)
				printf("Result: %d\n", a - b);
			else if (choice == 3)
				printf("Result: %d\n", a * b);
			else if (choice == 4)
			{
				if (b == 0)
					printf("Error: division by zero\n");
				else
				{
					result = (float)a / b;
					printf("Result: %.1f\n", result);
				}
			}
		}
		else if (choice == 0)
		{
			printf("Bye!\n");
		}
	}

	return (0);
}
