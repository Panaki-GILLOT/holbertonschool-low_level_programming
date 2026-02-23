#include <stdio.h>

/**
 * main - prints the alphabet in lowercase then uppercase
 *
 * Return: Always 0
 */
int main(void)
{
	char c;

	/* lowercase letters */
	for (c = 'a'; c <= 'z'; c++)
		putchar(c);

	/* uppercase letters */
	for (c = 'A'; c <= 'Z'; c++)
		putchar(c);

	putchar('\n');

	return (0);
}
