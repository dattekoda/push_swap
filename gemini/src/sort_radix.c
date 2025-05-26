/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:17:13 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Helper to find max bits needed for radix sort
static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = size - 1;
	if (max_num < 0) // handles size 0 or 1
		return (0);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	max_bits;
	int	original_size_a;

	max_bits = get_max_bits(stacks->size_a);
	i = 0;
	while (i < max_bits)
	{
		original_size_a = stacks->size_a;
		j = 0;
		while (j < original_size_a)
		{
			if (((stacks->a->index >> i) & 1) == 1) // If bit is 1
				ra(stacks, true);
			else // If bit is 0
				pb(stacks, true);
			j++;
		}
		while (stacks->size_b != 0)
			pa(stacks, true);
		i++;
	}
}
