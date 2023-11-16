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

/**
 * printString - Prints a string.
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
