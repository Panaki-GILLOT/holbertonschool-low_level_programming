#include <stdio.h>
#include "function_pointers.h"

int is_positive(int n)
{
    return (n > 0);
}

int is_98(int n)
{
    return (n == 98);
}

int main(void)
{
    int array[] = {0, -5, -3, 98, 402};
    int index;

    index = int_index(array, 5, is_positive);
    printf("First positive index: %d\n", index);

    index = int_index(array, 5, is_98);
    printf("Index of 98: %d\n", index);

    return (0);
}
