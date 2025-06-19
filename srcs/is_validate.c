/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:11:28 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/19 23:37:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isnumber(const char *s)
{
	if (!*s || !s)
		return (FAILURE);
	while (*s && (*s == ' ' || ('\t' <= *s && *s <= '\r')))
		s++;
	if (*s && (*s == '-' || *s == '+'))
		s++;
	if (!*s)
		return (FAILURE);
	while (*s && ('0' <= *s && *s <= '9'))
		s++;
	return (*s);
}

static int	is_unique(int argc, char *argv[], int *array)
{	//check if it is unique and store the element in the array.
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
		if (ft_isnumber(argv[_argc]))
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
// 	// printf("%d\n", ft_isnumber("821"));
// 	printf("%d\n", is_validate(argc, argv, array));
// 	while (++i < argc - 1)
// 		printf("%d ", array[i]);
// 	return (free(array), printf("\n"), 0);
// }