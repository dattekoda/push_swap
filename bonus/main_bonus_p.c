/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:14:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/22 04:08:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include <stdio.h>

static void	print_val(t_stack *stack);
static void	print_idx(t_stack *stack);
static void	print_two(t_two *two);

static int	check_sorted(t_stack *a)
{
	int	val;

	while (a && a->next)
	{
		val = a->value;
		if (a->next->value < val)
			return (FAILURE);
		a = a->next;
	}
	return (SUCCESS);
}

static int	commandable(char *line, t_two **two)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (sa(two), SUCCESS);
	else if (!ft_strncmp(line, "sb\n", 3))
		return (sb(two), SUCCESS);
	else if (!ft_strncmp(line, "ss\n", 3))
		return (ss(two), SUCCESS);
	else if (!ft_strncmp(line, "pa\n", 3))
		return (pa(two), SUCCESS);
	else if (!ft_strncmp(line, "pb\n", 3))
		return (pb(two), SUCCESS);
	else if (!ft_strncmp(line, "ra\n", 3))
		return (ra(two), SUCCESS);
	else if (!ft_strncmp(line, "rb\n", 3))
		return (rb(two), SUCCESS);
	else if (!ft_strncmp(line, "rr\n", 3))
		return (rr(two), SUCCESS);
	else if (!ft_strncmp(line, "rra\n", 4))
		return (rra(two), SUCCESS);
	else if (!ft_strncmp(line, "rrb\n", 4))
		return (rrb(two), SUCCESS);
	else if (!ft_strncmp(line, "rrr\n", 4))
		return (rrr(two), SUCCESS);
	return (FAILURE);
}

static int	do_command(char *line, t_two **two)
{
	if (!commandable(line, two))
		return (SUCCESS);
	else if (*line == '\n')
		return (SUCCESS);
	return (FAILURE);
}

static int	get_command(t_two **two)
{
	char	*line;
	char	c;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (do_command(line, two))
			return (free(line), FAILURE);
		c = *line;
		free(line);
		if (c == '\n')
			break ;
		print_two(*two);
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_two	*two;

	if (argc == 1)
		err();
	two = parse_num_to_two(argc, argv);
	if (!two)
		err();
	print_two(two);
	if (get_command(&two))
	{
		free_two(&two);
		err();
	}
	if (!two->b && !check_sorted(two->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_two(&two), 0);
}

static void	print_val(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_idx(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ", stack->index);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_two(t_two *two)
{
	printf("A: ");
	print_val(two->a);
	printf("A: ");
	print_idx(two->a);
	printf("B: ");
	print_val(two->b);
	printf("B: ");
	print_idx(two->b);
}
