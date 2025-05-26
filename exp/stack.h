#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}	t_stack;

t_stack	*init_stack(void);
void	free_stack(t_stack **head);
void	push_stack(t_stack **head, int val);
int		pop_stack(t_stack **head);
void	swap_stack(t_stack **head);
void	rotate_stack(t_stack **head);
void	rev_rotate_stack(t_stack **head);

#endif