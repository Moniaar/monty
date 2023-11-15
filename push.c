#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, int value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* Global variable to represent the stack (doubly linked list) */
stack_t *stack;

int main(void)
{
	/* Example usage */
	push(&stack, 1, 1);
	push(&stack, 2, 2);
	push(&stack, 3, 3);
	pall(&stack, 4);

	return 0;
}

/* Function to push an element onto the stack */
void push(stack_t **stack, int value, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "Error at line %u: Stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error at line %u: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(value))
	{
		fprintf(stderr, "Error at line %u: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/* Function to print all values on the stack */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Not using line_number in this example */

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
