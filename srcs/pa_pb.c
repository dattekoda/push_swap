/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:08:58 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:05:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_two **two)
{
	write(1, "pa\n", 3);
	if ((*two)->b)
		push_stack(&((*two)->a), pop_stack(&((*two)->b)));
}

void	pb(t_two **two)
{
	write(1, "pb\n", 3);
	if ((*two)->a)
		push_stack(&((*two)->b), pop_stack(&((*two)->a)));
}
