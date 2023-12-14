#include "monty.h"

/**
* rotr - rotates the last node of a stack_t stack
* @stack: head of stack
* @_count: line count
*/
void rotr(stack_t **stack, unsigned int _count)
{
	stack_t *bottom;
	stack_t *prev;

	(void) _count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}

/**
* rotl - rotates the first element of the stack
* @stack: head of stack
* @_count: line count
*/
void rotl(stack_t **stack, unsigned int _count)
{
	stack_t *left;
	stack_t *right;

	(void) _count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next)
		right = right->next;
	right->next = left;
	left->prev = right;
	*stack = left->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
