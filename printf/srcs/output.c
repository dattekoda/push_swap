/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:27:54 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:38:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fmt.h"
#include "../includes/ft_handle.h"
#include "../includes/libft.h"

ssize_t	output_left(char *s, const t_fmt *f, int *len)
{
	ssize_t	ret;
	bool	space;

	ret = 0;
	space = (s[0] != '-' && s[0] != '+' && f->flags & FLAG_SPACE
			&& (f->spec == 'i' || f->spec == 'd'));
	if (space)
		ret = ft_putnchar(' ', 1, len);
	if (ret == -1)
		return (-1);
	ret = ft_putstr_len(s, len);
	if (ret == -1)
		return (-1);
	if (f->width > f->len + space)
		ret = ft_putnchar(' ', f->width - f->len - space, len);
	if (ret == -1)
		return (-1);
	return (0);
}

ssize_t	output_right(char *s, const t_fmt *f, int *len)
{
	ssize_t	ret;
	bool	space;

	ret = 0;
	space = (s[0] != '-' && s[0] != '+' && f->flags & FLAG_SPACE
			&& (f->spec == 'i' || f->spec == 'd'));
	if (space)
		ret = ft_putnchar(' ', 1, len);
	if (ret == -1)
		return (-1);
	if (f->width > f->len + space)
		ret = ft_putnchar(' ', f->width - f->len - space, len);
	if (ret == -1)
		return (-1);
	ret = ft_putstr_len(s, len);
	if (ret == -1)
		return (-1);
	return (0);
}
