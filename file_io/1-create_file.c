#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - creates a file
 * @filename: name of the file
 * @text_content: content to write
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, written;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		len = strlen(text_content);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		written = write(fd, text_content, len);
		if (written == -1 || written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
