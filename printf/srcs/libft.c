/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:28:13 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:38:59 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*h;

	if (!s)
		return (0);
	h = s;
	while (*s)
		s++;
	return ((size_t)(s - h));
}

char	*ft_strdup(const char *s)
{
	char		*dup;
	size_t		slen;

	slen = ft_strlen(s);
	dup = malloc(slen + 1);
	if (!dup)
		return (NULL);
	dup[slen] = '\0';
	while (slen--)
		dup[slen] = s[slen];
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;

	if (!dst || !src)
		return (0);
	slen = -1;
	while (src[++slen] && size-- > 1)
		dst[slen] = src[slen];
	dst[slen] = '\0';
	while (src[slen])
		slen++;
	return (slen);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = ft_strlen(src);
	i = -1;
	while (src[++i] && dst_len + i + 1 < size)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
