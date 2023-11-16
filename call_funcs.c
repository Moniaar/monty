#include "monty.h"

/**
 * callfuncs - Calls the required function after you write the command
 * in the Monty File
 *
 * @func: Pointer to the function that is about to be called.
 *
 * @op: string representing the opcode.
 *
 * @val: string representing a numeric value.
 *
 * @ln: line numeber for the instruction.
 *
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 *
 */

void callfuncs(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *Node;
	int flag;
	int k;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error_mesg(5, ln);
		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k]) == 0)
				error_mesg(5, ln);
		}
		Node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&Node, ln);
		if (format == 1)
			adddToqueue(&Node, ln);
	}
	else
		func(&head, ln);
}
