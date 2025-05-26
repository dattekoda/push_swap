/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:14:58 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:15:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_logic(t_stacks *stacks)
{
	if (is_sorted(stacks->a) || stacks->size_a <= 1)
		return ;
	assign_indexes(stacks); // Essential for most sorting strategies
	if (stacks->size_a == 2)
		sa(stacks, true);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4)
		sort_four(stacks);
	else if (stacks->size_a == 5)
		sort_five(stacks);
	else
		radix_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	init_stacks(&stacks);
	parse_arguments(argc, argv, &stacks);
	validate_duplicates(&stacks);
	sort_logic(&stacks);
	free_stacks_and_exit(&stacks, 0);
	return (0);
}
