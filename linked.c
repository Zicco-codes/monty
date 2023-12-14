#include "monty.h"

/**
 * stackless - frees doubly linked list
 * @stack: list head
 */
void stackless(stack_t *stack)
{
	stack_t *now = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (now)
		{
			free(now);
			now = next;
			if (next)
				next = next->next;
		}
	}
}

/**
 * p_stack - prints contents of stack
 * @stack: stack head
 *
 * Return: elements of list
 */
size_t p_stack(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}

/**
 * node_q - adds node to stack in queue
 * @stack: stack head
 * @n: num of node
 *
 * Return: new node
 */
stack_t *node_q(stack_t **stack, const int m)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *now = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = m;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!now->next)
		{
			new->next = NULL;
			new->prev = now;
			now->next = new;
			break;
		}
		now = now->next;
	}

	return (new);
}

/**
 * node_add - adds node to start of stack
 * @stack: stack head
 * @n: new node num
 *
 * Return: node
 */
stack_t *node_add(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}
