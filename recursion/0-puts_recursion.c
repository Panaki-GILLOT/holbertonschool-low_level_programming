#include "main.h"
#include <stdio.h>

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: string to print
 */
void _puts_recursion(char *s)
{
    if (*s == '\0')  /* condition d'arrêt : fin de chaîne */
    {
        _putchar('\n');
        return;
    }

    _putchar(*s);         /* affiche le caractère courant */
    _puts_recursion(s + 1); /* appel récursif sur le reste de la chaîne */
}