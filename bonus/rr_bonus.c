/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:33:26 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	rr(t_two **two)
{
	rotate_stack(&((*two)->a));
	rotate_stack(&((*two)->b));
}

void	rra(t_two **two)
{
	rev_rotate_stack(&((*two)->a));
}

void	rrb(t_two **two)
{
	rev_rotate_stack(&((*two)->b));
}

void	rrr(t_two **two)
{
	rev_rotate_stack(&((*two)->a));
	rev_rotate_stack(&((*two)->b));
}
