#include "push_swap.h"

void	hf_swap(t_stack *stack)
{
	int	tmp;

	if(stack->top > 0)
	{
		tmp = stack->vector[stack->top];
		stack->vector[stack->top] = stack->vector[stack->top - 1];
		stack->vector[stack->top - 1] = tmp;
	}
}

void	sa(t_stack *a)
{
	hf_swap(a);
}

void	sb(t_stack *b)
{
	hf_swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	hf_swap(a);
	hf_swap(b);
}