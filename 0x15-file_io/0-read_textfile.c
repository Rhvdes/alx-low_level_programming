#include <stdio.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	/* Return 0 if filename is NULL*/
	if (!filename)
	{
		return (0);
	}

	/* Open the file for reading*/
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}

	/* Allocate a buffer to hold the read data*/
	buffer = malloc(letters);
	if (!buffer)
	{
		return (0);
	}

	/* Read up to "letters" number of bytes from the file*/
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	/* Write the read data to standard output*/
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		return (0);
	}

	/* Free the buffer and close the file*/
	free(buffer);
	close(fd);

	/* Return the number of bytes read and written*/
	return (bytes_read);
}
