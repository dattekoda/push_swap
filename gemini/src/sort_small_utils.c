/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:28:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Pushes the node with the smallest index from stack_a to stack_b.
// Assumes indexes are assigned.
void	push_smallest_to_b(t_stacks *stacks)
{
	int	pos_smallest;
	int	size_a;
	int	i;

	pos_smallest = find_smallest_index_pos(stacks->a);
	size_a = stacks->size_a;
	if (pos_smallest == -1)
		return ;
	i = 0;
	if (pos_smallest <= size_a / 2) // If in first half, ra
	{
		while (i < pos_smallest)
		{
			ra(stacks, true);
			i++;
		}
	}
	else // If in second half, rra
	{
		while (i < (size_a - pos_smallest))
		{
			rra(stacks, true);
			i++;
		}
	}
	pb(stacks, true);
}
