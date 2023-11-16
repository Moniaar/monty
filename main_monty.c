#include "monty.h"
stack_t *head = NULL;

/**
 * main - This is the main entry point
 *
 * @argc: arguments count
 *
 * @argv: list of arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openew_file(argv[1]);
	freeNodes();
	return (0);
}

/**
 * createNode - This function will create a new node
 *
 * @n: Number to go inside the node.
 *
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 *
 */

stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_mesg(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNodes - Frees nodes in the stack
 *
 */

void freeNodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * adddToqueue - Adds a new node to the queue.
 *
 * @new_node: Pointer to the new node.
 *
 * @ln: line number of the opcode.
 */

void adddToqueue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
