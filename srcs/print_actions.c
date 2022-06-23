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

void	print_rra(t_stack *a)
{
	rra(a);
	ft_print_str("rra\n", 1);
}

void	print_sa(t_stack *a)
{
	sa(a);
	ft_print_str("sa\n", 1);
}