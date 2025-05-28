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

static int	ft_atoi(const char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s == ' ' || (9 <= *s && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		sign = (s++, -1 + 2 * (*s == '+'));
	while (*s && ('0' <= *s && *s <= '9'))
		num = num * 10 + (*(s++) - '0');
	return (num * sign);
}

int	main(int argc, char *argv[])
{
	t_two	*two;
	int		i;

	i = 0;
	two = init_two();
	if (!two)
		return (1);
	while (++i < argc)
		push_stack(&(two->a), ft_atoi(argv[i]));
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