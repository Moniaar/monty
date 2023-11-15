#include "monty.h"

/** 
 * addtop_elem - A function that will add the top 2 elements of the
 * stack and make the stack minimize by 1
 *
 * @stack: a pointer to a pointer pointing to top node of the stack
 *
 * @line_number: integer to tell you the line number of the given opCode
 *
 * Return: Nothing (Void)
 */

void addtop_elem(stack_t **stack, unsigned int line_number)
{
	int addnode;

	/*checking if the stack is empty or has less than 2 elements*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		print_error;
		exit(EXIT_FAILURE);
	}
	/*make the stack pointer go to the next postion*/
	(*stack) = (*stack)->next;
	/*store the value in addnode */
	addnode = (*stack)->n + (*stack)->prev->n;
	/*make the stack point to the top again which is the new summation*/
	(*stack)-> = addnode;
	/*free the previuos node since it's empty now after being summed*/
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
