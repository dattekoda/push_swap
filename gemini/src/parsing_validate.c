/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:25:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	validate_duplicates(t_stacks *stacks)
{
	t_node	*current;
	t_node	*runner;

	if (!stacks || !stacks->a)
		return ;
	current = stacks->a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				exit_error(stacks);
			runner = runner->next;
		}
		current = current->next;
	}
}
