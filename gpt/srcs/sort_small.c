/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:46:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:46:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->value;
	y = a->top->next->value;
	z = a->top->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
	{
		while (a->size > 3)
			pb(a, b);
		sort_three(a);
		while (b->size)
			pa(a, b);
	}
}
