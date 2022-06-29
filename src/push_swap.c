/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:39 by David RF          #+#    #+#             */
/*   Updated: 2022/06/29 23:02:29 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	La rotación del caso particular de 5 elementos (elementos 2 y 3 en cabecera)
*	se realiza para deshacer el caso peor de ordenamiento
*/
void	hf_mng_algorithms(t_stack *a, int argc)
{
	if (argc == 3)
		sort_two(a);
	else if (argc == 4)
		sort_three(a);
	else if (argc == 6)
	{
		if ((a->vector[4] == 2 && a->vector[3] == 3)
			|| (a->vector[4] == 3 && a->vector[3] == 2))
			print_rra(a);
		sort_gt_three(a);
	}
	else if (argc < 22)
		sort_gt_three(a);
	else
		radix_sort(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 3)
		return (0);
	a = load_stack(argc - 1, argv + 1);
	if (error_mng(a))
	{
		ft_print_str("Error\n", 2);
		free_stack(&a);
		return (1);
	}
	if (is_sort(a))
	{	
		free_stack(&a);
		return (0);
	}
	hf_mng_algorithms(a, argc);
	free_stack(&a);
	return (0);
}
