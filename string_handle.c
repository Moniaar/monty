#include "monty.h"

/**
 * printString - Prints a string given by the monty script
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @ln: Interger representing the line number of of the opcode.
 */

void printString(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int a;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		a = temp->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		temp = temp->next;
	}
	printf("\n");
}
