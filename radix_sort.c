#include "push_swap.h"

void	hf_iteration(t_stack *a, t_stack *b, unsigned int mask)
{
	int				iter;

	iter = a->top;
	while (iter >= 0)
	{
		if (!(a->vector[a->top] & mask))
			print_pb(a, b);
		else
			print_ra(a);
		iter--;
	}
}

void	radix_sort(t_stack *a)
{
	int				i;
	int				iter;
	unsigned int	mask;
	t_stack			*b;

	b = empty_stack(a->size);
	if (!b)
		return ;
	mask = 0x00000001;
	i = 0;
	while (i < 32)
	{
		hf_iteration(a, b, mask);
		while (!isempty(b))
			print_pa(a, b);
		if(is_sort(a))
			break;
		mask *= 2;
		i++;
	}
	free_stack(&b);
}