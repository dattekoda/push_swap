/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:28:06 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:37:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_handle.h"
#include "../includes/libft.h"

int	handle_char(char c, const t_fmt *f)
{
	int	len;
	int	ret;

	len = 0;
	ret = 0;
	if (f->width > 1 && !(f->flags & FLAG_MINUS))
		ret = (int)ft_putnchar(' ', f->width - 1, &len);
	if (ret == -1)
		return (-1);
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	len += ret;
	if (f->width > 1 && f->flags & FLAG_MINUS)
		ret = (int)ft_putnchar(' ', f->width - 1, &len);
	if (ret == -1)
		return (-1);
	return (len);
}

int	handle_str(char *s, const t_fmt *f)
{
	int		len;
	int		slen;
	ssize_t	ret;

	ret = 0;
	if (!s)
		return (handle_null(f));
	len = 0;
	slen = (int)ft_strlen(s);
	if (f->flags & FLAG_DOT && f->prec < slen)
		slen = f->prec;
	if (f->width > slen && !(f->flags & FLAG_MINUS))
		ret = (int)ft_putnchar(' ', f->width - slen, &len);
	if (ret == -1)
		return (-1);
	ret = write(1, s, slen);
	if (ret == -1)
		return (-1);
	len += ret;
	if (f->width > slen && f->flags & FLAG_MINUS)
		ret = (int)ft_putnchar (' ', f->width - slen, &len);
	if (ret == -1)
		return (-1);
	return (len);
}

int	handle_null(const t_fmt *f)
{
	int		len;
	ssize_t	ret;

	len = 0;
	ret = 0;
	if (6 <= f->prec || !(f->flags & FLAG_DOT))
	{
		if (6 <= f->width && !(f->flags & FLAG_MINUS))
			ret = (int)ft_putnchar(' ', f->width - 6, &len);
		if (ret == -1)
			return (-1);
		ret = write(1, "(null)", 6);
		len += ret;
		if (ret == -1)
			return (-1);
		if (6 <= f->width && f->flags & FLAG_MINUS)
			ret = (int)ft_putnchar(' ', f->width - 6, &len);
	}
	else
		ret = (int)ft_putnchar(' ', f->width, &len);
	if (ret == -1)
		return (-1);
	return (len);
}

int	handle_uint(unsigned long n, t_fmt *f, unsigned int base)
{
	char	*num;
	int		len;
	ssize_t	ret;

	num = ready_uint(n, f, base);
	len = 0;
	ret = 0;
	if (!num)
		return (-1);
	if (f->flags & FLAG_MINUS)
		ret = output_left(num, f, &len);
	else
		ret = output_right(num, f, &len);
	if (ret == -1)
		return (free(num), -1);
	return (free(num), len);
}

int	handle_sint(long n, t_fmt *f)
{
	char	*num;
	int		len;
	ssize_t	ret;

	num = ready_sint(n, f);
	len = 0;
	ret = 0;
	if (!num)
		return (-1);
	if (f->flags & FLAG_MINUS)
		ret = output_left(num, f, &len);
	else
		ret = output_right(num, f, &len);
	if (ret == -1)
		return (free(num), -1);
	return (free(num), len);
}
