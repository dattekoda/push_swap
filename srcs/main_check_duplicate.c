#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static int	check_duplicate(int arr[], int length)
{
	int	before[length];
	int	after[length];
	int	i;
	int	j;

	i = length;
	ft_memmove(before, arr, sizeof(int) * length);
	ft_qsort(arr, 0, length - 1);
	ft_memmove(after, arr, sizeof(int) * length);
	while (--i)
		if (arr[i] == arr[i - 1])
			return (1);
	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length)
			if (before[i] == after[j])
				arr[i] = j;
	}
	return (0);
}

int	main(void)
{
	int a[10] = {7, 9, 1, 3, 4, 8, 6};
	int len = 7;
	int	i = -1;

	while (++i < len)
		printf("%d ", a[i]);
	printf("\n");
	check_duplicate(a, len);
	i = -1;
	while(++i < len)
		printf("%d ", a[i]);
}