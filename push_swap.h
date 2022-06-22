#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdlib.h>
# include	"libft.h"
# include	"get_next_line.h"

typedef struct	s_stack
{
	unsigned int *vector;
	int size;
	int	top;
}	t_stack;

void	print_stacks(t_stack *a, t_stack *b);

t_stack	*empty_stack(int size);
t_stack	*load_stack(int size, char **argv);
t_stack	*copy_stack(t_stack *src, t_stack *dest);
void	free_stack(t_stack **stack);
int		is_sort(t_stack *stack);
int		error_mng(t_stack *stack);

void	print_pa(t_stack *a, t_stack *b);
void	print_pb(t_stack *a, t_stack *b);
void	print_ra(t_stack *a);
void	print_rra(t_stack *a);
void	print_sa(t_stack *a);

void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_gt_three(t_stack *a);
void	radix_sort(t_stack *a);
void	quick_sort(t_stack *a);
void 	radix_sort_dec(t_stack *a);

int 	isempty(t_stack *stack);
int 	isfull(t_stack *stack);
int		pop(t_stack *stack);
void	push(t_stack *stack, int data);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif