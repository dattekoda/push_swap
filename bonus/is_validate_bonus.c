/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:11:28 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:07:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	ft_isint(const char *s)
{
	long	num;
	int		minus;

	num = 0;
	minus = 1;
	if (!*s || !s)
		return (FAILURE);
	while (*s && (*s == ' ' || ('\t' <= *s && *s <= '\r')))
		s++;
	if (*s && (*s == '-' || *s == '+'))
		minus = 1 - 2 * (*s++ == '-');
	if (!*s)
		return (FAILURE);
	while (*s && ('0' <= *s && *s <= '9'))
		num = num * 10 + (*s++ - '0');
	num *= minus;
	if (num < INT_MIN || INT_MAX < num)
		return (FAILURE);
	return (*s);
}

static int	is_unique(int argc, char *argv[], int *array)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		j = i;
		while (++j < argc)
			if (array[i - 1] == ft_atoi(argv[j]))
				return (FAILURE);
	}
	return (SUCCESS);
}

int	is_validate(int argc, char *argv[], int	*array)
{
	int	_argc;

	_argc = argc;
	while ((_argc-- - 1))
		if (ft_isint(argv[_argc]))
			return (FAILURE);
	if (is_unique(argc, argv, array))
		return (FAILURE);
	return (SUCCESS);
}

// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	int	*array;
// 	int	i;

// 	i = -1;
// 	if (argc == 1)
// 		return (1);
// 	array = malloc(sizeof(int) * (argc - 1));
// 	// printf("%d\n", is_unique(argc, argv));
// 	// printf("%d\n", ft_isint("821"));
// 	printf("%d\n", is_validate(argc, argv, array));
// 	while (++i < argc - 1)
// 		printf("%d ", array[i]);
// 	return (free(array), printf("\n"), 0);
// }