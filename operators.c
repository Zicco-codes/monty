#include "monty.h"

/**
 * plus -  adds first two nodes of stack
 * @stack: the stack
 * @a: line counter
 */
void plus(stack_t **stack, unsigned int a)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", a);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, a);
	(*stack)->n = res;
}

/**
 * minus -  substracts first two nodes of the stack
 * @stack: stack
 * @b: line counter
 */
void minus(stack_t **stack, unsigned int b)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", b);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, b);
	(*stack)->n = res;
}

/**
 * multi - multiplies the next top value by the top value
 * @stack: stack
 * @c: line counter
 */
void multi(stack_t **stack, unsigned int c)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", c);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, c);
	(*stack)->n = res;
}

/**
 * divide - divides the next top value by the top value
 * @stack: stack
 * @d: line counter
 */
void divide(stack_t **stack, unsigned int d)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", d);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", d);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, d);
	(*stack)->n = res;
}

/**
 * mod - computes remainder of the division
 * @stack: stack
 * @e: line counter
 */
void mod(stack_t **stack, unsigned int e)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", e);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", e);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, e);
	(*stack)->n = res;
}
