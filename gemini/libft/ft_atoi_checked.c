/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_checked.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 14:52:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

long	ft_atoi_checked(const char *str, int *error_flag)
{
	long	result;
	int		sign;
	int		digits_found;

	result = 0;
	sign = 1;
	digits_found = 0;
	*error_flag = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		digits_found = 1;
		if (sign == 1 && (result > (LONG_MAX - (*str - '0')) / 10))
			*error_flag = 1;
		if (sign == -1 && (-result < (LONG_MIN + (*str - '0')) / 10))
			*error_flag = 1;
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' || !digits_found) // Check for trailing non-digits or no digits
		*error_flag = 1;
	result *= sign;
	if ((result > INT_MAX || result < INT_MIN) && !*error_flag) // Check final int range
	    *error_flag = 1;
	return (result);
}