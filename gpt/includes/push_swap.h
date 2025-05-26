/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:43:33 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:52:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ------------------------------- structs ---------------------------------- */
typedef struct s_node
{
	int			value;
	int			index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* -------------------------- parsing & utils -------------------------------- */
int			ps_error(void);
int			ps_atoi(const char *str, int *dest);
int			parse_input(int argc, char **argv, t_stack *a);
int			is_sorted(t_stack *a);
void		index_stack(t_stack *a);

/* --------------------------- stack helpers --------------------------------- */
t_stack		*stack_new(void);
void		stack_push(t_stack *stack, t_node *node);
t_node		*stack_pop(t_stack *stack);
void		stack_clear(t_stack *stack);

/* ---------------------------- operations ----------------------------------- */
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/* ---------------------------- sorting -------------------------------------- */
void		sort_small(t_stack *a, t_stack *b);
void		sort_big(t_stack *a, t_stack *b);

#endif