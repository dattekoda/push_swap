/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:44:56 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:44:57 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_new(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	stack_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node *node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	stack_clear(t_stack *stack)
{
	t_node *tmp;
	t_node *next;

	if (!stack)
		return ;
	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(stack);
}