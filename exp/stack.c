#include "stack.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!stack->array)
		return (free(stack), NULL);
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->array);
		free(stack);
	}
}

int	push(t_stack *stack, int value)
{
	if (stack->size >= stack->capacity)
		return (-1);
	stack->array[stack->size] = value;
	stack->size++;
	return (0);
}

int	pop(t_stack *stack, int *value)
{
	if (stack->size <= 0)
		return (-1);
	stack->size--;
	*value = stack->array[stack->size];
	return (0);
}

int	swap(t_stack *stack)
{
	int	tmp;
	int	size;

	size = stack->size;
	if (size <= 1)
		return (-1);
	tmp = stack->array[size - 1];
	stack->array[size - 1] = stack->array[size - 2];
	stack->array[size - 2] = tmp;
	return (0);
}

int	rotate(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack->size - 1;
	if (size <= 0)
		return (-1);
	i = -1;
	while (2 * (++i) < size)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[size - i];
		stack->array[size - i] = tmp;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = stack->size;
	while (--i >= 0)
		printf("%d: %d\n", i, stack->array[i]);
	printf("-----------\n\n");
}