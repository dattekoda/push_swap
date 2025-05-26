/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 12:06:00 by khanadat          #+#    #+#             */
/*   Updated: 2025-04-25 12:06:00 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = NULL;
	while (*s)
	{
		if (*s == (char) c)
			l = (char *)s;
		s++;
	}
	if ((char) c == '\0')
		l = (char *) s;
	return (l);
}
