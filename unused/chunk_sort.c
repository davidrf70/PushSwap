#include "push_swap.h"

typedef struct s_comb
{
	int	id;
	int	nro_actions;
} t_comb;

int	search_base(t_stack *s, int lim)
{
	int	i;

	i = 0;
	while (s->vector[i] > (unsigned int)lim && i <= s->top)
		i++;
	return (i);
}

int	search_top(t_stack *s, int lim)
{
	int	i;

	i = s->top;
	while (s->vector[i] > (unsigned int)lim && i >=0)
		i--;
	return (i);
}

int	search_min(t_stack *s)
{
	int	i;
	int	min;
	int	i_min;

	min = UINT_MAX;
	i_min = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->vector[i] < (unsigned int)min)
		{
			min = s->vector[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

int	search_max(t_stack *s)
{
	int	i;
	int	max;
	int	i_max;

	max = 0;
	i_max = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->vector[i] > (unsigned int)max)
		{
			max = s->vector[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

void	do_rrr(t_stack *a, t_stack *b, int n_rra, int n_rrb)
{
	int	i;
	
	i = 0;
	while (i < n_rra && i < n_rrb)
	{
		print_rrr(a, b);
		i++;
	}
	while (i < n_rra)
	{
		print_rra(a);
		i++;
	}
	while (i < n_rrb)
	{
		print_rrb(b);
		i++;
	}
}

void	do_rra_rb(t_stack *a, t_stack *b, int n_rra, int n_rb)
{
	int	i;

	i = 0;
	while (i < n_rra)
	{
		print_rra(a);
		i++;
	}
	i = 0;
	while (i < n_rb)
	{
		print_rb(b);
		i++;
	}
}

void	do_rr(t_stack *a, t_stack *b, int n_ra, int n_rb)
{
	int	i;
	
	i = 0;
	while (i < n_ra && i < n_rb)
	{
		print_rr(a, b);
		i++;
	}
	while (i < n_ra)
	{
		print_ra(a);
		i++;
	}
	while (i < n_rb)
	{
		print_rb(b);
		i++;
	}
}

void	do_ra_rrb(t_stack *a, t_stack *b, int n_ra, int n_rrb)
{
	int	i;

	i = 0;
	while (i < n_ra)
	{
		print_ra(a);
		i++;
	}
	i = 0;
	while (i < n_rrb)
	{
		print_rrb(b);
		i++;
	}
}

/*
*	comb[0]: max(rra, rrb)
*	comb[1]: rra + rb
*	comb[2]: max(ra, rb)
*	comb[3]: ra + rrb
*/
int		min_actions(int *actions)
{
	t_comb	comb[4];
	int		min;
	int		i;
	int		j;

	comb[0].id = 0;
	comb[0].nro_actions = max(actions[0], actions[2]);
	comb[1].id = 1;
	comb[1].nro_actions = actions[0] + actions[3];
	comb[2].id = 2;
	comb[2].nro_actions = max(actions[1], actions[3]);
	comb[3].id = 3;
	comb[3].nro_actions = actions[1] + actions[2];
	min = comb[0].nro_actions;
	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (comb[j].nro_actions < min)
				min = j;
			j++;
		}
		i++;
	}
	return (min);
}

/*
*	action[0]: nro rra
*	action[1]: nro ra
*	action[2]: nro rrb 
*	action[3]: nro rb
*/
void	do_actions(t_stack *a, t_stack *b, int top, int base, int min)
{
	int	actions[4];
	int	option;

	if (a->top == -1)
	{
		actions[0] = 0;
		actions[1] = 0;
	}
	else
	{
		actions[0] = base + 1;
		actions[1] = a->top - top;
	}
	if (b->top == -1)
	{
		actions[2] = 0;
		actions[3] = 0;
	}
	else
	{
		actions[2] = min + 1;
		actions[3] = b->top - min;
	}
	option = min_actions(actions);
	if (option == 0)
		do_rrr(a, b, actions[0], actions[2]);
	else if (option == 1)
		do_rra_rb(a, b, actions[0], actions[3]);
	else if (option == 2)
		do_rr(a, b, actions[1], actions[3]);
	else
		do_ra_rrb(a, b, actions[1], actions[2]);
	print_pb(a, b);
}

void	chunk_sort(t_stack *a, int chunk_size)
{
	t_stack	*b;
	int		lim;
	int		mov_top;
	int		mov_base;
	int		b_id;

	b = empty_stack(a->size);
	if (!b)
		return ;
	lim = chunk_size;
	while (!isempty(a))
	{
		while (1)
		{
			mov_top = search_top(a, lim);
			if (mov_top < 0)
				break ;
			mov_base = search_base(a, lim);
			b_id = search_min(b);
			do_actions(a, b, mov_top, mov_base, b_id);
		}
		lim = lim + chunk_size;
	}
	while (!isempty(b))
	{
		b_id = search_max(b);
		if ((b->top - b_id) < (b_id + 1))
			while (b_id < b->top)
			{
				print_rb(b);
				b_id++;
			}
		else
			while (b_id >= 0)
			{
				print_rrb(b);
				b_id--;
			}
		print_pa(a, b);
	}
}