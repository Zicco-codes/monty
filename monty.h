#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
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

#define INSTRUCTIONS { \
		{"push", push},\
		{"pall", pall},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{"nop", nop},\
		{"div", divide},\
		{"mul", multi},\
		{"add", plus},\
		{"sub", minus},\
		{"mod", mod},\
		{"pchar", pchar},\
		{"pstr", pstr},\
		{"rotl", rotl},\
		{"rotr", rotr},\
		{NULL, NULL} \
	}
/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

extern int status;

void push(stack_t **stack, unsigned int a);
void pall(stack_t **stack, unsigned int d);
void pint(stack_t **stack, unsigned int c);
void swap(stack_t **stack, unsigned int a);
void pop(stack_t **stack, unsigned int b);
void nop(stack_t **stack, unsigned int zz);
void divide(stack_t **stack, unsigned int d);
void plus(stack_t **stack, unsigned int a);
void minus(stack_t **stack, unsigned int b);
void multi(stack_t **stack, unsigned int c);
void mod(stack_t **stack, unsigned int e);
void pchar(stack_t **stack, unsigned int a);
void pstr(stack_t **stack, unsigned int b);
void rotl(stack_t **stack, unsigned int _count);
void rotr(stack_t **stack, unsigned int _count);
void opcode(stack_t **stack, char *str, unsigned int b);
void f_error(char *argv);
int is_digit(char *s);
int isnum(char *s);
void err(void);
stack_t *node_add(stack_t **stack, const int n);
stack_t *node_q(stack_t **stack, const int m);
void stackless(stack_t *stack);
size_t p_stack(const stack_t *stack);

#endif
