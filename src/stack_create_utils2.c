/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:52:42 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 15:04:42 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*empty_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->vector = malloc(size * sizeof(unsigned int));
	if (!stack->vector)
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

t_stack	*copy_stack(t_stack *src, t_stack *dest)
{
	int	i;

	if (!src || !dest)
		return (NULL);
	dest->size = src->size;
	dest->top = src->top;
	i = 0;
	while (i <= src->top)
	{
		dest->vector[i] = src->vector[i];
		i++;
	}
	return (dest);
}

unsigned int	search_elem(unsigned int *array, unsigned int elem)
{
	unsigned int	i;

	i = 0;
	while (array[i] != elem)
		i++;
	return (i);
}

void	reverse_stack(t_stack *s)
{
	int				init;
	int				end;
	unsigned int	tmp;

	init = 0;
	end = s->top;
	while (init < end)
	{
		tmp = s->vector[end];
		s->vector[end] = s->vector[init];
		s->vector[init] = tmp;
		init++;
		end--;
	}
}
