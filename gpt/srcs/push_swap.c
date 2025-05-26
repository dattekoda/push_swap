/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:47:05 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:47:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_and_parse(int argc, char **argv, t_stack **a)
{
	*a = stack_new();
	if (!*a)
		return (ps_error());
	if (parse_input(argc, argv, *a))
	{
		stack_clear(*a);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (init_and_parse(argc, argv, &a))
		return (1);
	if (is_sorted(a))
	{
		stack_clear(a);
		return (0);
	}
	b = stack_new();
	if (!b)
	{
		stack_clear(a);
		return (ps_error());
	}
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
	stack_clear(a);
	stack_clear(b);
	return (0);
}
