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
