#include "monty.h"

/**
 * multiply_nodes - multiply the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void multiply_nodes(stack_t **stack, unsigned int line_number)
{
	int m;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		AdvErrors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	m = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = m;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * rem_nodes - Divide the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void rem_nodes(stack_t **stack, unsigned int line_number)
{
	int d;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		AdvErrors(8, line_number, "mod");


	if ((*stack)->n == 0)
		AdvErrors(9, line_number);
	(*stack) = (*stack)->next;

	d = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = d;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
