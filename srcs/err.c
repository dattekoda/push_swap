/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:04:44 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:06:34 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	err(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		err();
// 	return (0);
// }
