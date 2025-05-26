#include "stack.h"

t_stack	*init_stack(void)
{
	return (NULL);
}

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

void	push_stack(t_stack **head, int val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = val;
	node->next = *head;
	*head = node;
}

int	pop_stack(t_stack **head)
{
	int	pop;
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

void	rotate_stack(t_stack **head)
{
	t_stack	*first;
	t_stack *tail;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	first->next = NULL;
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = first;
}

void	rev_rotate_stack(t_stack **head)
{
	t_stack	*prev;
	t_stack	*tail;

	if (!*head || !(*head)->next)
		return ;
	prev = NULL;
	tail = *head;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->next = *head;
	*head = tail;
}