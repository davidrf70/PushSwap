#include "push_swap.h"

void	hf_print_command(t_stack *stack, t_stack *tmp, char *str, int print)
{
	if (print)
		ft_print_str(str, 1);
	else
		copy_stack(tmp, stack);
}

int	hf_sol_1(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	rra(stack);
	if (is_sort(stack))
	{
		hf_print_command(stack, tmp, "rra\n", print);
		return (1);
	}
	copy_stack(tmp, stack);
	sa(stack);
	if (is_sort(stack))
	{
		hf_print_command(stack, tmp, "sa\n", print);
		return (1);
	}
	copy_stack(tmp, stack);
	return (0);
}

int	hf_sol_2(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	sa(stack);
	rra(stack);
	if (is_sort(stack))
	{
		hf_print_command(stack, tmp, "sa\nrra\n", print);
		return (1);
	}
	copy_stack(tmp, stack);
	rra(stack);
	sa(stack);
	if (is_sort(stack))
	{
		hf_print_command(stack, tmp, "rra\nsa\n", print);
		return (1);
	}
	copy_stack(tmp, stack);
	return (0);
}

int	hf_sol_3(t_stack *stack, t_stack *tmp, int print)
{
	copy_stack(stack, tmp);
	sa(stack);
	rra(stack);
	sa(stack);
	if (is_sort(stack))
	{
		hf_print_command(stack, tmp, "sa\nrra\nsa\n", print);
		return (1);
	}
	copy_stack(tmp, stack);
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
	else if(hf_sol_2(stack, tmp, 0))
		hf_sol_2(stack, tmp, 1);
	else
		hf_sol_3(stack, tmp, 1);
	free_stack(&tmp);
}