#include "monty.h"

/**
 * rotateFtoBot - Rotates the first node of the stack to the bottom.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @ln: Interger representing the line number of of the opcode.
 */

void rotateFtoBot(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
