#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->size == 2)
		if (stack->vector[0] < stack->vector[1])
		{
			sa(stack);
			ft_print_str("sa\n", 1);
		}
}

void	hf_sort_partial(t_stack *stack)
{
	int	r_count;
	int	top;
	int	i;

	i = 0;
	top = stack->top;
	r_count = 0;
	while (stack->vector[top] > stack->vector[top - 1] && i < top)
	{
		sa(stack);
		ft_print_str("sa\n", 1);
		ra(stack);
		ft_print_str("ra\n", 1);
		r_count++;
		i++;
	}
	while (r_count > 0)
	{
		rra(stack);
		ft_print_str("rra\n", 1);
		r_count--;
	}
}

void	sort_gt_three(t_stack *a)
{
	t_stack	*b;

	if (a->size <= 3)
		return ;
	b = empty_stack(a->size);
	if (!b)
		return ;
	while (a->top > 2)
	{
		pb(a, b);
		ft_print_str("pb\n", 1);
	}
	sort_three(a);
	while (b->top >= 0)
	{
		pa(a, b);
		ft_print_str("pa\n", 1);
		hf_sort_partial(a);
	}
}