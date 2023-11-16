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

/**
 * findFuncs - find the appropriate function for the given opcode
 *
 * @opcode: opcode
 *
 * @value: argument of opcode
 *
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 *
 * @ln: line number
 *
 * if 1 nodes will be entered as a queue.
 * Return: void
 *
 */

void findFuncs(char *opcode, char *value, int ln, int format)
{
	int k;
	int flag;

	instruction_t func_list[] = {
		{"push", addnodeTos},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", Nop},
		{"swap", swapTop2elem},
		{"add", addTOtop},
		{"sub", subTotop},
		{"div", divNodes},
		{"mul", multiply_nodes},
		{"mod", rem_nodes},
		{"pchar", printAscii},
		{"pstr", printString},
		{"rotl", rotateFtoBot},
		{"rotr", rotLastTop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			callfuncs(func_list[k].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_mesg(3, ln, opcode);
}


/**
 * callfuncs - Calls the required function after you write the command
 * in the Monty File
 *
 * @func: Pointer to the function that is about to be called.
 *
 * @op: string representing the opcode.
 *
 * @val: string representing a numeric value.
 *
 * @ln: line numeber for the instruction.
 *
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 *
 */

void callfuncs(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *Node;
	int flag;
	int k;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error_mesg(5, ln);
		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k]) == 0)
				error_mesg(5, ln);
		}
		Node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&Node, ln);
		if (format == 1)
			adddToqueue(&Node, ln);
	}
	else
		func(&head, ln);
}
