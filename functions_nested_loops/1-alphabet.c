#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Description: Uses _putchar to print all letters from 'a' to 'z',
 * followed by a new line.
 * Return: void
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		_putchar(c);

	_putchar('\n');
}
