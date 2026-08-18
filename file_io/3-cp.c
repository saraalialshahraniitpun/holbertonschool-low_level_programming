#include "main.h"

void close_file(int fd);

/**
 * close_file - closes a file descriptor and handles errors
 * @fd: file descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to program
 * @argv: array of pointers to arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;
	ssize_t read_bytes, write_bytes;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(from_fd);
		exit(99);
	}

	while ((read_bytes = read(from_fd, buffer, BUF_SIZE)) > 0)
	{
		write_bytes = write(to_fd, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(from_fd);
			close_file(to_fd);
			exit(99);
		}
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(from_fd);
		close_file(to_fd);
		exit(98);
	}

	close_file(from_fd);
	close_file(to_fd);

	return (0);
}
