#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_all - prints anything based on a format string
* @format: list of types of arguments passed
*/
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;

	char *str;

	char sep = 0;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		if (sep)
			printf(", ");

		if (format[i] == 'c')
			printf("%c", va_arg(args, int));
		if (format[i] == 'i')
			printf("%d", va_arg(args, int));
		if (format[i] == 'f')
			printf("%f", va_arg(args, double));
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
		}

		sep = 1;
		i++;
	}

	va_end(args);
	printf("\n");
}
