#include "push_swap.h"

void	hf_process_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(cmd, "sa", 2))
		sa(a);
	else if (!ft_strncmp(cmd, "sb", 2))
		sb(b);
	else if (!ft_strncmp(cmd, "ss", 2))
		ss(a, b);
	else if (!ft_strncmp(cmd, "pa", 2))
		pa(a, b);
	else if (!ft_strncmp(cmd, "pb", 2))
		pb(a, b);
	else if (!ft_strncmp(cmd, "rra", 3))
		rra(a);
	else if (!ft_strncmp(cmd, "rrb", 3))
		rrb(b);
	else if (!ft_strncmp(cmd, "rrr", 3))
		rrr(a, b);
	else if (!ft_strncmp(cmd, "ra", 2))
		ra(a);
	else if (!ft_strncmp(cmd, "rb", 2))
		rb(b);
	else if (!ft_strncmp(cmd, "rr", 2))
		rr(a, b);
}

int		hf_check_solution(t_stack *a, t_stack *b)
{
	if (is_sort(a) && isempty(b))
		return (1);
	return (0);
}

void	hf_search_eol(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
		cmd[i - 1] = 0;
	else
		cmd[i] = 0;
}

void	hf_read_do_actions(t_stack *a, t_stack *b)
{
	char	*cmd;

	while (1)
	{
		cmd = ft_get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		hf_search_eol(cmd);
		hf_process_cmd(cmd, a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	a = load_stack(argc - 1, argv + 1);
	b = empty_stack(argc - 1);
	if (error_mng(a) || !b)
	{
		ft_print_str("Error\n", 2);
		return (1);
	}
	hf_read_do_actions(a, b);
	if (hf_check_solution(a, b))
		ft_print_str("OK\n", 1);
	else
		ft_print_str("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
    return 0;
}
