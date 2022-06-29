#include "push_swap.h"

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

/* void	quick_sort(t_stack *a)
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
} */

int	hf_log2(int n)
{
	int	i;
	int	div;

	i = 1;
	div = 2;
	while (n / div)
	{
		div *= 2;
		i++;
	}
	return (i);
}

int	median_index(t_stack *s, int base)
{
	unsigned int	*order;
	int				i;
	int				median;

	//order = malloc((s->top - base) * sizeof(unsigned int));
	order = malloc((s->top - base + 1) * sizeof(int));
	i = 0;
	while (i < s->top - base + 1)
	{
		order[i] = s->vector[i + base];
		i++;
	}
	qsort(order, s->top - base + 1, sizeof(unsigned int), comp);
	median = search_elem(s->vector, order[(s->top - base + 1) / 2]);
	free(order);
	return (median);
}

void	split_a(t_stack *a, t_stack *b, int base)
{
	int	i;
	int	median;
	int	ra_count;

	ra_count = 0;
	median = a->vector[median_index(a, base)];
	i = a->top;
	while (i >= base)
	{
		if (a->vector[a->top] < median)
			print_pb(a, b);
		else
		{
			print_ra(a);
			ra_count++;
		}
		i--;
	}
	while (ra_count > 0 && base > 0)
	{
		print_rra(a);
		ra_count--;
	}
}

void	split_b(t_stack *a, t_stack *b, int base)
{
	int	i;
	int	median;
	int	rb_count;

	rb_count = 0;
	median = b->vector[median_index(b, base)];
	i = b->top;
	while (i >= base)
	{
		if (b->vector[b->top] > median)
			print_pa(a, b);
		else
		{
			print_rb(b);
			rb_count++;
		}
		i--;
	}
	while (rb_count > 0)
	{
		print_rrb(b);
		rb_count--;
	}
}

int		quick_is_sort(t_stack *s)
{
	int	i;

	i = 0;
	while (s->vector[i] > s->vector[i + 1] && i <= s->top - 1)
		i++;
	if (i == s->top)
		return (1);
	return (0);
}

/* (top - base) 1 3 2   O(n) = 3 */
t_stack	*sort3_case1(t_stack *a, int print)
{
	ra(a);
	sa(a);
	rra(a);
	if (print)
		ft_print_str("ra\nsa\nrra\n", 1);
	return (a);
}

/* (top - base) 2 1 3   O(n) = 1 */
t_stack	*sort3_case2(t_stack *a, int print)
{
	sa(a);
	if (print)
		ft_print_str("sa\n", 1);
	return (a);
}

/* (top - base) 2 3 1   O(n) = 4 */
t_stack	*sort3_case3(t_stack *a, int print)
{
	sort3_case1(a, print);
	sort3_case2(a, print);
	return (a);
}

/* (top - base) 3 1 2   O(n) = 4 */
t_stack	*sort3_case4(t_stack *a, int print)
{
	sa(a);
	if (print)
		ft_print_str("sa\n", 1);
	sort3_case1(a, print);
	return (a);
}

/* (top - base) 3 2 1   O(n) = 5 */
t_stack	*sort3_case5(t_stack *a, int print)
{
	sa(a);
	if (print)
		ft_print_str("sa\n", 1);
	sort3_case3(a, print);
	return (a);
}

void	hf_copy_tmp_stack(t_stack *src, t_stack *tmp)
{
	int	i;
	
	i = 0;
	while (i < tmp->size)
	{
		tmp->vector[i] = src->vector[src->top - 2 + i];
		i++;
	}
	tmp->top = 2;
}

void	quick_sort_three(t_stack *a, int base)
{
	t_stack	*tmp;

	if ((a->top - base) == 1)
		return ;
	if ((a->top - base) == 2)
	{
		if (a->vector[a->top] > a->vector[a->top - 1])
			print_sa(a);
		return ;
	}
	tmp = empty_stack(3);
	hf_copy_tmp_stack(a, tmp);
	if (quick_is_sort(tmp))
		return ;
	if (quick_is_sort(sort3_case1(tmp, 0)))
		sort3_case1(a, 1);
	hf_copy_tmp_stack(a, tmp);
	if (quick_is_sort(sort3_case2(tmp, 0)))
		sort3_case2(a, 1);
	hf_copy_tmp_stack(a, tmp);
	if (quick_is_sort(sort3_case3(tmp, 0)))
		sort3_case3(a, 1);
	hf_copy_tmp_stack(a, tmp);
	if (quick_is_sort(sort3_case4(tmp, 0)))
		sort3_case4(a, 1);
	hf_copy_tmp_stack(a, tmp);
	if (quick_is_sort(sort3_case5(tmp, 0)))
		sort3_case5(a, 1);
	free_stack(&tmp);
}

void	quick_sort(t_stack *a)
{
	t_stack	*b;
	t_stack	*a_part;
	t_stack	*b_part;
	int		i;

	b = empty_stack(a->size);
	a_part = empty_stack(hf_log2(a->size));
	push(a_part, -1);
	b_part = empty_stack(hf_log2(a->size));
	push(b_part, -1);
	if (!b || !a_part || !b_part)
		return ;
	while (!(is_sort(a) && a->top == a->size - 1))
	{
		while (a->top > a_part->vector[a_part->top] + 3)
		{
			split_a(a, b, a_part->vector[a_part->top] + 1);
			push(b_part, b->top);
		}
		quick_sort_three(a, a_part->vector[a_part->top]);
		pop(a_part);
		push(a_part, a->top);
		if (b->top > b_part->vector[b_part->top] + 3)
			split_b(a, b, b_part->vector[b_part->top] + 1);
		else
		{
			i = 0;
			while (i < b->top - b_part->vector[b_part->top])
				print_pa(a, b);
			pop(b_part);
		}
	}
	free_stack(&b);
	free_stack(&a_part);
	free_stack(&b_part);
}