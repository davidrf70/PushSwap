#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size - 1;
	while (i >= 0)
	{
		if (i <= a->top)
			printf("%d ", a->vector[i]);
		else
			printf("* ");
		if (b)
		{
			if (i <= b->top)
				printf("%d", b->vector[i]);
			else
				printf("*");
		}
		printf("\n");
		i--;
	}
	if (b)
	{
		printf("- -\n");
		printf("a b\n");
	}
	else
	{
		printf("-\n");
		printf("a\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 3)
		return (0);
	stack_a = load_stack(argc - 1, argv + 1);
	if (error_mng(stack_a))
	{
		ft_print_str("Error\n", 2);
		return (1);
	}
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc > 4 && argc < 22)
		sort_gt_three(stack_a);
	else
		radix_sort(stack_a); 
	free_stack(&stack_a);
	return (0);
}