/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:12:23 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	pa(t_two **two)
{
	if ((*two)->b)
		push_stack(&((*two)->a), pop_stack(&((*two)->b)));
}

void	pb(t_two **two)
{
	if ((*two)->a)
		push_stack(&((*two)->b), pop_stack(&((*two)->a)));
}
