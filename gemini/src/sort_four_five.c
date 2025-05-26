/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:29:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Assumes stack_a has 4 elements and indexes are assigned.
void	sort_four(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	push_smallest_to_b(stacks); // Push element with index 0 to b
	sort_three(stacks);
	pa(stacks, true);
}

// Assumes stack_a has 5 elements and indexes are assigned.
void	sort_five(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	push_smallest_to_b(stacks); // Push element with index 0 to b
	push_smallest_to_b(stacks); // Push element with index 1 to b
	sort_three(stacks);
	pa(stacks, true); // Push back index 1
	pa(stacks, true); // Push back index 0
}
