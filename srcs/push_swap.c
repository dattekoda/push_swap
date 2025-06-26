/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:05:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:06:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	roop_check(t_two **two, int size)
{
	int		i;
	t_stack	*node;

	node = (*two)->a;
	i = node->index;
	while (node && node->index == i)
	{
		node = node->next;
		i = (i + 1) % size;
	}
	if (node)
		return (FAILURE);
	if ((*two)->a->index == size - 1 || (*two)->a->index == size - 2)
		while ((*two)->a->index != 0)
			ra(two);
	else
		while ((*two)->a->index != 0)
			rra(two);
	return (SUCCESS);
}

void	push_swap(t_two **two, int size)
{
	if (!roop_check(two, size))
		return ;
	else if (size == 2 && (*two)->a->index == 1)
		sa(two);
	else if (size == 3)
		push_swap_three(two, 2);
	else if (size == 5 || size == 4)
		push_swap_five(two, size);
	else if (size <= 100)
		push_swap_more(two, size, RANGE_FEWER);
	else
		push_swap_more(two, size, RANGE_MORE);
}
