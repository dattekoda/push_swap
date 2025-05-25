/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:29:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:37:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fmt.h"
#include "../includes/ft_handle.h"
#include "../includes/libft.h"

static	int	atoi_move(const char *s, unsigned int *i)
{
	int	num;

	num = 0;
	while (s[*i] && ('0' <= s[*i] && s[*i] <= '9'))
		num = num * 10 + (s[(*i)++] - '0');
	return (num);
}

void	f_init(t_fmt	*f)
{
	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	f->spec = '\0';
	f->len = 0;
}

void	f_parse_flags(const char *fmt, unsigned int *i, t_fmt *f)
{
	while (ft_strchr("0-+ #", fmt[*i]))
	{
		if (fmt[*i] == '0')
			f->flags |= FLAG_ZERO;
		else if (fmt[*i] == '-')
			f->flags |= FLAG_MINUS;
		else if (fmt[*i] == '+')
			f->flags |= FLAG_PLUS;
		else if (fmt[*i] == ' ')
			f->flags |= FLAG_SPACE;
		else if (fmt[*i] == '#')
			f->flags |= FLAG_HASH;
		(*i)++;
	}
	if (f->flags & FLAG_MINUS && f->flags & FLAG_ZERO)
		f->flags ^= FLAG_ZERO;
}

void	f_parse_width_prec(const char *fmt, unsigned int *i, t_fmt *f)
{
	f->width = atoi_move(fmt, i);
	if (fmt[*i] == '.')
	{
		(*i)++;
		f->flags |= FLAG_DOT;
		f->prec = atoi_move(fmt, i);
	}
}

int	dispatch(t_fmt *f, va_list *ap)
{
	if (f->spec == 'c')
		return (handle_char((char)va_arg(*ap, int), f));
	if (f->spec == 's')
		return (handle_str(va_arg(*ap, char *), f));
	if (f->spec == 'p')
		return (f->flags |= FLAG_HASH
			, (handle_uint((unsigned long)va_arg(*ap, void *), f, 16)));
	if (f->spec == 'd' || f->spec == 'i')
		return (handle_sint((long)va_arg(*ap, int), f));
	if (f->spec == 'u')
		return (handle_uint((unsigned long)va_arg(*ap, unsigned int), f, 10));
	if (f->spec == 'x')
		return (handle_uint((unsigned int)va_arg(*ap, unsigned int), f, 16));
	if (f->spec == 'X')
		return (handle_uint((unsigned int)va_arg(*ap, unsigned int), f, 16));
	if (f->spec == '%')
		return (write(1, "%", 1));
	return (0);
}
