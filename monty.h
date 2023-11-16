#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void openew_file(char *file_name);
int parseline(char *buffer, int line_number, int format);
void readfile(FILE *);
int len_chars(FILE *);
void findFuncs(char *, char *, int, int);

/*Stack operations*/
stack_t *createNode(int n);
void freeNodes(void);
void pall(stack_t **, unsigned int);
void addnodeTos(stack_t **, unsigned int);
void adddToqueue(stack_t **, unsigned int);

void callfuncs(op_func, char *, char *, int, int);

void printTop(stack_t **, unsigned int);
void popTop(stack_t **, unsigned int);
void Nop(stack_t **, unsigned int);
void swapTop2elem(stack_t **, unsigned int);

/*Math operations with nodes*/
void addTOtop(stack_t **, unsigned int);
void subTotop(stack_t **, unsigned int);
void divNodes(stack_t **, unsigned int);
void multiply_nodes(stack_t **, unsigned int);
void rem_nodes(stack_t **, unsigned int);

/*String operations*/
void printAscii(stack_t **stack, unsigned int line_number);
void printString(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotateFtoBot(stack_t **stack, __attribute__((unused))unsigned int ln);

/*Error hanlding*/
void error_mesg(int error_num, ...);
void AdvErrors(int error_num, ...);
void stringErr(int error_num, ...);
void rotLastTop(stack_t **stack, __attribute__((unused))unsigned int ln);
#endif
