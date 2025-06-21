/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:15:56 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/21 21:30:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_two	*two;

	if (argc == 1)
		err();
	two = parse_num_to_two(argc, argv);
	if (!two)
		err();
	push_swap(&two, argc - 1);
	free_two(&two);
	return (0);
}

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

// int	main(int argc, char *argv[])
// {
// 	t_two	*two;

// 	two = parse_num_to_two(argc, argv);
// 	if (!two)
// 		err();
// 	print_two(two);
// 	push_swap(&two, argc - 1);
// 	print_two(two);
// 	free_two(&two);
// 	return (0);
// }