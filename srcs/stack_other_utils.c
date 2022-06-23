#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	if (stack)
	{
		free((*stack)->vector);
		free(*stack);
		*stack = NULL;
	}
}

/*
*	The smallest element at stack top
*/
int	is_sort(t_stack *stack)
{
	int	sort;
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->vector[i] > stack->vector[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	hf_elem_repeated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->vector[i] == stack->vector[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
*	Return 1 if error exists
*/
int	error_mng(t_stack *stack)
{
	if (!stack)
		return (1);
	if (hf_elem_repeated(stack))
		return (1);
	return (0);
}