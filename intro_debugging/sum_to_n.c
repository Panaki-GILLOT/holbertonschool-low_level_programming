#include <stdio.h>

/**
 * sum_to_n - returns the sum of all integers from 1 to n
 * @n: the last number to sum
 *
 * Return: sum of numbers from 1 to n
 */
int sum_to_n(int n)
{
    int i;
    int sum = 0;

    for (i = 1; i <= n; i++)
        sum += i;

    return sum;
}

int main(void)
{
    printf("%d\n", sum_to_n(10));
    return 0;
}
