#include "monty.h"

/**
 * findFuncs - find the appropriate function for the given opcode
 *
 * @opcode: opcode
 *
 * @value: argument of opcode
 *
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 *
 * @ln: line number
 *
 * if 1 nodes will be entered as a queue.
 * Return: void
 *
 */

void findFuncs(char *opcode, char *value, int ln, int format)
{
	int k;
	int flag;

	instruction_t func_list[] = {
		{"push", addnodeTos},
		{"pall", pall},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", Nop},
		{"swap", swapTop2elem},
		{"add", addTOtop},
		{"sub", subTotop},
		{"div", divNodes},
		{"mul", multiply_nodes},
		{"mod", rem_nodes},
		{"pchar", printAscii},
		{"pstr", printString},
		{"rotl", rotateFtoBot},
		{"rotr", rotLastTop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			callfuncs(func_list[k].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_mesg(3, ln, opcode);
}
