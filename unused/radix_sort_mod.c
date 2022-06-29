#include "push_swap.h"

int	search_base(t_stack *s, unsigned int mask)
{
	int	i;

	i = 0;
	while ((s->vector[i] & mask) && i <= s->top)
		i++;
	return (i);
}

int	search_top(t_stack *s, int unsigned mask)
{
	int	i;

	i = s->top;
	while ((s->vector[i] & mask) && i >= 0)
		i--;
	return (i);
}

void	hf_do_actions(t_stack *a, t_stack *b, int mov_top, int mov_base)
{
	if ((a->top - mov_top) < (mov_base + 1))
		while (mov_top < a->top)
		{
			print_ra(a);
			mov_top++;
		}
	else
		while (mov_base >= 0)
		{
			print_rra(a);
			mov_base--;
		}
	print_pb(a, b);
}

void	hf_iteration(t_stack *a, t_stack *b, unsigned int mask)
{
	int	mov_top;
	int	mov_base;

	while (1)
	{
		mov_top = search_top(a, mask);
		if (mov_top < 0)
			break ;
		mov_base = search_base(a, mask);
		hf_do_actions(a, b, mov_top, mov_base);
	}
}

void	radix_sort_mod(t_stack *a)
{
	int				i;
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