#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: Name of the file
 * @text_content: NULL-terminated string to add at the end
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t bytes_written;
	int fd, len = 0;

	if (!filename)
		return (-1);

	/* Calculate length of text_content */
	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	/* Open file for writing, do not create if it doesn't exist, append at end */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If there is text to write, write it */
	if (len > 0)
	{
		bytes_written = write(fd, text_content, len);
		if (bytes_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
