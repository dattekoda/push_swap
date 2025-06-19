/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:14:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/20 03:43:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sorted(t_stack *a)
{
	int	val;

	while (a && a->next)
	{
		val = a->value;
		if (a->next->value < val)
			return (FAILURE);
		a = a->next;
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_two	*two;

	two = parse_num_to_two(argc, argv);
	if (!two)
		err();
	push_swap(&two, argc - 1);
	if (!two->b && !check_sorted(two->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_two(&two), 0);
}
