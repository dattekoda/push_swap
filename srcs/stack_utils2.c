/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:05:06 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/20 02:19:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_stack(t_stack **head)
{
	t_stack	*first;
	t_stack	*tail;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	first->next = NULL;
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = first;
}

void	rev_rotate_stack(t_stack **head)
{
	t_stack	*prev;
	t_stack	*tail;

	if (!*head || !(*head)->next)
		return ;
	prev = NULL;
	tail = *head;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->next = *head;
	*head = tail;
}

t_two	*init_two(void)
{
	t_two	*two;

	two = (t_two *)malloc(sizeof(t_two));
	if (!two)
		return (NULL);
	two->a = NULL;
	two->b = NULL;
	return (two);
}

void	free_two(t_two **two)
{
	free_stack(&((*two)->a));
	free_stack(&((*two)->b));
	free(*two);
}

void	pb(t_two **two)
{
	write(1, "pb\n", 3);
	if ((*two)->a)
		push_stack(&((*two)->b), pop_stack(&((*two)->a)));
}
