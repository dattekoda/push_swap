/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:53:17 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/20 15:07:15 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FMT_H
# define FT_FMT_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

# define FLAG_ZERO	0b00000001
# define FLAG_MINUS	0b00000010
# define FLAG_PLUS	0b00000100
# define FLAG_SPACE	0b00001000
# define FLAG_HASH	0b00010000
# define FLAG_DOT	0b00100000

typedef struct s_fmt
{
	uint8_t		flags;
	int			width;
	int			prec;
	char		spec;
	int			len;
}	t_fmt;

void	f_init(t_fmt *fmt);
void	f_parse_flags(const char *fmt, unsigned int *i, t_fmt *f);
void	f_parse_width_prec(const char *fmt, unsigned int *i, t_fmt *f);
int		dispatch(t_fmt *fmt, va_list *ap);

#endif