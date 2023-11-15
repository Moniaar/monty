#include "monty.h"

/**
 * print-error - A function to print error messeges to the stderr
 *
 * Return: Void (Nothing)
 */

void print_error(int codeoferr, ...)
{
	/*variadic functions are needed because we don't know the
	 * length of the upcoming arguments*/
	va_list args;
	char *opcod;
	int line_num;

	va_start(args, codeoferr);
	/*These will become Switch cases as we move on to more
	 * errors throughout the program*/
	line_num = va_arg(args, unsigned int);
	opcod = va_arg(ag, char *);
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, opcod);
}
