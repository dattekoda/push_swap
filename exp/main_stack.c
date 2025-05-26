#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_AB(t_stack *a, t_stack *b)
{
	t_stack *_a = a;
	t_stack *_b = b;
	printf("A: ");
	print_stack(a);
	printf("B: ");
	print_stack(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	int		i;

	a = init_stack();
	b = init_stack();
	i = 0;

	while (++i < argc)
		push_stack(&a, atoi(argv[i]));
	print_AB(a, b);

	swap_stack(&a);
	print_AB(a, b);

	push_stack(&b, pop_stack(&a));
	print_AB(a, b);

	free_stack(&a);
	free_stack(&b);
	return (0);
}