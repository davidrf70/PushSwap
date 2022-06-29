/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:30 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 12:51:31 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pa(t_stack *a, t_stack *b)
{
	pa(a, b);
	ft_print_str("pa\n", 1);
}

void	print_pb(t_stack *a, t_stack *b)
{
	pb(a, b);
	ft_print_str("pb\n", 1);
}

void	print_ra(t_stack *a)
{
	ra(a);
	ft_print_str("ra\n", 1);
}

void	print_rb(t_stack *b)
{
	ra(b);
	ft_print_str("rb\n", 1);
}

void	print_rr(t_stack *a, t_stack *b)
{
	rr(a, b);
	ft_print_str("rr\n", 1);
}
