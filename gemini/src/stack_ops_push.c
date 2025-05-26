/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:27:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Take the first element at the top of src and put it at the top of dst.
// Do nothing if src is empty.
static void	push(t_node **src, t_node **dst)
{
	t_node	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	node_to_push->next = *dst;
	*dst = node_to_push;
}

void	pa(t_stacks *stacks, bool print)
{
	if (stacks->size_b == 0)
		return ;
	push(&(stacks->b), &(stacks->a));
	stacks->size_a++;
	stacks->size_b--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks, bool print)
{
	if (stacks->size_a == 0)
		return ;
	push(&(stacks->a), &(stacks->b));
	stacks->size_b++;
	stacks->size_a--;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
