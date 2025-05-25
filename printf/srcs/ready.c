/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:28:57 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:38:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_handle.h"
#include "../includes/libft.h"

char	*ready_uint(unsigned long n, t_fmt *f, unsigned int base)
{
	char	*ready;

	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0 && !(f->width))
		ready = ft_strdup("");
	else if (f->spec == 'p' && n == 0)
		ready = (f->len = 5, ft_strdup("(nil)"));
	else
	{
		count_flen_u(n, f, base);
		ready = malloc(f->len + 1);
		if (!ready)
			return (NULL);
		ready[f->len] = '\0';
		ft_utoa_base(n, f, base, ready);
	}
	return (ready);
}

char	*ready_sint(long n, t_fmt *f)
{
	char	*ready;

	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0)
	{
		if (f->flags & FLAG_PLUS)
			ready = ((f->len)++, ft_strdup("+"));
		else
			ready = ft_strdup("");
	}
	else
	{
		count_flen(n, f);
		ready = malloc(f->len + 1);
		if (!ready)
			return (NULL);
		ready[f->len] = '\0';
		ft_sitoa(n, f, ready);
	}
	return (ready);
}
