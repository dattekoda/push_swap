/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-25 12:05:36 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-25 12:05:36 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_two(t_two *two)
{
	printf("A: ");
	print_stack(two->a);
	printf("B: ");
	print_stack(two->b);
}

void	push_swap(t_two **two)
{
}

int	main(int argc, char *argv[])
{
	t_two	*two;

	two = parse_num_to_two(argc, argv);
	print_two(two);
	push_swap(&two);
	return (0);
}
