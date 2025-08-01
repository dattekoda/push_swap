/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:04:57 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:06:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_two **two)
{
	write(1, "sa\n", 3);
	swap_stack(&((*two)->a));
}

void	sb(t_two **two)
{
	write(1, "sb\n", 3);
	swap_stack(&((*two)->b));
}

void	ss(t_two **two)
{
	write(1, "ss\n", 3);
	swap_stack(&((*two)->a));
	swap_stack(&((*two)->b));
}

void	ra(t_two **two)
{
	write(1, "ra\n", 3);
	rotate_stack(&((*two)->a));
}

void	rb(t_two **two)
{
	write(1, "rb\n", 3);
	rotate_stack(&((*two)->b));
}
