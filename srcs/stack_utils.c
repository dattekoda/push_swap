/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:05:03 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:06:19 by khanadat         ###   ########.fr       */
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
	t_stack	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

int	get_stack_len(t_stack *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
		node = (len++, node->next);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_stack	*head;
// 	t_stack *node;
// 	int	i;

// 	head = NULL;
// 	for (i = 0; i < 10; i++)
// 	{
// 		node = malloc(sizeof(t_stack));
// 		node->value = i * i;
// 		node->index = i;
// 		push_stack(&head, node);
// 	}
// 	printf("%d\n", get_stack_len(head));
// 	free_stack(&head);
// 	return (0);
// }