#include "monty.h"

/**
 * addnodeTos - Adds a node to the stack.
 *
 * @new_node: Pointer to the new node.
 *
 * @ln: Interger representing the line number of of the opcode.
 */

void addnodeTos(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * pall - This function prints the elements of the stack
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: line number of  the opcode.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * popTop - this function will remove the top element of a stack
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void popTop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		AdvErrors(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * printTop - Prints the top nodes of the stack
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 *
 * @line_number: Interger representing the line number of of the opcode.
 */

void printTop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		AdvErrors(6, line_number);
	printf("%d\n", (*stack)->n);
}
