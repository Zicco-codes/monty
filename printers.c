#include "monty.h"

/**
 * pchar - prints int at top of the stack as char
 * @stack: stack
 * @a: line counter
 */
void pchar(stack_t **stack, unsigned int a)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", a);
		status = EXIT_FAILURE;
		return;
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		if (((*stack)->n) == 0)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", a);
			status = EXIT_FAILURE;
			return;
		}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack
 * @b: line counter
 */
void pstr(stack_t **stack, unsigned int b __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * pint - print the top data
 * @stack: stack
 * @c: line counter
 */
void pint(stack_t **stack, unsigned int c)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", c);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pall - prints the whole stack
 * @stack: stack
 * @d: line counter
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int d __attribute__((unused)))
{
	p_stack(*stack);
}
