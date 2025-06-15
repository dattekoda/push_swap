/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:49:16 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/15 20:01:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static int	check_dup(int before[], int after[], int length)
{
	int	i;
	int	j;

	i = length;
	ft_memmove(after, before, sizeof(int) * length);
	ft_qsort(after, 0, length - 1);
	while (--i)
		if (after[i] == after[i - 1])
			return (1);
	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length)
			if (before[i] == after[j])
				after[i] = j;
	}
	return (0);
}

int	*char_to_int(int argc, char *argv[])
{
	int *res;

	res = malloc(sizeof(int) * argc);
	if (!res)
		return (NULL);
	while(argc--)
		res[argc] = atoi(argv[argc + 1]);
	return (res);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i = -1;

	argc--;
	b = char_to_int(argc, argv);
	if (!b)
		err();
	a = malloc(sizeof(int) * argc);
	if (!a)
	{
		free(b);
		err();
	}
	if (check_dup(b, a, argc) == 1)
	{
		free(a);
		free(b);
		err();
	}
	while (++i < argc)
		printf("%d ", b[i]);
	printf("\n");
	i = -1;
	while(++i < argc)
		printf("%d ", a[i]);
}