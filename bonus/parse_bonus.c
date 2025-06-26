/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:28:52 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	*int_dup(int *array, int len)
{
	int	*dup;

	dup = malloc(sizeof(int) * len);
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = array[len];
	return (dup);
}

static int	first_push(int argc, t_two **two, int *array)
{
	t_stack	*node;
	int		idx;
	int		_argc;
	int		*sorted;

	sorted = int_dup(array, argc - 1);
	if (!sorted)
		return (FAILURE);
	_argc = argc;
	ft_qsort(sorted, 0, _argc - 2);
	while (argc-- - 1)
	{
		node = malloc(sizeof(t_stack));
		if (!node)
			return (free(sorted), FAILURE);
		node->value = array[argc - 1];
		idx = -1;
		while (++idx < _argc - 1)
			if (sorted[idx] == array[argc - 1])
				node->index = idx;
		push_stack(&((*two)->a), node);
	}
	return (free(sorted), SUCCESS);
}

t_two	*parse_num_to_two(int argc, char *argv[])
{
	t_two	*two;
	int		*array;

	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		err();
	if (is_validate(argc, argv, array))
		return (free(array), NULL);
	two = init_two();
	if (!two)
		return (free(array), NULL);
	if (first_push(argc, &two, array))
		return (free(array), free_two(&two), NULL);
	return (free(array), two);
}

// #include <stdio.h>

// static void	print_stack(t_stack *stack, int val_switch)
// {
// 	while (stack && val_switch)
// 	{
// 		printf("%d, ", stack->value);
// 		stack = stack->next;
// 	}
// 	while (stack && !val_switch)
// 	{
// 		printf("%d, ", stack->index);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// static void	print_two(t_two *two)
// {
// 	printf("A: ");
// 	print_stack(two->a, 0);
// 	printf("A: ");
// 	print_stack(two->a, 1);
// 	printf("B: ");
// 	print_stack(two->b, 0);
// 	printf("B: ");
// 	print_stack(two->b, 1);
// }

// int	main(int argc, char *argv[])
// {
// 	t_two *two;

// 	if (argc == 1)
// 		return (FAILURE);
// 	two = parse_num_to_two(argc, argv);
// 	if (!two)
// 		return (FAILURE);
// 	print_two(two);
// 	free_two(&two);
// 	return (SUCCESS);
// }
