/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:12:20 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:37:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_handle.h"
#include "../includes/libft.h"

int	count_digit_p(uintptr_t n, unsigned int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	count_digit_u(unsigned int n, unsigned int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	count_digit(long n, unsigned int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

void	count_flen_u(unsigned long n, t_fmt *f, unsigned int base)
{
	int	c;

	if (f->spec == 'p')
		c = count_digit_p(n, 16);
	else
		c = count_digit_u(n, base);
	if (c < f->prec)
		f->len = f->prec;
	else if (c < f->width && f->flags & FLAG_ZERO && !(f->flags & FLAG_DOT))
		f->len = f->width;
	else if (n == 0 && f->flags & FLAG_DOT && f->prec == 0)
		f->len = 0;
	else
		f->len = c;
	if (f->flags & FLAG_HASH && n != 0 && f->spec != 'u')
		f->len += 2;
}

void	count_flen(long n, t_fmt *f)
{
	int	c;

	c = count_digit(n, 10);
	if (c < f->prec)
		f->len = f->prec + ((f->flags & FLAG_PLUS) || n < 0);
	else if (c < f->width && f->flags & FLAG_ZERO && !(f->flags & FLAG_DOT))
		f->len = f->width;
	else if (n == 0 && f->flags & FLAG_DOT && f->prec == 0)
		f->len = ((f->flags & FLAG_PLUS) || n < 0);
	else
		f->len = c + ((f->flags & FLAG_PLUS) || n < 0);
}
