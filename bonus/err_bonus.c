/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:04:44 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/22 04:08:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	err(void)
{
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		err();
// 	return (0);
// }
