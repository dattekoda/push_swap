/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:28:52 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/17 23:29:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isnumber(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s && ('0' <= *s && *s <= '9'))
		s++;
	return (*s == '\0');
}

static int	*ft_intdup(int *nums, int length)
{
	int	*dup;

	dup = (int *)malloc(sizeof(int) * length);
	if (!dup)
		return (NULL);
	while (length--)
		dup[length] = nums[length];
	return (dup);
}

static int	get_sorted_idx_checking_dup(int arr[], int length)
{
	int	i;
	int	j;
	int	*_arr;

	i = length;
	_arr = ft_intdup(arr, length);
	if (!_arr)
		return (1);
	ft_qsort(arr, 0, length - 1);
	while (--i)
		if (_arr[i] == arr[i - 1])
			return (free(_arr), 1);
	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length)
			if (_arr[i] == arr[j])
				arr[i] = j;
	}
	return (free(_arr), 0);
}

static void	is_validate(int argc, char *argv[], int *arr)
{
	int	_argc;

	_argc = argc;
	while (--_argc)
	{
		if (!ft_isnumber(argv[_argc]))
		{
			free(arr);
			err();
		}
		arr[_argc - 1] = ft_atoi(argv[_argc]);
	}
	if (get_sorted_idx_checking_dup(arr, argc - 1))
	{
		free(arr);
		err();
	}
}

static int	first_push(int argc, char *argv[], t_two **two, int *idx)
{
	t_stack	*node;

	while (--argc)
	{
		node = malloc(sizeof(t_stack));
		if (!node)
			return (1);
		node->value = ft_atoi(argv[argc]);
		node->index = idx[argc - 1];
		push_stack(&((*two)->a), node);
	}
	return (0);
}

t_two	*parse_num_to_two(int argc, char *argv[])
{
	t_two	*two;
	int		*idx;

	idx = (int *)malloc(sizeof(int) * (argc - 1));
	if (!idx)
		err();
	is_validate(argc, argv, idx);
	two = init_two();
	if (!two)
	{
		free(idx);
		err();
	}
	if (first_push(argc, argv, &two, idx))
	{
		free_two(&two);
		free(idx);
		err();
	}
	return (two);
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
// 	printf("B: ");
// 	print_stack(two->b, 0);
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		return (1);
// 	t_two *two = parse_num_to_two(argc, argv);
// 	print_two(two);
// 	free_two(&two);
// 	return (0);
// }