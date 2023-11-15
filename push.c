#include "monty.h"
stack_t *stack;
/**
 * push - Pushes an element onto the stack
 * @stack: A pointer to the stack (doubly linked list)
 * @value: The value to be pushed onto the stack
 * @line_number: The line number in the file
 *
 * Description: This function pushes an element with the given value onto the
 * stack. It performs error checks and prints error messages if needed.
 */
void push(stack_t **stack, char *value, unsigned int line_number)
{
	int i;
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "Error at line %u: Stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error at line %u: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; value[i] != '\0'; i++)
	{
		if (!isdigit(value[i]) && value[i] != '-')
		{
			fprintf(stderr, "Error at line %u: usage: push integer\n", line_number);
			free(new_node);
			exit(EXIT_FAILURE);
		}
	}

	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
