#include "stack.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int		i = 0;

	if (argc == 1)
		return (1);
	a = init_stack(argc - 1);
	if (!a)
		return (1);
	b = init_stack(argc - 1);
	if (!b)
		return (1);
	while (++i < argc)
		push(a, atoi(argv[i]));
	rotate(a);
	print_stack(a);
	return (0);
}