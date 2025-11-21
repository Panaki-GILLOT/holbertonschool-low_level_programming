#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char *s;
	char *sep = "";

	va_start(ap, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(ap, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(ap, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(ap, double));
				sep = ", ";
				break;
			case 's':
				s = va_arg(ap, char *);
				if (!s)
					s = "(nil)";
				printf("%s%s", sep, s);
				sep = ", ";
				break;
			default:
				break;
		}
		i++;
		while (0)
		{}
	}
	if (sep)
	{}
	printf("\n");
	va_end(ap);
}
