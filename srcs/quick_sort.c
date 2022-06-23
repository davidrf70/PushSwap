#include "push_swap.h"
#include <stdio.h>

/* void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size - 1;
	while (i >= 0)
	{
		if (i <= a->top)
			printf("%d ", a->vector[i]);
		else
			printf("* ");
		if (b)
		{
			if (i <= b->top)
				printf("%d", b->vector[i]);
			else
				printf("*");
		}
		printf("\n");
		i--;
	}
	if (b)
	{
		printf("- -\n");
		printf("a b\n");
	}
	else
	{
		printf("-\n");
		printf("a\n");
	}
} */

void	quick_sort(t_stack *a)
{
	int				i;
	int				j;
	t_stack			*b;

	b = empty_stack(a->size);
	if (!b)
		return ;
	//print_stacks(a, b);
	j = 0;
 	while (!is_sort(a))
	{
		while (j > 0)
		{
			print_ra(a);
			j--;
		}
		i = a->size - 1;
		while (i > 0)
		{
			if(a->vector[a->top] <= a->vector[a->top - 1])
			{
				print_sa(a);
				print_ra(a);
			}
			else
			{
				print_sa(a);
				print_pb(a, b);
			}
			i--;
		}
		j = 1;
		while (!isempty(b))
		{
			print_pa(a, b);
			j++;
		}
	}
	//print_stacks(a, b);
	free_stack(&b);
}