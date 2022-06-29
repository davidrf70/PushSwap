/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:35 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:11:38 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rra(t_stack *a)
{
	rra(a);
	ft_print_str("rra\n", 1);
}

void	print_rrb(t_stack *b)
{
	rrb(b);
	ft_print_str("rrb\n", 1);
}

void	print_rrr(t_stack *a, t_stack *b)
{
	rrr(a, b);
	ft_print_str("rrr\n", 1);
}

void	print_sa(t_stack *a)
{
	sa(a);
	ft_print_str("sa\n", 1);
}

void	print_sb(t_stack *b)
{
	sb(b);
	ft_print_str("sb\n", 1);
}
