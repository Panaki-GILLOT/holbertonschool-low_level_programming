#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/**
 * main - Copies the content of one file to another
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success, exit with specified codes on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open source file for reading */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open (or create) destination file for writing, truncate if exists */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		if (close(fd_from) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(99);
	}

	/* Read 1024 bytes at a time and write to destination */
	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			if (close(fd_from) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
			if (close(fd_to) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		if (close(fd_from) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		if (close(fd_to) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(98);
	}

	/* Close file descriptors */
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
