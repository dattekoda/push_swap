#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*array;
	int size;
	int capacity;
}	t_stack;

t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		push(t_stack *stack, int value);
int		pop(t_stack *stack, int *value);
int		swap(t_stack *stack);
int		rotate(t_stack *stack);
void	print_stack(t_stack *stack);

#endif