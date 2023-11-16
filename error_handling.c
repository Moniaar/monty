#include "monty.h"

/**
 * error_mesg - Prints appropiate error messages
 * determined by their error code.
 *
 * @error_num: The error codes are the following:
 *
 * (1) => The user does not give any file or more
 * than one file to the path
 *
 * (2) => The file provided isn't a file that can be opened or read
 *
 * (3) => The file provided contains an invalid given instruction
 *
 * (4) => When the program is unable to malloc more memory anymore
 *
 * (5) => When the parameter passed to the instruction
 * "push" isn't int.
 *
 * (6) => When the stack is empty for pint.
 *
 * (7) => When the stack is empty for pop.
 *
 * (8) => When stack is too short to make operation on it
 *
 */

void error_mesg(int error_num, ...)
{
	va_list args;
	char *op;
	int l_num;

	va_start(args, error_num);
	switch (error_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			l_num = va_arg(args, int);

			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * AdvErrors - A function that handles the advanced errors.
 *
 * @error_num: The error codes are the following:
 *
 * (6) => When the stack is empty for pint.
 *
 * (7) => When the stack is empty for pop.
 *
 * (8) => When stack is too short
 *
 * (9) => when Division by zero happens
 */

void AdvErrors(int error_num, ...)
{
	va_list args;
	char *op;
	int l_num;

	va_start(args, error_num);
	switch (error_num)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			l_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
