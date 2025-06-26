/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:04:55 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:06:14 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_two **two)
{
	write(1, "rr\n", 3);
	rotate_stack(&((*two)->a));
	rotate_stack(&((*two)->b));
}

void	rra(t_two **two)
{
	write(1, "rra\n", 4);
	rev_rotate_stack(&((*two)->a));
}

void	rrb(t_two **two)
{
	write(1, "rrb\n", 4);
	rev_rotate_stack(&((*two)->b));
}

void	rrr(t_two **two)
{
	write(1, "rrr\n", 4);
	rev_rotate_stack(&((*two)->a));
	rev_rotate_stack(&((*two)->b));
}
