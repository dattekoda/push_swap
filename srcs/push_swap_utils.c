/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:47:25 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/20 01:36:09 by khanadat         ###   ########.fr       */
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

void	push_swap_three(t_two **two, int largest)
{
	if ((*two)->a->index == largest)
	{
		if ((*two)->b && (*two)->b->index == 0)
			rr(two);
		else
			ra(two);
	}
	else if ((*two)->a->next->index == largest)
	{
		if ((*two)->b && (*two)->b->index == 0)
			rrr(two);
		else
			rra(two);
	}
	if ((*two)->a->index == largest - 1)
	{
		if ((*two)->b && (*two)->b->index == 0)
			ss(two);
		else
			sa(two);
	}
}

static int	roop_check(t_two **two, int size)
{
	int		i;
	t_stack	*node;

	node = (*two)->a;
	i = node->index;
	while (node && node->index == i)
	{
		node = node->next;
		i = (i + 1) % size;
	}
	if (node)
		return (FAILURE);
	if ((*two)->a->index == size - 1 || (*two)->a->index == size - 2)
		while ((*two)->a->index != 0)
			ra(two);
	else
		while ((*two)->a->index != 0)
			rra(two);
	return (SUCCESS);
}

void	push_swap_five(t_two **two, int size)
{
	if (!roop_check(two, size))
		return ;
	while ((*two)->a->index != 0 && (*two)->a->index != 1)
		ra(two);
	pb(two);
	while ((*two)->a->index != 0 && (*two)->a->index != 1)
		ra(two);
	pb(two);
	if (!((*two)->a->next->next) && ((*two)->a->index == 3))
	{
		if ((*two)->b->index == 0)
			ss(two);
		else
			sa(two);
	}
	else if ((*two)->a->next->next)
		push_swap_three(two, 4);
	if ((*two)->b->index == 0)
		sb(two);
	pa(two);
	pa(two);
}
