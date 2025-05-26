/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:45:10 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:45:10 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print(const char *op)
{
	write(1, op, 3);
	write(1, "\n", 1);
}

void	sa(t_stack *a)
{
	t_node *first;
	t_node *second;

	if (a->size < 2)
		return ;
	first = stack_pop(a);
	second = stack_pop(a);
	stack_push(a, first);
	stack_push(a, second);
	print("sa");
}

void	sb(t_stack *b)
{
	sa(b);
	write(1, "\b\bsb\n", 5);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
	write(1, "\b\bss\n", 5);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node *node;

	node = stack_pop(b);
	if (!node)
		return ;
	stack_push(a, node);
	print("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node *node;

	node = stack_pop(a);
	if (!node)
		return ;
	stack_push(b, node);
	print("pb");
}

static void	rotate(t_stack *s)
{
	t_node *first;
	t_node *last;

	if (s->size < 2)
		return ;
	first = stack_pop(s);
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	s->size++;
	s->size--; /* keep size unchanged */
}

static void	rev_rotate(t_stack *s)
{
	t_node *prev;
	t_node *last;

	if (s->size < 2)
		return ;
	prev = NULL;
	last = s->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	stack_push(s, last);
	s->size--;
	/* size restored by stack_push */
}

void	ra(t_stack *a)
{
	rotate(a);
	print("ra");
}

void	rb(t_stack *b)
{
	ra(b);
	write(1, "\b\brb\n", 5);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
	write(1, "\b\brr\n", 5);
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	print("rra");
}

void	rrb(t_stack *b)
{
	rra(b);
	write(1, "\b\brrb\n", 6);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rra(b);
	write(1, "\b\brrr\n", 6);
}
