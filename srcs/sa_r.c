#include "../includes/push_swap.h"

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
