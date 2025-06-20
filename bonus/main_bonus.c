/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:14:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/21 04:40:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static int	do_command(char *line, t_two **two)
{
	if (ft_strncmp(line, "sa\n", 4))
		sa(two);
	else if (ft_strncmp(line, "sb\n", 4))
		sb(two);
	else if (ft_strncmp(line, "ss\n", 4))
		ss(two);
	else if (ft_strncmp(line, "ra\n", 4))
		ra(two);
	else if (ft_strncmp(line, "rb\n", 4))
		rb(two);
	else if (ft_strncmp(line, "rr\n", 4))
		rr(two);
	else if (ft_strncmp(line, "rra\n", 5))
		rra(two);
	else if (ft_strncmp(line, "rrb\n", 5))
		rrb(two);
	else if (ft_strncmp(line, "rrr\n", 5))
		rrr(two);
	else
		return (FAILURE);
	return (SUCCESS);
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
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_two	*two;

	two = parse_num_to_two(argc, argv);
	if (!two)
		err();
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
