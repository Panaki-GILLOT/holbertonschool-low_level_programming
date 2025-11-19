#include <stdio.h>
#include "function_pointers.h"

void print_upper(char *s)
{
    while (*s)
    {
        putchar(toupper(*s));
        s++;
    }
    putchar('\n');
}

void print_normal(char *s)
{
    printf("%s\n", s);
}

int main(void)
{
    print_name("Ghost", print_normal);
    print_name("Ghost", print_upper);

    return 0;
}

int is_98(int elem)
{
	return (elem == 98);
}

int main(void)
{
	int array[] = {10, 20, 98, 5, 2};
	int index;

	index = int_index(array, 5, is_98);
	printf("Index: %d\n", index);

	return (0);
}