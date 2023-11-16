#include "monty.h"

/**
 * parseline - Separates each line into tokens to determine
 * which function to call from the different ones in the lists below
 * @buffer: line from the file
 *
 * @line_number: line number
 *
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 *
 */

int parseline(char *buffer, int line_number, int format)
{
	char *opcd, *v;
	const char *delim = "\n ";

	if (buffer == NULL)
		error_mesg(4);

	opcd = strtok(buffer, delim);
	if (opcd == NULL)
		return (format);
	v = strtok(NULL, delim);

	if (strcmp(opcd, "stack") == 0)
		return (0);
	if (strcmp(opcd, "queue") == 0)
		return (1);

	findFuncs(opcd, v, line_number, format);
	return (format);
}
