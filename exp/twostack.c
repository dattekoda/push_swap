#include "stack.h"

t_two	*init_two(void)
{
	t_two	*two;

	two = (t_two *)malloc(sizeof(t_two));
	if (!two)
		return (NULL);
	two->a = NULL;
	two->b = NULL;
	return (two);
}

void	free_two(t_two **two)
{
	free_stack(&((*two)->a));
	free_stack(&((*two)->b));
	free(*two);
}

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

void	sa(t_two **two)
{
	write(1, "sa\n", 3);
	swap_stack(&((*two)->a));
}

void	sb(t_two **two)
{
	write(1, "sb\n", 3);
	swap_stack(&((*two)->b));
}

void	ss(t_two **two)
{
	write(1, "ss\n", 3);
	sa(two);
	sb(two);
}

void	ra(t_two **two)
{
	write(1, "ra\n", 3);
	rotate_stack(&((*two)->a));
}

void	rb(t_two **two)
{
	write(1, "rb\n", 3);
	rotate_stack(&((*two)->b));
}

void	rr(t_two **two)
{
	write(1, "rr\n", 3);
	rotate_stack(&((*two)->a));
	rotate_stack(&((*two)->b));
}

void	rra(t_two **two)
{
	write(1, "rra\n", 4);
	rev_rotate_stack(&((*two)->a));
}

void	rrb(t_two **two)
{
	write(1, "rrb\n", 4);
	rev_rotate_stack(&((*two)->b));
}

void	rrr(t_two **two)
{
	write(1, "rrr\n", 4);
	rev_rotate_stack(&((*two)->a));
	rev_rotate_stack(&((*two)->b));
}
