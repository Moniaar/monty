#include "monty.h"

/**
 * printAscii - Prints the Ascii value.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */
void printAscii(stack_t **stack, unsigned int line_number)
{
	int a;

	if (stack == NULL || *stack == NULL)
		stringErr(11, line_number);

	a = (*stack)->n;
	if (a < 0 || a > 127)
		stringErr(10, line_number);
	printf("%c\n", a);
}
