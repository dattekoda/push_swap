/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:46:44 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:55:17 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_node	*tmp;

	max = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	assign_indices(t_stack *a, int count)
{
	int		 idx;
	int		 min_val;
	// int		 min_idx;
	t_node	*tmp;

	idx = 0;
	while (idx < count)
	{
		min_val = INT_MAX;
		tmp = a->top;
		while (tmp)
		{
			if (tmp->index == 0 && tmp->value < min_val)
			{
				min_val = tmp->value;
				// min_idx = idx;
			}
			tmp = tmp->next;
		}
		tmp = a->top;
		while (tmp)
		{
			if (tmp->value == min_val && tmp->index == 0)
			{
				tmp->index = idx;
				break ;
			}
			tmp = tmp->next;
		}
		idx++;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		 i;
	int		 j;
	int		 size;
	int		 max_bits;

	size = a->size;
	assign_indices(a, size);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}
