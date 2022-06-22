#include "push_swap.h"

void	hf_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if(stack->top < 1)
		return ;
	tmp = stack->vector[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->vector[i] = stack->vector[i - 1];
		i--;
	}
	stack->vector[i] = tmp;
}

void	ra(t_stack *a)
{
	hf_rotate(a);
}

void	rb(t_stack *b)
{
	hf_rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	hf_rotate(a);
	hf_rotate(b);
}