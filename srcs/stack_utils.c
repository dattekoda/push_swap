#include "../includes/push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}
}

int	push_stack(t_stack **head, int val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (1);
	node->value = val;
	node->next = *head;
	*head = node;
	return (0);
}

int	pop_stack(t_stack **head)
{
	int		pop;
	t_stack	*node;

	if (!*head)
		return (0);
	node = *head;
	pop = node->value;
	*head = node->next;
	free(node);
	return (pop);
}

void	swap_stack(t_stack **head)
{
	t_stack	*first;
	t_stack *second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	pa(t_two **two)
{
	write(1, "pa\n", 3);
	if ((*two)->b)
		push_stack(&((*two)->a), pop_stack(&((*two)->b)));
}
