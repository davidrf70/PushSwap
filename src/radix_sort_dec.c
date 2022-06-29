/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:42 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:15:40 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst_stack(t_stack **lst_stack)
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

void	hf_classify(t_stack **lst_stack, t_stack *s, int div)
{
	int	i;

	while (!isempty(s))
	{
		i = (s->vector[s->top] % (div * 10)) / div;
		push(lst_stack[i], pop(s));
	}
}

void	hf_return_iteration(t_stack **lst_stack, t_stack *s)
{
	int	i;

	i = 9;
	while (i >= 0)
	{
		while (!isempty(lst_stack[i]))
			push(s, pop(lst_stack[i]));
		i--;
	}
}

t_stack	**hf_allocate_lst_stack(int size)
{
	t_stack	**lst_stack;
	int		i;

	lst_stack = malloc(10 * sizeof(t_stack *));
	i = 0;
	while (i < 10)
	{
		lst_stack[i] = empty_stack(size);
		i++;
	}
	return (lst_stack);
}

void	radix_sort_dec(t_stack *s)
{
	t_stack	**lst_stack;
	int		i;
	int		div;

	lst_stack = hf_allocate_lst_stack(s->size);
	div = 1;
	i = 10;
	while (i > 0)
	{
		hf_classify(lst_stack, s, div);
		hf_return_iteration(lst_stack, s);
		if (is_sort(s))
			break ;
		div *= 10;
		i--;
	}
	free_lst_stack(lst_stack);
	free(lst_stack);
}
