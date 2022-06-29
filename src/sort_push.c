/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:49 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 12:51:50 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hf_push(t_stack *src, t_stack *dest)
{
	int	data;

	if (!isempty(src) && !isfull(dest))
	{
		data = pop(src);
		push(dest, data);
	}
}

void	pa(t_stack *a, t_stack *b)
{
	hf_push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	hf_push(a, b);
}
