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
# include <stdbool.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../printf/includes/ft_printf.h"

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
}	t_stack;

typedef struct s_two
{
	t_stack *a;
	t_stack *b;
}	t_two;

void	free_stack(t_stack **head);
void	push_stack(t_stack **head, t_stack *node);
t_stack	*pop_stack(t_stack **head);
void	swap_stack(t_stack **head);
void	rotate_stack(t_stack **head);
void	rev_rotate_stack(t_stack **head);

t_two	*init_two(void);
void	free_two(t_two **two);
void	pa(t_two **two);
void	pb(t_two **two);
void	sa(t_two **two);
void	sb(t_two **two);
void	ss(t_two **two);
void	ra(t_two **two);
void	rb(t_two **two);
void	rr(t_two **two);
void	rra(t_two **two);
void	rrb(t_two **two);
void	rrr(t_two **two);

void	ft_qsort(int arr[], int low, int high);
void	push_swap(t_two **two);
t_two	*parse_num_to_two(int argc, char *argv[]);

void	err(void);

#endif