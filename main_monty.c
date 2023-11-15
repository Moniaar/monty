#include "monty.h"

/**
 * main - The entry point starts from here
 *
 * @arg: arguments counts
 *
 * @argc: List of written arguments
 *
 * Return: Always  0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	free_node();
	return(0);
}

/**
 * openFile - A function to open a file whenver you enter a new command
 *
 * @fileName: the file path name
 *
 * Return: Void (Nothing)
 */

void openFile(char *fileName)
{
	FILE *fd = fopen(fileName, "r");

	if (fileName == NULL || fd == NULL)

	print_error(2, fileName);
	readFile(fd);
	fclose(fd);
}

/**
 * readFile - a function to read the file after opening it
 *
 * @fd: (File descriptor)pointer to the given file name
 *
 * Return: Void (nothing)
 */

void readFile(FILE *fd)
{
	int line_number;
	int format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for(line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		format = parseGivenLine(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * parseGivenLine - seprates each line into tokens to know which function exactly
 * to be called by the next function below this one
 *
 * @buffer: Line from file
 *
 * @line_number: integer line number
 *
 * @format: storage format, if it's 0, nodes will enter as a stack
 *
 * if 1 the nodes will be inserted as a queue
 *
 * Return: 0 if it's a stack, 1 if it's a queue
 */

int parseGivenLine(char *buffer, int line_number, int format)
{
	char *opcod, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		print_error(4);

	opcod = strtok(buffer, delim);
	if (opcod == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcod, "stack") == 0)
		return (0);
	if (strcmp(opcod, "queue") == 0)
		return (1);

	find_func(opcod, value, line_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 *
 * @value: argument of opcode
 *
 * @format: storage format. If 0 Nodes will be entered as a stack.
 *
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 *
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
	};
	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - Calls the required function.
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
 * Return: Nothing (Void)
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
	}
	else
		func(&head, ln);
}
