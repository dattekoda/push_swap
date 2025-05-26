/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:29:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Helper for qsort comparison
static int	compare_ints(const void *a, const void *b)
{
	int	int_a;
	int	int_b;

	int_a = *((int *)a);
	int_b = *((int *)b);
	if (int_a < int_b)
		return (-1);
	if (int_a > int_b)
		return (1);
	return (0);
}

// Creates a sorted array of the values in stack_a
static int	*get_sorted_array(t_node *stack, int size, t_stacks *stacks_ptr)
{
	int		*arr;
	t_node	*current;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit_error(stacks_ptr);
	current = stack;
	i = 0;
	while (current && i < size)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	qsort(arr, size, sizeof(int), compare_ints); // Using qsort from stdlib
	return (arr);
}

// Assigns a normalized index (0 to N-1) to each node in stack_a
void	assign_indexes(t_stacks *stacks)
{
	int		*sorted_arr;
	t_node	*current_node;
	int		i;
	int		size;

	if (!stacks || !stacks->a)
		return ;
	size = stacks->size_a;
	sorted_arr = get_sorted_array(stacks->a, size, stacks);
	current_node = stacks->a;
	while (current_node)
	{
		i = 0;
		while (i < size)
		{
			if (current_node->value == sorted_arr[i])
			{
				current_node->index = i;
				break ;
			}
			i++;
		}
		current_node = current_node->next;
	}
	free(sorted_arr);
}
