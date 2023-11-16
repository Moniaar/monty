#include "monty.h"

/**
 * stringErr - A function to handle the errors made by strings
 *
 * @error_num: The error codes are the following:
 *
 * (10) => The number inside a node is outside ASCII bounds
 *
 * (11) => when The stack is empty.
 */

void stringErr(int error_num, ...)
{
	va_list args;
	int l_num;

	va_start(args, error_num);
	l_num = va_arg(args, int);
	switch (error_num)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
