/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:20:10 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Note: The Norm forbids `for` loops. All loops must be `while`.

static void	add_num_to_stack(int num, t_stacks *stacks)
{
	t_node	*node;

	node = new_node(num);
	if (!node)
		exit_error(stacks); // Malloc failure
	add_node_to_list_back(&(stacks->a), node);
	stacks->size_a++;
}

void	parse_arguments(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	long	num_long;
	int		num_int;
	int		error_flag;

	i = 1;
	error_flag = 0;
	while (i < argc)
	{
		num_long = ft_atoi_checked(argv[i], &error_flag);
		if (error_flag || num_long > INT_MAX || num_long < INT_MIN)
			exit_error(stacks);
		num_int = (int)num_long;
		add_num_to_stack(num_int, stacks);
		i++;
	}
	if (stacks->size_a == 0) // No valid numbers provided
		exit_error(stacks);
}
