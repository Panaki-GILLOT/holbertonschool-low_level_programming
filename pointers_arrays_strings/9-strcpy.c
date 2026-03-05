#include "main.h"

/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: buffer where the string will be copied
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* Copier le caractère de fin */
	dest[i] = '\0';

	return (dest);
}
