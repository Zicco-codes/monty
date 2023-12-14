#include "monty.h"

/**
 * swap -  swaps data from top to previous
 * @stack: stack
 * @a: line counter
 */
void swap(stack_t **stack, unsigned int a)
{
	stack_t *tmp = NULL;
	int f = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", a);
		status = EXIT_FAILURE;
		return;
	}
	tmp = *stack;
	f = tmp->n;
	tmp->n = f;

	tmp->n = tmp->next->n;
	tmp->next->n = f;

}

/**
 * opcode - function in charge of running builtins
 * @stack: stack
 * @s: string
 * @b: line counter
 */
void opcode(stack_t **stack, char *s, unsigned int b)
{
	int m = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(s, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(s, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[m].opcode)
	{
		if (strcmp(op[m].opcode, s) == 0)
		{
			op[m].f(stack, b);
			return;
		}
		m++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", b, s);
	status = EXIT_FAILURE;
}

/**
 * is_digit - checks if a string is a digit
 * @s: string
 *
 * Return: 1,or 0
 */
int is_digit(char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (isdigit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}
/**
 * isnum - checks if a string is a number
 * @s: string
 *
 * Return: 1, or 0.
 */
int isnum(char *s)
{
	int a;

	if (!s)
		return (0);

	for (a = 0; s[a]; a++)
		if (a < '0' || a > '9')
			return (0);

	return (1);
}
