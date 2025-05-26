/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:15:15 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:16:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack_nodes(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	free_stacks_and_exit(t_stacks *stacks, int exit_code)
{
	if (stacks)
	{
		free_stack_nodes(&(stacks->a));
		free_stack_nodes(&(stacks->b));
	}
	exit(exit_code);
}

void	exit_error(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks_and_exit(stacks, 1);
}
