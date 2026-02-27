#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the starting number
 *
 * Description: Numbers are separated by a comma followed by a space.
 * The sequence is printed in order up to 98.
 */
void print_to_98(int n)
{
    if (n <= 98)
    {
        while (n <= 98)
        {
            printf("%d", n);
            if (n != 98)
                printf(", ");
            n++;
        }
    }
    else
    {
        while (n >= 98)
        {
            printf("%d", n);
            if (n != 98)
                printf(", ");
            n--;
        }
    }
    printf("\n");
}
