/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 01:44:21 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:05:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include <stdio.h>

// static void	print_val(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d, ", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// static void	print_idx(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d, ", stack->index);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

// static void	print_two(t_two *two)
// {
// 	printf("A: ");
// 	print_val(two->a);
// 	printf("A: ");
// 	print_idx(two->a);
// 	printf("B: ");
// 	print_val(two->b);
// 	printf("B: ");
// 	print_idx(two->b);
// }

static void	a_to_b(t_two **two, int size, int range)
{
	int	i;
	int	idx;

	i = -1;
	while ((*two)->a)
	{
		idx = (*two)->a->index;
		if (idx <= i)
			pb((++i, two));
		else if (idx <= i + range)
		{
			pb(two);
			rb(two);
			++i;
		}
		else
			ra(two);
	}
}

static void	search_max_push(t_two **two, int size)
{
	t_stack	*node;
	int		idx;
	int		b_len;

	idx = 0;
	node = (*two)->b;
	b_len = get_stack_len((*two)->b);
	while (node && node->index != size - 1)
		node = (idx++, node->next);
	if (idx <= b_len / 2)
		while (idx--)
			rb(two);
	else
		while (size-- - idx)
			rrb(two);
	pa(two);
}

static void	b_to_a(t_two **two, int size)
{
	while ((*two)->b)
	{
		if ((*two)->b->index == size - 1)
			pa(two);
		else if ((*two)->b->next
			&& (*two)->b->next->index == size - 1)
		{
			sb(two);
			pa(two);
		}
		else
			search_max_push(two, size);
		size--;
	}
}

void	push_swap_more(t_two **two, int size, int range)
{
	a_to_b(two, size, range);
	b_to_a(two, size);
}
