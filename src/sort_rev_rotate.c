/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:52:05 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:16:27 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hf_rev_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	tmp = stack->vector[0];
	i = 0;
	while (i < stack->top)
	{
		stack->vector[i] = stack->vector[i + 1];
		i++;
	}
	stack->vector[i] = tmp;
}

void	rra(t_stack *a)
{
	hf_rev_rotate(a);
}

void	rrb(t_stack *b)
{
	hf_rev_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	hf_rev_rotate(a);
	hf_rev_rotate(b);
}
