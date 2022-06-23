#include "push_swap.h"

void	hf_free_lst_stack(t_stack **lst_stack)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		free(lst_stack[i]->vector);
		free(lst_stack[i]);
		i++;
	}
}

int	hf_search_elem(t_stack *s, int elem)
{
	int	i;

	i = 0;
	while (s->vector[i] != elem)
		i++;
	return (i);
}

t_stack *hf_sort_stack(t_stack *s)
{
	t_stack **lst_stack;
	t_stack	*tmp;
	int		i;
	int		j;
	int		div;

	// Reservar estructuras de datos
	tmp = empty_stack(s->size);
	copy_stack(s, tmp);
	lst_stack = malloc(10 * sizeof(t_stack *));
	i = 0;
	while (i < 10)
	{
		lst_stack[i] = empty_stack(s->size);
		i++;
	}
	// Ordenamiento radix con 10 pilas
	div = 1;
	while (i > 0)
	{
		while (!isempty(tmp))
		{
			j = (tmp->vector[tmp->top] % (div * 10)) / div;
			push(lst_stack[j], pop(tmp));
		}
		j = 9;
		while (j >= 0)
		{
			while (!isempty(lst_stack[j]))
				push(tmp, pop(lst_stack[j]));
			j--;
		}
		if (is_sort(tmp))
			break ;
		div *= 10;
		i--;	
	}
	hf_free_lst_stack(lst_stack);
	free(lst_stack);
	return (tmp);
}

void 	radix_sort_dec(t_stack *a)
{
	t_stack	*b;
	t_stack	*tmp;
	int		i;
	int		index;

	b = empty_stack(a->size);
	tmp = hf_sort_stack(a);
	// Extracción de elementos de 'a' y volcado en 'b'
	while (!isempty(tmp))
	{
		index = hf_search_elem(a, pop(tmp));
		if ((a->top - index) < index)
		{
			i = a->top - index;
			while (i > 0)
			{
				print_ra(a);
				i--;
			}
		}
		else
		{
			i = index;
			while (i >= 0)
			{
				print_rra(a);
				i--;
			}
		}
		print_pb(a, b);
	}
	// Volcado de 'b' a 'a'
	while (!isempty(b))
		print_pa(a, b);
	free_stack(&b);
	free_stack(&tmp);
}