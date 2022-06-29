#include "push_swap.h"

/* int		comp(const void *n1, const void *n2)
{
	if (*(unsigned int *)n1 > *(unsigned int *)n2)
		return (1);
	else if (*(unsigned int *)n1 < *(unsigned int *)n2)
		return (-1);
	else
		return (0);
} */

//int	hf_search_elem(t_stack *s, unsigned int elem)
int	hf_search_elem(t_stack *s, int elem)
{
	unsigned int	i;

	i = 0;
	while (s->vector[i] != elem)
		i++;
	return (i);
}

int		rev_comp(const void *n1, const void *n2)
{
	//if (*(unsigned int *)n1 > *(unsigned int *)n2)
	if (*(int *)n1 < *(int *)n2)
		return (1);
	//else if (*(unsigned int *)n1 < *(unsigned int *)n2)
	else if (*(int *)n1 > *(int *)n2)
		return (-1);
	else
		return (0);
}

unsigned int	*hf_get_ordered_array(t_stack *s, char dir)
{
	unsigned int	*order;
	int				i;

	order = malloc(s->size * sizeof(unsigned int));
	i = 0;
	while (i < s->size)
	{
		order[i] = s->vector[i];
		i++;
	}
	if (dir == 'f')
		qsort(order, s->size, sizeof(unsigned int), comp);
	else
		qsort(order, s->size, sizeof(unsigned int), rev_comp);
	return (order);
}

void	hf_extract_elem_rev(t_stack *a, t_stack *b, int pos)
{
	if ((b->top - pos) < (pos + 1))
		while (pos < b->top)
		{
			print_rb(b);
			pos++;
		}
	else
		while (pos >= 0)
		{
			print_rrb(b);
			pos--;
		}
	print_pa(a, b);
}

void	hf_extract_elem(t_stack *a, t_stack *b, int pos)
{
	if ((a->top - pos) < (pos + 1))
		while (pos < a->top)
		{
			print_ra(a);
			pos++;
		}
	else
		while (pos >= 0)
		{
			print_rra(a);
			pos--;
		}
	print_pb(a, b);
}

void	hf_bucket_sort(t_stack *a, t_stack *b)
{
	int	bucket;
	int	i;

	bucket = a->size;
	while (bucket > 0)
	{
		i = 0;
		while (i <= a->top)
		{
			if (a->vector[i] < bucket && a->vector[i] >= bucket - 10)
			{
				hf_extract_elem(a, b, i);
				i = -1;
			}
			i++;
		}
		bucket -= 10;
	}	
}

void	extraction_sort(t_stack *a)
{
	t_stack			*b;
	unsigned int	*order;
	int				pos;
	int				i;

	b = empty_stack(a->size);
	if (!b)
		return ;
	//order = hf_get_ordered_array(a);
	order = hf_get_ordered_array(a, 'r');
	hf_bucket_sort(a, b); //  NUEVO
	i = 0;
	/* while (i < a->size)
	{
		pos = hf_search_elem(a, order[i]);
		hf_extract_elem(a, b, pos);
		i++;
	}
	while (!isempty(b))
		print_pa(a, b); */
	while (i < b->size)
	{
		pos = hf_search_elem(b, order[i]);
		hf_extract_elem_rev(a, b, pos);
		i++;
	}
	free(order);
	free_stack(&b);
}