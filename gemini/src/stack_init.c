/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:26:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1; // Initialize index, to be set later
	node->next = NULL;
	return (node);
}

// Used by parsing_args to build initial stack_a in order
void	add_node_to_list_back(t_node **stack, t_node *node)
{
	t_node	*current;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = node;
}

// Used by push operations (pa, pb)
void	add_node_front(t_node **stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	*stack = node;
}

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
}
