/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:16:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stacks *stacks, bool print)
{
	swap(&(stacks->a));
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks, bool print)
{
	swap(&(stacks->b));
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks, bool print)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	if (print)
		ft_putstr_fd("ss\n", 1);
}
