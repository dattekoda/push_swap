#include "../includes/push_swap.h"

static int	ft_isnumber(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s && ('0' <= *s && *s <= '9'))
		s++;
	return (*s == '\0');
}

static void	is_validate(int argc, char *argv[])
{
	while (--argc)
		if (!ft_isnumber(argv[argc]))
			err();
}

t_two *parse_num_to_two(int argc, char *argv[])
{
	t_two 	*two;
	int		i;

	is_validate(argc, argv);
	two = init_two();
	if (!two)
		err();
	i = 0;
	while (--argc)
	{
		if (push_stack(&(two->a), ft_atoi(argv[argc])))
		{
			free_two(&two);
			err();
		}
	}
	return (two);
}

// #include <stdio.h>

// static void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d, ", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// static void	print_two(t_two *two)
// {
// 	printf("A: ");
// 	print_stack(two->a);
// 	printf("B: ");
// 	print_stack(two->b);
// }

// int	main(int argc, char *argv[])
// {
// 	t_two *two = parse_num_to_two(argc, argv);
// 	print_two(two);
// 	free_two(&two);
// 	return (0);
// }