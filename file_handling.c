#include "monty.h"

/**
 * openew_file - This function will open a file for you
 *
 * @file_name: the file name path
 *
 * Return: void (Nothing)
 */

void openew_file(char *file_name)
{
	FILE *fdis = fopen(file_name, "r");

	if (file_name == NULL || fdis == NULL)
		error_mesg(2, file_name);

	readfile(fdis);
	fclose(fdis);
}


/**
 * readfile - This function reads a file from the user
 *
 * @fd: pointer to file descriptor
 *
 * Return: void
 */

void readfile(FILE *fd)
{
	int linenum, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (linenum = 1; getline(&buffer, &length, fd) != -1; linenum++)
	{
		format = parseline(buffer, linenum, format);
	}
	free(buffer);
}
