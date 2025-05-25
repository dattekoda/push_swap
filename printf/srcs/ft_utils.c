/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:17:40 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:39:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_handle.h"
#include "../includes/libft.h"

ssize_t	ft_putnchar(char c, int n, int *len)
{
	ssize_t	ret;

	ret = 0;
	if (n == 0)
		return (0);
	while (n--)
	{
		ret = write(1, &c, 1);
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	return (0);
}

ssize_t	ft_putstr_len(const char *s, int *len)
{
	ssize_t	ret;

	ret = 0;
	while (*s)
	{
		ret = write(1, s++, 1);
		if (ret == -1)
			return (-1);
		*len += ret;
	}
	return (0);
}

void	ft_utoa_base(unsigned long n, t_fmt *f, unsigned int base, char *num)
{
	char			base_set[18];
	int				i;
	unsigned long	_n;

	ft_strlcpy(base_set, "0123456789abcdefx", 18);
	if (f->spec == 'X')
		ft_strlcpy(base_set + 10, "ABCDEFX", 8);
	i = f->len;
	_n = n;
	if (n == 0 && f->prec != 0)
		num[--i] = '0';
	while (n > 0)
	{
		num[--i] = base_set[n % base];
		n /= base;
	}
	if ((f->flags & FLAG_HASH && _n != 0 && (f->spec != 'x' || f->spec != 'X'))
		|| f->spec == 'p')
		num[--i] = base_set[16];
	while (0 < i)
		num[--i] = '0';
}

void	ft_sitoa(long n, t_fmt *f, char *num)
{
	int		i;
	long	_n;

	_n = n;
	i = f->len;
	if (n == 0)
		num[--i] = '0';
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		num[--i] = ('0' + n % 10);
		n /= 10;
	}
	while (0 < i)
		num[--i] = '0';
	if (_n < 0)
		num[i] = '-';
	else if (f->flags & FLAG_PLUS)
		num[i] = '+';
}
