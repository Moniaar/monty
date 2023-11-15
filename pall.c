#include "monty.h"

/**
 * pall - Prints all values on the stack
 * @stack: A pointer to the stack (doubly linked list)
 * @line_number: The line number in the file (not used in this example)
 *
 * Description: This function prints all values on the stack, starting from the
 * top of the stack. If the stack is empty, it doesn't print anything.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* Not using line_number in this example */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
