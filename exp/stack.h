#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}	t_stack;

typedef struct s_two
{
	t_stack *a;
	t_stack *b;
}	t_two;

void	free_stack(t_stack **head);
void	push_stack(t_stack **head, int val);
int		pop_stack(t_stack **head);
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

#endif