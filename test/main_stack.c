#include "../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_two(t_two *two)
{
	printf("A: ");
	print_stack(two->a);
	printf("B: ");
	print_stack(two->b);
}

int	main(int argc, char *argv[])
{
	t_two	*two;
	t_stack	*node;

	if (argc == 1)
		return (1);
	two = init_two();
	if (!two)
		return (1);
	while (--argc)
	{
		node = malloc(sizeof(t_stack));
		node->value = ft_atoi(argv[argc]);
		node->index = 0;
		push_stack(&(two->a), node);
	}
	print_two(two);

	sa(&two);
	print_two(two);
	pb(&two);
	print_two(two);
	pb(&two);
	print_two(two);
	pb(&two);
	print_two(two);
	pa(&two);
	print_two(two);
	ra(&two);
	print_two(two);
	ra(&two);
	print_two(two);
	ra(&two);
	print_two(two);
	sb(&two);
	print_two(two);

	free_two(&two);
	return (0);
}