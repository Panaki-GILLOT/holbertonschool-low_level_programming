#include <stdio.h>

/**
 * main - prints the program's name
 * @argc: argument count (not used)
 * @argv: argument vector (argv[0] is the program name)
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
