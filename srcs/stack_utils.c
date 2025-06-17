/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:05:03 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/17 23:05:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}
}

void	push_stack(t_stack **head, t_stack *node)
{
	if (!node || !head)
		return ;
	node->next = *head;
	*head = node;
}

t_stack	*pop_stack(t_stack **head)
{
	t_stack	*node;

	if (!*head || !head)
		return (NULL);
	node = *head;
	*head = node->next;
	node->next = NULL;
	return (node);
}

void	swap_stack(t_stack **head)
{
	t_stack	*first;
	t_stack *second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	pa(t_two **two)
{
	write(1, "pa\n", 3);
	if ((*two)->b)
		push_stack(&((*two)->a), pop_stack(&((*two)->b)));
}
