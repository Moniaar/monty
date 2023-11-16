#include "monty.h"

/**
 * Nop - Does nothing.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 *
 */

void Nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swapTop2elem - Swaps the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void swapTop2elem(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		AdvErrors(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * addTOtop - Adds the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void addTOtop(stack_t **stack, unsigned int line_number)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		AdvErrors(8, line_number, "add");

	(*stack) = (*stack)->next;
	summation = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * subTotop - Subtracts the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void subTotop(stack_t **stack, unsigned int line_number)
{
	int subtract;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		AdvErrors(8, line_number, "sub");


	(*stack) = (*stack)->next;
	subtract = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = subtract;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divNodes - Divides the top two elements of the stack.
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void divNodes(stack_t **stack, unsigned int line_number)
{
	int d;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		AdvErrors(8, line_number, "div");

	if ((*stack)->n == 0)
		AdvErrors(9, line_number);
	(*stack) = (*stack)->next;
	d = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = d;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
