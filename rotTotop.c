#include "monty.h"

/**
 * rotLastTop - Rotates the last node of the stack to the top.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @ln: Interger representing the line number of of the opcode.
 */

void rotLastTop(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
