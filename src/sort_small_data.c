/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:52:11 by David RF          #+#    #+#             */
/*   Updated: 2022/06/29 09:59:51 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	hf_get_pos(t_stack *s)
{
	t_stack	*tmp;
	int		i;

	tmp = empty_stack(s->size);
	copy_stack(s, tmp);
	radix_sort_dec(tmp);
	i = 0;
	while (i < s->size)
	{
		if (s->vector[s->top] == tmp->vector[i])
			break ;
		i++;
	}
	free_stack(&tmp);
	return (i);
}

void	hf_top_insert(t_stack *s, int base)
{
	int	i;

	i = 0;
	while (i < s->top - base -1)
	{
		print_sa(s);
		print_ra(s);
		i++;
	}
	print_sa(s);
	i = 0;
	while (i < s->top - base - 1)
	{
		print_rra(s);
		i++;
	}
}

void	hf_bottom_insert(t_stack *s, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		print_rra(s);
		print_sa(s);
		i++;
	}
	i = 0;
	while (i < base + 1)
	{
		print_ra(s);
		i++;
	}
}

void	hf_sort_partial(t_stack *s)
{
	int	i;

	i = hf_get_pos(s);
	if (i == s->top)
		return ;
	if (i == 0)
	{
		print_ra(s);
		return ;
	}
	if (s->top - i == 1)
	{
		print_sa(s);
		return ;
	}
	if ((3 * (s->top - i - 1) + 1) < (2 * i + (i + 1)))
		hf_top_insert(s, i);
	else
		hf_bottom_insert(s, i);
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
		print_pb(a, b);
	sort_three(a);
	while (b->top >= 0)
	{
		print_pa(a, b);
		hf_sort_partial(a);
	}
	free_stack(&b);
}
