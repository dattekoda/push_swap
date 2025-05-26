/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:27:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift down all elements of stack by 1. The last element becomes the first one.
static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last) // If more than one element
		second_last->next = NULL;
	else // Only one element, rra on one element does nothing (handled by guard)
		return ;   // but this is for when stack had 2 elements, *stack becomes NULL
	last->next = *stack;
	*stack = last;
}

void	rra(t_stacks *stacks, bool print)
{
	reverse_rotate(&(stacks->a));
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks, bool print)
{
	reverse_rotate(&(stacks->b));
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks, bool print)
{
	reverse_rotate(&(stacks->a));
	reverse_rotate(&(stacks->b));
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
