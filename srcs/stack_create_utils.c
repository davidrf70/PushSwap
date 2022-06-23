#include "push_swap.h"

t_stack	*empty_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->vector = malloc(size*sizeof(int));
	if (!stack->vector)
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

t_stack	*hf_allocate_memory(int size)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->vector = malloc(size*sizeof(int));
	if (!stack->vector)
		return (NULL);
	stack->size = size;
	stack->top = size - 1;
	return(stack);
}

void	hf_move2floor(t_stack *stack)
{
	unsigned int	min;
	int				i;

	i = stack->top;
	min = UINT_MAX;
	while (i >= 0)
	{
		if (stack->vector[i] < min)
			min = stack->vector[i];
		i--;
	}
	i = stack->top;
	while (i >= 0)
	{
		stack->vector[i] -= min; 
		i--;
	}
}

/*
*	First program argument to stack top
*	stack->vector[0]: Stack base
*	stack->vector[top]: Stack top
*/
t_stack	*load_stack(int size, char **argv)
{
	t_stack	*stack;
	int		i;
	int		elem;
	int		log;
	
	if (!argv || size < 1)
		return (NULL);
	stack = hf_allocate_memory(size);
	i = 0;
	while (i < size)
	{
		elem = ft_atoi(argv[size - 1 - i]);
		log = ft_strncmp(argv[size - 1 - i], "0", 1);
		if (!elem && ft_strncmp(argv[size - 1 - i], "0", 1)
			|| (elem == -1 && ft_strlen(argv[size - 1 - i]) > 2))
			return (NULL);
		stack->vector[i] = INT_MAX + elem;
		i++;
	}
	hf_move2floor(stack);
	return (stack);
}

t_stack	*copy_stack(t_stack *src, t_stack *dest)
{
	int	i;

	if (!src || !dest)
		return (NULL);
	dest->size = src->size;
	dest->top = src->top;
	i = 0;
	while (i <= src->top)
	{
		dest->vector[i] = src->vector[i];
		i++;
	}
}
