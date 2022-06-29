/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:20:06 by David RF          #+#    #+#             */
/*   Updated: 2022/06/29 21:21:00 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hf_sol_1(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	ra(tmp);
	if (is_sort(tmp))
	{
		if (print)
			print_ra(stack);
		return (1);
	}
	return (0);
}

int	hf_sol_2(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	sa(tmp);
	if (is_sort(tmp))
	{
		if (print)
			print_sa(stack);
		return (1);
	}
	copy_stack(stack, tmp);
	rra(tmp);
	if (is_sort(tmp))
	{
		if (print)
			print_rra(stack);
		return (1);
	}
	return (0);
}

int	hf_sol_3(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	rra(tmp);
	sa(tmp);
	if (is_sort(tmp))
	{
		if (print)
		{
			print_rra(stack);
			print_sa(stack);
		}
		return (1);
	}
	return (0);
}

int	hf_sol_4(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	sa(tmp);
	rra(tmp);
	if (is_sort(tmp))
	{
		if (print)
		{
			print_sa(stack);
			print_rra(stack);
		}
		return (1);
	}
	return (0);
}

void	sort_three(t_stack *stack)
{
	t_stack	*tmp;

	tmp = empty_stack(stack->size);
	if (!tmp)
		return ;
	if (hf_sol_1(stack, tmp, 0))
		hf_sol_1(stack, tmp, 1);
	else if (hf_sol_2(stack, tmp, 0))
		hf_sol_2(stack, tmp, 1);
	else if (hf_sol_3(stack, tmp, 0))
		hf_sol_3(stack, tmp, 1);
	else if (hf_sol_4(stack, tmp, 0))
		hf_sol_4(stack, tmp, 1);
	free_stack(&tmp);
}
