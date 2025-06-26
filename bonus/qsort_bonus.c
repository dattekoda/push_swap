/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:04:51 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static	void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	return (i);
}

void	ft_qsort(int arr[], int low, int high)
{
	int	idx;

	idx = partition(arr, low, high);
	if (low < idx - 1)
		ft_qsort(arr, low, idx - 1);
	if (idx < high)
		ft_qsort(arr, idx, high);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	data[] = {4, 2, 1, 10, 5 ,7, 8, 3, 0};
// 	int	size = sizeof(data) / sizeof(data[0]);

// 	ft_qsort(data, 0, size - 1);

// 	int	i = -1;
// 	while (++i < size)
// 		printf("%d ", data[i]);
// 	printf("\n");
// 	return (0);
// }