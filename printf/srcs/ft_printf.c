/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:29:16 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:37:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int	i;
	unsigned int	total;
	va_list			ap;
	t_fmt			f;
	int				tmp;

	if (fmt == NULL)
		return (-1);
	i = -1;
	total = 0;
	va_start(ap, fmt);
	while (fmt && fmt[++i])
	{
		if (fmt[i] == '%')
			tmp = ft_vprintf(fmt, &ap, &i, &f);
		else
			tmp = write(1, &fmt[i], 1);
		if (tmp == -1)
			return (va_end(ap), -1);
		total += tmp;
	}
	va_end(ap);
	return (total);
}

int	ft_vprintf(const char *fmt, va_list *ap, unsigned int *i, t_fmt *f)
{
	(*i)++;
	f_init(f);
	f_parse_flags(fmt, i, f);
	f_parse_width_prec(fmt, i, f);
	f->spec = fmt[(*i)];
	return (dispatch(f, ap));
}
