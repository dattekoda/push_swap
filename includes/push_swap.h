/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-24 14:44:48 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-24 14:44:48 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../printf/includes/ft_printf.h"

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}		t_stack;

void	push_swap(int argc, char *argv[]);

#endif