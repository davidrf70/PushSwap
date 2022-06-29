/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:52:36 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:51:12 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isempty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	else
		return (0);
}

int	isfull(t_stack *stack)
{
	if (stack->top == stack->size - 1)
		return (1);
	else
		return (0);
}

int	pop(t_stack *stack)
{
	int	data;

	data = 0;
	if (!isempty(stack))
	{
		data = stack->vector[stack->top];
		stack->top--;
	}
	return (data);
}

void	push(t_stack *stack, int data)
{
	if (!isfull(stack))
	{
		stack->top++;
		stack->vector[stack->top] = data;
	}
}
