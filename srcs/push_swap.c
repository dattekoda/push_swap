/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:05:36 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/20 00:43:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	print_val(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_idx(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->index);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_two(t_two *two)
{
	printf("A: ");
	print_val(two->a);
	printf("A: ");
	print_idx(two->a);
	printf("B: ");
	print_val(two->b);
	printf("B: ");
	print_idx(two->b);
}

void	push_swap(t_two **two, int size)
{
	if (size == 3)
		push_swap_three(two, 2);
	else if (size == 5 || size == 4)
		push_swap_five(two, size);
}

int	main(int argc, char *argv[])
{
	t_two	*two;

	two = parse_num_to_two(argc, argv);
	if (!two)
		err();
	print_two(two);
	push_swap(&two, argc - 1);
	print_two(two);
	free_two(&two);
	return (0);
}
