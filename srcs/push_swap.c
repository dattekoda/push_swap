/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-25 12:05:36 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-25 12:05:36 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(int argc, char *argv[])
{
	int	i = -1;
	int	num;
	t_list	a;
	t_list	b;
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_printf("%d\n", num);
	}
}

int	main(int argc, char *argv[])
{
	push_swap(--argc, argv + 1);
	return (0);
}
