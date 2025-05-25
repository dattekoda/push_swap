#include "stack.h"

int	main(void)
{
	t_stack	*a;
	int		value;

	a = init_stack(10);
	if (!a)
		return (1);
	
	push(a, 3);
	push(a, 7);
	push(a, 1);

	printf("Stack A:\n");
	print_stack(a);

	pop(a, &value);
	printf("Popped value: %d\n", value);

	printf("Stack A after pop:\n");
	print_stack(a);

	push(a, -4);
	printf("Stack A after push:\n");
	print_stack(a);

	push(a, value);
	printf("Stack A after push value %d:\n", value);
	print_stack(a);

	swap(a);
	printf("Stack A after swap:\n");
	print_stack(a);

	rotate(a);
	printf("Stack A after rotate:\n");
	print_stack(a);

	free_stack(a);
	return (0);
}