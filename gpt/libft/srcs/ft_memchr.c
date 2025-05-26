/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 12:40:13 by khanadat          #+#    #+#             */
/*   Updated: 2025-04-25 12:40:13 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *) s;
	while (n--)
	{
		if (*t == (unsigned char) c)
			return ((void *) t);
		t++;
	}
	return (NULL);
}
