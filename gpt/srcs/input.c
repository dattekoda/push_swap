/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:44:11 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:52:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	detect_duplicate(t_stack *a, int nb)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ps_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ps_atoi(const char *str, int *dest)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
			return (0);
	}
	if (*str)
		return (0);
	*dest = (int)(res * sign);
	return (1);
}

static t_node	*create_node(int value)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int		 i;
	int		 nb;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		if (!ps_atoi(argv[i], &nb))
			return (ps_error());
		if (detect_duplicate(a, nb))
			return (ps_error());
		node = create_node(nb);
		if (!node)
			return (ps_error());
		stack_push(a, node);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	if (!a || a->size < 2)
		return (1);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
