/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:45 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:50:13 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hf_isthere_elem(t_stack *s, unsigned int mask)
{
	int	i;

	i = s->top;
	while (i >= 0)
	{
		if (!(s->vector[i] & mask))
			return (1);
		i--;
	}
	return (0);
}

void	hf_iteration(t_stack *a, t_stack *b, unsigned int mask)
{
	int	iter;

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
		if (is_sort(a))
			break ;
		mask *= 2;
		i++;
	}
	free_stack(&b);
}
