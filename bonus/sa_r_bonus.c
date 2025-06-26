/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_r_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:32:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sa(t_two **two)
{
	swap_stack(&((*two)->a));
}

void	sb(t_two **two)
{
	swap_stack(&((*two)->b));
}

void	ss(t_two **two)
{
	sa(two);
	sb(two);
}

void	ra(t_two **two)
{
	rotate_stack(&((*two)->a));
}

void	rb(t_two **two)
{
	rotate_stack(&((*two)->b));
}
