#include <stdio.h>
#include "function_pointers.h"

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