/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:27:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift up all elements of stack by 1. The first element becomes the last one.
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stacks *stacks, bool print)
{
	rotate(&(stacks->a));
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks, bool print)
{
	rotate(&(stacks->b));
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks, bool print)
{
	rotate(&(stacks->a));
	rotate(&(stacks->b));
	if (print)
		ft_putstr_fd("rr\n", 1);
}
