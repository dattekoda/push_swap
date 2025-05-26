#include "stack.h"

int	push_a(t_stack *a, t_stack *b)
{
	
}

int	push_a(t_stack *a, t_stack *b)
{
	int	tmp;
	if (a->size <= 0)
		return (1);
	pop(a, &tmp);
	push(b, tmp);
	return (0);
}