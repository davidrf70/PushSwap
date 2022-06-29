/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:52:39 by David RF          #+#    #+#             */
/*   Updated: 2022/06/29 23:18:00 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*hf_allocate_memory(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->vector = malloc(size * sizeof(unsigned int));
	if (!stack->vector)
		return (NULL);
	stack->size = size;
	stack->top = size - 1;
	return (stack);
}

/*
*	radix_sort_dec algorithm orders stack with minimum element 
*	on top of stack (i = size - 1)
*	So, ordered stack must be reversed
*/
void	hf_normalize(t_stack *s)
{
	t_stack	*order;
	int		i;

	order = empty_stack(s->size);
	i = 0;
	while (i < s->size)
	{
		order->vector[i] = s->vector[i];
		i++;
	}
	order->top = s->size - 1;
	radix_sort_dec(order);
	reverse_stack(order);
	i = 0;
	while (i < s->size)
	{
		s->vector[i] = search_elem(order->vector, s->vector[i]);
		i++;
	}
	free_stack(&order);
}

int	hf_check_arg(char *s_arg, int i_arg)
{
	char	*tmp_str;
	int		check;
	int		len;
	int		cmp1;
	int		cmp2;

	len = ft_strlen(s_arg);
	cmp1 = ft_strncmp(s_arg, "0", 1);
	tmp_str = ft_itoa(i_arg);
	cmp2 = ft_strncmp(tmp_str, s_arg, len);
	check = 1;
	if ((!i_arg && cmp1) || (i_arg == -1 && len > 2) || cmp2)
		check = 0;
	free(tmp_str);
	return (check);
}

/*
*	First program argument on stack top
*	stack->vector[0]: Stack base
*	stack->vector[top]: Stack top
*/
t_stack	*load_stack(int size, char **argv)
{
	t_stack	*stack;
	int		i;
	int		elem;
	char	*arg;

	if (!argv || size < 1)
		return (NULL);
	stack = hf_allocate_memory(size);
	i = 0;
	while (i < size)
	{
		arg = argv[size - 1 - i];
		elem = ft_atoi(arg);
		if (!hf_check_arg(arg, elem))
			return (NULL);
		stack->vector[i] = INT_MAX + elem;
		i++;
	}
	hf_normalize(stack);
	return (stack);
}
