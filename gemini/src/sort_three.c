/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:38:53 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Assumes stack_a has exactly 3 elements and indexes are assigned.
// Indexes for 3 elements will be 0, 1, 2.
void	sort_three(t_stacks *stacks)
{
	t_node	*top;
	t_node	*mid;

	if (is_sorted(stacks->a))
		return ;
	top = stacks->a;
	mid = top->next;
	if (top->index == 0 && mid->index == 2) // 0 2 1 -> rra, sa
	{
		rra(stacks, true);
		sa(stacks, true);
	}
	else if (top->index == 1 && mid->index == 0) // 1 0 2 -> sa
		sa(stacks, true);
	else if (top->index == 1 && mid->index == 2) // 1 2 0 -> rra
		rra(stacks, true);
	else if (top->index == 2 && mid->index == 0) // 2 0 1 -> ra
		ra(stacks, true);
	else if (top->index == 2 && mid->index == 1) // 2 1 0 -> sa, rra
	{
		sa(stacks, true);
		rra(stacks, true);
	}
}
