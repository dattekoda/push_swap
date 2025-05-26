/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:26:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (true); // An empty stack is considered sorted
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Returns the 0-based position of the node with the smallest index
int	find_smallest_index_pos(t_node *stack)
{
	int		min_index;
	int		pos;
	int		current_pos;
	t_node	*current;

	if (!stack)
		return (-1);
	min_index = stack->index;
	pos = 0;
	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (pos);
}

// Gets the value of the node at a given 0-based position
int	get_node_value_at_pos(t_node *stack, int pos)
{
	int		current_pos;
	t_node	*current;

	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current_pos == pos)
			return (current->value);
		current = current->next;
		current_pos++;
	}
	return (0); // Should not happen if pos is valid
}
