#include "monty.h"

/**
 * nop - function that does nothing
 * @stack: stack
 * @zz: line counter
 */
void nop(stack_t **stack, unsigned int zz)
{
	(void) stack;
	(void) zz;
}

/**
 * errs - prints usage message and exits
 */
void err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * f_err - prints file error message and exits
 * @argv: argv given by main
 */
void f_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
